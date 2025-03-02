#include <esp32-hal.h>
#include "hw/display.h"
#include "ui/ui.h"

void setup()
{
  Serial.begin(115200);
  display_init();
  lvgl_init();
  ui_init();
  ESP_LOGI("main", "Setup done");
}

void loop()
{
  lv_timer_handler();
  delay(5);
}
