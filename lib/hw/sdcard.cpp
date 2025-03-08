#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

// 定义 SD 卡 CS 引脚
const int chipSelect = 10;
File file;

void sd_init() {
  ESP_LOGI("sd_init", "初始化 SD 卡...");
  if (!SD.begin(chipSelect)) {
    ESP_LOGI("sd_init", "初始化失败，请检查连接！");
    return;
  }
  ESP_LOGI("sd_init", "初始化成功");

  file = SD.open("/gps.log", FILE_WRITE);
  if (file) {
    file.println("start logging gps");
  } else {
    ESP_LOGE("sd_init", "GPS日志打开失败");
  }
}

void sd_write_str(const char *str) {
  file.println(str);

  static long lastMillis = 0;
  long currentMillis = millis();

  if (currentMillis - lastMillis > 1000) {
    lastMillis = currentMillis;
    file.flush();
  }
}