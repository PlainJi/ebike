#include "ahtxx.h"
#include <Adafruit_AHTX0.h>

#define I2C1_SCL 5
#define I2C1_SDA 6
Adafruit_AHTX0 aht;

void ahtxx_init() {
  int retry = 10;
  Wire1.begin(I2C1_SDA, I2C1_SCL);
  do {
    if (!aht.begin(&Wire1, 0, 0x39)) {
        ESP_LOGI("temp_init", "无法找到 AHT21 传感器，请检查连接！");
    }
    delay(100);
  } while(retry--);
  
  ESP_LOGI("temp_init", "AHT21 传感器初始化完成");
}

void ahtxx_update() {
  sensors_event_t humidity, temp;
  if (aht.getEvent(&humidity, &temp)) {
    ESP_LOGI("温度", "%f °C", temp.temperature);
    ESP_LOGI("湿度", "%f %", humidity.relative_humidity);
  }
}

void scan() {
    byte error, address;
    int nDevices = 0;
    
    Wire1.begin(I2C1_SDA, I2C1_SCL);

    for (address = 1; address < 127; address++) {
        Wire1.beginTransmission(address);
        error = Wire1.endTransmission();

        if (error == 0) {
            ESP_LOGI("scan", "找到设备地址: 0x%02X", address);
            nDevices++;
        } else if (error == 4) {
            ESP_LOGI("scan", "未知错误地址: 0x%02X", address);
        } else {
            ESP_LOGI("scan", "未知错误 error=%d", error);
        }
        delay(10);
  }

  if (nDevices == 0) {
    ESP_LOGI("scan", "未找到 I2C 设备");
  }
}