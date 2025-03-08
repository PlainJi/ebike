#include "aht_bmp.h"
#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

#define I2C1_SCL 5
#define I2C1_SDA 6
#define AHT20_ADDR  0x38
#define BMP280_ADDR 0x77
Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp(&Wire1);
static bool aht_ok = false;
static bool bmp_ok = false;

void aht_bmp_init() {
  Wire1.begin(I2C1_SDA, I2C1_SCL);

  int retry = 3;
  do {
    if (!aht.begin(&Wire1, 0, AHT20_ADDR)) {
        ESP_LOGI("temp_init", "无法找到 AHT21 传感器，请检查连接！");
    }
    delay(100);
  } while(retry--);
  if (retry) aht_ok = true;
  ESP_LOGI("temp_init", "AHT21 传感器初始化完成");

  retry = 3;
  do {
    if (!bmp.begin()) {
      ESP_LOGI("temp_init", "无法找到 BMP280 传感器, 请检查连接！");
    }
    delay(100);
  } while(retry--);
  if (retry) bmp_ok = true;
  ESP_LOGI("temp_init", "BMP280 传感器初始化完成");
}

void update_aht() {
  sensors_event_t humidity, temp;
  if (aht_ok) {
    if (aht.getEvent(&humidity, &temp)) {
      ESP_LOGI("AHT温度 ", "%d °C", (int)temp.temperature);
      ESP_LOGI("AHT湿度 ", "%d %%", (int)humidity.relative_humidity);
    }
  }
}

void update_bmp() {
  if (bmp_ok) {
    ESP_LOGI("BMP温度 ", "%d °C", (int)bmp.readTemperature());
    ESP_LOGI("BMP压力 ", "%d Pa", (int)bmp.readPressure());
    ESP_LOGI("BMP高度 ", "%d m",  (int)bmp.readAltitude(1013.25));
  }
}

// void scan() {
//     byte error, address;
//     int nDevices = 0;
    
//     Wire1.begin(I2C1_SDA, I2C1_SCL);

//     for (address = 1; address < 127; address++) {
//         Wire1.beginTransmission(address);
//         error = Wire1.endTransmission();

//         if (error == 0) {
//             ESP_LOGI("scan", "找到设备地址: 0x%02X", address);
//             nDevices++;
//         } else if (error == 4) {
//             ESP_LOGI("scan", "未知错误地址: 0x%02X", address);
//         } else {
//             ESP_LOGI("scan", "未知错误 error=%d", error);
//         }
//         delay(10);
//   }

//   if (nDevices == 0) {
//     ESP_LOGI("scan", "未找到 I2C 设备");
//   }
// }