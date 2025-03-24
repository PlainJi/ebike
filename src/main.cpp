#include <Arduino.h>
#include <esp32-hal.h>
#include "hw/display.h"
#include "hw/sdcard.h"
#include "hw/aht_bmp_imu.h"
#include "ImuMotionDetector.h"
#include "hw/gps.h"
#include "ui/ui.h"

TaskHandle_t task_i2c_device_;
TaskHandle_t task_gps_;
SemaphoreHandle_t xMutex;

// NOTE: 
//  aht & bmp & imu share the same i2c bus.
//  Take care of protecting the critical resource.
void task_i2c_device(void *pvParameters) {
  int temp = 0;
  char temp_str[3] = {0};
  int max_temp = 50;
  uint32_t cnt = 0;

  ESP_LOGI("task", "i2c");
  while (1) {
    cnt++;
    if (!(cnt%2)) {
      aht_update();
      bmp_update();
    }
    imu_update();
    
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      if (imu_data.is_moving) {
        lv_obj_add_flag(ui_Image_Parking, LV_OBJ_FLAG_HIDDEN);
      } else {
        lv_obj_clear_flag(ui_Image_Parking, LV_OBJ_FLAG_HIDDEN);
      }

      sprintf(temp_str, "%d", weather_data.temp_aht20);
      lv_label_set_text(ui_Label_Temp, temp_str);
      sprintf(temp_str, "%d", weather_data.humidity);
      lv_label_set_text(ui_Label_Humidity, temp_str);
      xSemaphoreGive(xMutex);
    }

    if (xSemaphoreTake(xRecoderMutex, portMAX_DELAY) == pdTRUE) {
      // aht_print();
      // bmp_print();
      // imu_print();
      xSemaphoreGive(xRecoderMutex);
    }

    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void task_gps(void *pvParameters) {
  char temp_str[16] = {0};
  static int last_time = 0;
  static int last_speed = 0;
  static char last_fix_status = 'x';
  static int last_satellites = -1;
  static unsigned long last_uptime = 0;
  static double trip_distance = 0;

  ESP_LOGI("task", "gps");
  vTaskDelay(1000/portTICK_PERIOD_MS);
  ui_animation(ui_Slider_Speed, 0, 400, 1500, 1500, 200, 0, 0, _lv_slider_set_value);
  ui_animation(ui_Slider_Battery, 0, 100, 1500, 1500, 200, 0, 0, _lv_slider_set_value);
  last_uptime =  millis() / 1000;

  while(1) {
    gps_update();

    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      // update UpTime
      long uptime = millis() / 1000;
      if (uptime != last_uptime) {
        last_uptime = uptime;

        sprintf(temp_str, "%02d:%02d:%02d", uptime/3600, (uptime%3600)/60, uptime%60);
        lv_label_set_text(ui_Label_Arrival_Time_Number1, temp_str);
      }

      // update fix status
      if (gnss_data.fixStatus != last_fix_status) {
        last_fix_status = gnss_data.fixStatus;

        if (gnss_data.fixStatus == 'V') {
          lv_obj_clear_flag(ui_Image_Locating, LV_OBJ_FLAG_HIDDEN);
          lv_obj_add_flag(ui_Image_Located, LV_OBJ_FLAG_HIDDEN);
        } else if (gnss_data.fixStatus == 'A') {
          lv_obj_add_flag(ui_Image_Locating, LV_OBJ_FLAG_HIDDEN);
          lv_obj_clear_flag(ui_Image_Located, LV_OBJ_FLAG_HIDDEN);
        }
      }

      // update satalites
      if (gnss_data.numSats != last_satellites) {
        last_satellites = gnss_data.numSats;

        sprintf(temp_str, "%d", gnss_data.numSats);
        lv_label_set_text(ui_Label_Satellites, temp_str);
      }

      // update speed
      if ((int)gnss_data.speed != last_speed) {
        last_speed = (int)gnss_data.speed;
        ui_animation_for_slider(ui_Slider_Speed, (int)gnss_data.speed*10, 1000);
        lv_slider_set_value(ui_Slider_Battery, (int)gnss_data.speed, LV_ANIM_ON);
      }

      // update gps time
      int cur_time = gnss_data.hour * 100 + gnss_data.minute;
      if (last_time != cur_time) {
        last_time = cur_time;

        sprintf(temp_str, "%d:%02d", (gnss_data.hour+8)%24, gnss_data.minute);
        lv_label_set_text(ui_Label_Time_Home, temp_str);
      }

      // update trip distance & avg speed
      if ((int)(gnss_data.dist_with_last_pos*100) && imu_data.is_moving) {
        trip_distance += gnss_data.dist_with_last_pos;
        gnss_data.dist_with_last_pos = 0;

        if (trip_distance < 1000.0f) {
          sprintf(temp_str, "%d", (int)trip_distance);
          lv_label_set_text(ui_Label_Trip_Number, temp_str);
          lv_label_set_text(ui_Label_km2, "m");
        } else if (trip_distance < 10000.0f) {
          sprintf(temp_str, "%.2f", trip_distance/1000.0f);
          lv_label_set_text(ui_Label_Trip_Number, temp_str);
          lv_label_set_text(ui_Label_km2, "km");
        } else {
          sprintf(temp_str, "%.1f", trip_distance/1000.0f);
          lv_label_set_text(ui_Label_Trip_Number, temp_str);
          lv_label_set_text(ui_Label_km2, "km");
        }

        // update avg speed
        double avg_speed = 3.6f * trip_distance / uptime;
        sprintf(temp_str, "%.1f", avg_speed);
        lv_label_set_text(ui_Label_AVG_Speed_Number, temp_str);
      }

      xSemaphoreGive(xMutex);
    }

    // save log to SD Card
    // if (xSemaphoreTake(xRecoderMutex, portMAX_DELAY) == pdTRUE) {
    //   gps_print();
    //   xSemaphoreGive(xRecoderMutex);
    // }
  }
}

void setup()
{
  delay(3000);

  Serial.begin(115200);
  while(!Serial) {
    delay(10);
  }

  display_init();
  lvgl_init();
  ui_init();

  if (sd_init()) {
    lv_obj_clear_flag(ui_Image_Sdcard_w, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_add_flag(ui_Image_Sdcard_w, LV_OBJ_FLAG_HIDDEN);
  }
  gps_init();
  aht_bmp_imu_init();
  ESP_LOGI("setup", "init finished.");

  xMutex = xSemaphoreCreateMutex();
  if (xMutex == NULL) {
    ESP_LOGI("setup", "Failed to create mutex!");
    while (1);
  }

  xTaskCreatePinnedToCore(task_i2c_device, "task_i2c_device", 4096, NULL, 1, &task_i2c_device_, 0);
  xTaskCreatePinnedToCore(task_gps, "task_gps", 4096, NULL, 1, &task_gps_, 1);
  ESP_LOGI("setup", "creat task finished.");
}

void loop()
{
  if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
    lv_timer_handler();
    xSemaphoreGive(xMutex);
  }
  vTaskDelay(5/portTICK_PERIOD_MS);
}
