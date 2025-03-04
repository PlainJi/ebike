#include <esp32-hal.h>
#include "hw/display.h"
#include "hw/ahtxx.h"
#include "hw/gps.h"
#include "ui/ui.h"

void setup()
{
  Serial.begin(115200);
  delay(2000);

  display_init();
  gps_init();
  //ahtxx_init();
  scan();
  lvgl_init();
  ui_init();
  ESP_LOGI("setup", "finished.");
}

void loop()
{
  lv_timer_handler();
  delay(5);
  gps_update();
  //ahtxx_update();
}
