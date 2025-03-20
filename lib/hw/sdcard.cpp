#include "sdcard.h"

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

// 定义 SD 卡 CS 引脚
#define VSPI_CS   10
#define VSPI_MOSI 11
#define VSPI_SCK  12
#define VSPI_MISO 13

File file_gps;
File file_i2c;
SPIClass customSPI(HSPI);
SemaphoreHandle_t xRecoderMutex;
static bool init_flag_gps = false;
static bool init_flag_i2c = false;

void sd_init() {
  xRecoderMutex = xSemaphoreCreateMutex();
  if (xRecoderMutex == NULL) {
    ESP_LOGI("setup", "Failed to create xRecoderMutex!");
    while (1);
  }

  ESP_LOGI("sd_init", "初始化 SD 卡...");
  customSPI.begin(VSPI_SCK, VSPI_MISO, VSPI_MOSI, VSPI_CS);
  if (!SD.begin(VSPI_CS, customSPI)) {
  //if (!SD.begin(VSPI_CS)) {
    ESP_LOGI("sd_init", "初始化失败，请检查连接！");
    return;
  }
  ESP_LOGI("sd_init", "初始化成功");

  file_gps = SD.open("/gps.log", FILE_WRITE);
  if (file_gps) {
    file_gps.seek(file_gps.size());
    file_gps.println("start logging gps");
    file_gps.flush();
    init_flag_gps = true;
  } else {
    ESP_LOGE("sd_init", "GPS日志打开失败");
  }

  file_i2c = SD.open("/i2c.log", FILE_WRITE);
  if (file_i2c) {
    file_i2c.seek(file_i2c.size());
    file_i2c.println("start logging i2c");
    file_i2c.flush();
    init_flag_i2c = true;
  } else {
    ESP_LOGE("sd_init", "I2C日志打开失败");
  }
}

void sd_write_str(WRITE_TYPE write_type, const char *str) {
  if ((write_type == kWRITE_GPS) && init_flag_gps) {
    file_gps.println(str);
    
    static long lastMillis_gps = 0;
    long currentMillis_gps = millis();
    if (currentMillis_gps - lastMillis_gps > 1000) {
      lastMillis_gps = currentMillis_gps;
      file_gps.flush();
    }
  } else if ((write_type == KWRITE_I2C) && init_flag_i2c) {
    file_i2c.println(str);

    static long lastMillis_i2c = 0;
    long currentMillis_i2c = millis();
    if (currentMillis_i2c - lastMillis_i2c > 1000) {
      lastMillis_i2c = currentMillis_i2c;
      file_i2c.flush();
    }
  }
}
