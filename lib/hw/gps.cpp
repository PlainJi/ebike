#include "gps.h"
#include "sdcard.h"
#include <TinyGPS++.h>
#include <HardwareSerial.h>

#define UART1_RX 18             // 接GPS模块的TX
#define UART1_TX 17             // 接GPS模块的RX

TinyGPSPlus gps;                // 创建 GPS 对象
HardwareSerial gpsSerial(1);    // 创建硬件串口对象
GpsData gps_data;
static char temp_str[256] = {0};
// const char *rmc = "$GNRMC,123300.000,A,3957.44996,N,11628.97404,E,3.63,47.96,180325,,,A*48";
// const char *gga = "$GNGGA,123136.000,3957.42595,N,11628.91408,E,1,15,1.0,36.5,M,0.0,M,,*4C";
// const char *txt = "$GPTXT,01,01,01,ANTENNA OK*35";

void gps_init() {
  memset(&gps_data, 0, sizeof(gps_data));
  gpsSerial.setRxBufferSize(512);
  gpsSerial.begin(9600, SERIAL_8N1, UART1_RX, UART1_TX);
  ESP_LOGI("gps_init", "GPS 初始化完成，等待数据...");
}

void gps_update() {
  static bool get_initial_pos = false;
  // 检查是否有 GPS 数据
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c);
  }

  if (gps.message_finished) {
    ESP_LOGI("gps_update", "%s", gps.message);
    sd_write_str(kWRITE_GPS, gps.message);
    gps.message_finished = false;
    memset(gps.message, 0, sizeof(gps.message));
  }

  // 打印解析后的 GPS 数据
  if (gps.location.isUpdated()) {
    gps_data.updated = true;

    if (!get_initial_pos) {
      if (!((int)gps_data.latitude) && !((int)gps_data.longtitude) && \
           (int)gps.location.lat() && (int)gps.location.lng()) {
        gps_data.latitude = gps.location.lat();
        gps_data.longtitude = gps.location.lng();
        get_initial_pos = true;
      }
    } else {
      gps_data.dist_with_last_pos = gps.distanceBetween(gps_data.latitude, gps_data.longtitude, gps.location.lat(), gps.location.lng());
      if ((int)gps_data.dist_with_last_pos) {
        sprintf(temp_str, "dis %.1f", gps_data.dist_with_last_pos);
        sd_write_str(kWRITE_GPS, temp_str);
      }
    }

    gps_data.latitude = gps.location.lat();
    gps_data.longtitude = gps.location.lng();
    gps_data.altitude = gps.altitude.meters();
    gps_data.speed = (int)gps.speed.kmph();
    gps_data.satellites = gps.satellites.value();
    gps_data.hdop = gps.hdop.hdop();

    gps_data.year = gps.date.year();
    gps_data.month = gps.date.month();
    gps_data.day = gps.date.day();
    gps_data.hour = gps.time.hour();
    gps_data.minute = gps.time.minute();
    gps_data.second = gps.time.second();
  }
}

void gps_print() {
  ESP_LOGI("gps", "===== GPS 数据 =====");
  
  snprintf(temp_str, sizeof(temp_str), "%d-%d-%d %d:%d:%d", 
            gps_data.year, gps_data.month, gps_data.day,
            gps_data.hour, gps_data.minute, gps_data.second);
  ESP_LOGI("gps", "%s", temp_str);
  sd_write_str(kWRITE_GPS, temp_str);

  snprintf(temp_str, sizeof(temp_str), "%f %f %f | %d %d %.1f", 
            gps_data.latitude, gps_data.longtitude, gps_data.altitude, 
            gps_data.speed, gps_data.satellites, gps_data.hdop);
  ESP_LOGI("gps", "%s", temp_str);
  sd_write_str(kWRITE_GPS, temp_str);
}