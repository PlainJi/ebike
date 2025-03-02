#include "gps.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>

#define UART1_RX 18             // 接GPS模块的TX
#define UART1_TX 17             // 接GPS模块的RX

TinyGPSPlus gps;                // 创建 GPS 对象
HardwareSerial gpsSerial(1);    // 创建硬件串口对象

void gps_init() {
  gpsSerial.begin(9600, SERIAL_8N1, UART1_RX, UART1_TX);
  ESP_LOGI("gps_init", "GPS 初始化完成，等待数据...");
}

void gps_update() {
  // 检查是否有 GPS 数据
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c);
    ESP_LOGI("gps_update", "recv %c", c);
  }

  // 打印解析后的 GPS 数据
  if (gps.location.isUpdated()) {
    ESP_LOGI("gps_update", "===== GPS 数据 =====");
    ESP_LOGI("gps_update", "纬度 %f", gps.location.lat());
    // Serial.print("经度: ");
    // Serial.println(gps.location.lng(), 6);
    // Serial.print("海拔: ");
    // Serial.println(gps.altitude.meters());
    // Serial.print("速度: ");
    // Serial.println(gps.speed.kmph());
    // Serial.print("卫星数: ");
    // Serial.println(gps.satellites.value());
    // Serial.print("日期: ");
    // Serial.print(gps.date.year());
    // Serial.print("-");
    // Serial.print(gps.date.month());
    // Serial.print("-");
    // Serial.println(gps.date.day());
    // Serial.print("时间: ");
    // Serial.print(gps.time.hour());
    // Serial.print(":");
    // Serial.print(gps.time.minute());
    // Serial.print(":");
    // Serial.println(gps.time.second());
    ESP_LOGI("gps_update", "====================");
  }
}