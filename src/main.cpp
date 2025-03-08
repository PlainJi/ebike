#include <esp32-hal.h>
#include "hw/display.h"
#include "hw/sdcard.h"
#include "hw/aht_bmp.h"
#include "hw/imu.h"
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
  while (1) {
    update_aht();
    update_bmp();
    update_imu();
    imu_print_result();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    ESP_LOGI("task", "i2c device");

    temp += 5;
    if (temp > max_temp) temp = 0;
    sprintf(temp_str, "%d", temp);
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      _ui_label_set_property(ui_Label_Temp, 0, temp_str);
      lv_slider_set_value(ui_Slider_Speed, temp, LV_ANIM_ON);
      lv_slider_set_value(ui_Slider_Battery, temp, LV_ANIM_ON);
      xSemaphoreGive(xMutex);
    }
  }
}

void task_gps(void *pvParameters) {
  while(1) {
    update_gps();
    //update_gps_ui();
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    ESP_LOGI("task", "gps");

    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {

      xSemaphoreGive(xMutex);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  while(!Serial) {
    delay(10);
  }

  sd_init();
  display_init();
  aht_bmp_init();
  imu_init();
  gps_init();
  lvgl_init();
  ui_init();
  ESP_LOGI("setup", "init finished.");

  xMutex = xSemaphoreCreateMutex();
  if (xMutex == NULL) {
    ESP_LOGI("setup", "Failed to create mutex!");
    while (1);
  }

  xTaskCreatePinnedToCore(task_i2c_device, "task_i2c_device", 4096, NULL, 1, &task_i2c_device_, 1);
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
