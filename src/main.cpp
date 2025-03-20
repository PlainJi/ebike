#include <esp32-hal.h>
#include "hw/display.h"
#include "hw/sdcard.h"
#include "hw/aht_bmp_imu.h"
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

  ESP_LOGI("task", "i2c");
  while (1) {
    aht_update();
    bmp_update();
    imu_update();
    
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      sprintf(temp_str, "%d", weather_data.temp_aht20);
      lv_label_set_text(ui_Label_Temp, temp_str);
      sprintf(temp_str, "%d", weather_data.humidity);
      lv_label_set_text(ui_Label_Humidity, temp_str);
      xSemaphoreGive(xMutex);
    }

    if (xSemaphoreTake(xRecoderMutex, portMAX_DELAY) == pdTRUE) {
      ESP_LOGI("gps", "===== IMU =====");
      // aht_print();
      // bmp_print();
      imu_print();
      xSemaphoreGive(xRecoderMutex);
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void task_gps(void *pvParameters) {
  char temp_str[16] = {0};
  static int last_time = 0;
  static int last_speed = 0;
  static unsigned long last_uptime = 0;
  static double trip_distance = 0;

  ESP_LOGI("task", "gps");
  last_uptime =  millis() / 1000;

  while(1) {
    // update UpTime
    long uptime = millis() / 1000;
    if (uptime != last_uptime) {
      last_uptime = uptime;

      sprintf(temp_str, "%02d:%02d:%02d", uptime/3600, (uptime%3600)/60, uptime%60);
      lv_label_set_text(ui_Label_Arrival_Time_Number1, temp_str);
    }

    gps_update();
    if (!gps_data.updated) {
      vTaskDelay(5/portTICK_PERIOD_MS);
      continue;
    }

    gps_data.updated = false;
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      // update speed
      if (gps_data.speed != last_speed) {
        last_speed = gps_data.speed;

        lv_slider_set_value(ui_Slider_Speed, gps_data.speed, LV_ANIM_ON);
        sprintf(temp_str, "%d", gps_data.speed);
        lv_label_set_text(ui_Speed_Number_1, temp_str);
        lv_label_set_text(ui_Speed_Number_2, temp_str);
        lv_slider_set_value(ui_Slider_Battery, gps_data.speed, LV_ANIM_ON);
      }

      // update gps time
      int cur_time = gps_data.hour * 100 + gps_data.minute;
      if (last_time != cur_time) {
        last_time = cur_time;

        sprintf(temp_str, "%d:%02d", (gps_data.hour+8)%24, gps_data.minute);
        lv_label_set_text(ui_Label_Time_Home, temp_str);
      }

      // update trip distance & avg speed
      if ((int)gps_data.dist_with_last_pos) {
        trip_distance += gps_data.dist_with_last_pos;

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
    if (xSemaphoreTake(xRecoderMutex, portMAX_DELAY) == pdTRUE) {
      gps_print();
      xSemaphoreGive(xRecoderMutex);
    }
  }
}

void setup()
{
  delay(3000);

  Serial.begin(115200);
  while(!Serial) {
    delay(10);
  }

  sd_init();
  display_init();
  aht_bmp_imu_init();
  gps_init();
  lvgl_init();
  ui_init();
  ESP_LOGI("setup", "init finished.");

  xMutex = xSemaphoreCreateMutex();
  if (xMutex == NULL) {
    ESP_LOGI("setup", "Failed to create mutex!");
    while (1);
  }

  xTaskCreatePinnedToCore(task_gps, "task_gps", 4096, NULL, 1, &task_gps_, 1);
  xTaskCreatePinnedToCore(task_i2c_device, "task_i2c_device", 4096, NULL, 1, &task_i2c_device_, 0);
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
