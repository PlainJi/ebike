#include "aht_bmp_imu.h"
#include "sdcard.h"

#include <Adafruit_AHTX0.h>
#include <Adafruit_BMP280.h>

#define I2C1_SCL 5
#define I2C1_SDA 6
#define AHT20_ADDR  0x38
#define BMP280_ADDR 0x77
#define MPU6050_ADDR 0x68

Adafruit_AHTX0 aht;
Adafruit_BMP280 bmp(&Wire1);
static bool aht_ok = false;
static bool bmp_ok = false;
WeatherData weather_data;
ImuData imu_data;
static char temp_str[256] = {0};

void aht_bmp_imu_init() {
  Wire1.begin(I2C1_SDA, I2C1_SCL);

  // 初始化 AHT20
  int retry = 3;
  do {
    if (!aht.begin(&Wire1, 0, AHT20_ADDR)) {
        ESP_LOGI("temp_init", "无法找到 AHT21 传感器，请检查连接！");
    }
    delay(100);
  } while(retry--);
  if (retry) aht_ok = true;
  ESP_LOGI("temp_init", "AHT21 传感器初始化完成");

  // 初始化BMP280
  retry = 3;
  do {
    if (!bmp.begin()) {
      ESP_LOGI("temp_init", "无法找到 BMP280 传感器, 请检查连接！");
    }
    delay(100);
  } while(retry--);
  if (retry) bmp_ok = true;
  ESP_LOGI("temp_init", "BMP280 传感器初始化完成");

  // 初始化 MPU6050
  Wire1.beginTransmission(MPU6050_ADDR);
  Wire1.write(0x6B); // 电源管理寄存器
  Wire1.write(0);    // 唤醒 MPU6050
  Wire1.endTransmission(true);
  // 配置加速度计和陀螺仪
  Wire1.beginTransmission(MPU6050_ADDR);
  Wire1.write(0x1B); // 陀螺仪配置寄存器
  Wire1.write(0x08); // 设置陀螺仪量程为 ±500°/s
  Wire1.endTransmission(true);
  Wire1.beginTransmission(MPU6050_ADDR);
  Wire1.write(0x1C); // 加速度计配置寄存器
  Wire1.write(0x10); // 设置加速度计量程为 ±8g
  Wire1.endTransmission(true);
  ESP_LOGI("i2c_init", "IMU 传感器初始化完成");

  memset(&weather_data, 0, sizeof(weather_data));
  memset(&imu_data, 0, sizeof(imu_data));
}

void aht_update() {
  sensors_event_t humidity, temp;
  if (aht_ok) {
    if (aht.getEvent(&humidity, &temp)) {
      weather_data.temp_aht20 = (int)temp.temperature;
      weather_data.humidity = (int)humidity.relative_humidity;
    }
  }
}

void aht_print() {
  snprintf(temp_str, sizeof(temp_str), "AHT %d °C %d %%", weather_data.temp_aht20, weather_data.humidity);
  ESP_LOGI("aht_print", "%s", temp_str);
  sd_write_str(KWRITE_I2C, temp_str);
}

void bmp_update() {
  if (bmp_ok) {
    weather_data.temp_bmp280 = (int)bmp.readTemperature();
    weather_data.pressure = (int)bmp.readPressure();
    weather_data.altitude = (int)bmp.readAltitude(1013.25);
  }
}

void bmp_print() {
  snprintf(temp_str, sizeof(temp_str), "BMP %d °C %d Pa %d m", 
    weather_data.temp_bmp280, weather_data.pressure, weather_data.altitude);
  ESP_LOGI("bmp_print", "%s", temp_str);
  sd_write_str(KWRITE_I2C, temp_str);
}

void imu_update() {
  // 请求读取加速度计和陀螺仪数据
  Wire1.beginTransmission(MPU6050_ADDR);
  Wire1.write(0x3B); // 从加速度计数据寄存器开始读取
  Wire1.endTransmission(false);
  Wire1.requestFrom(MPU6050_ADDR, 14, 1); // 读取 14 字节数据

  // 读取加速度计数据
  imu_data.ax = Wire1.read() << 8 | Wire1.read();
  imu_data.ay = Wire1.read() << 8 | Wire1.read();
  imu_data.az = Wire1.read() << 8 | Wire1.read();

  // 读取温度数据
  imu_data.temp_imu = (Wire1.read() << 8 | Wire1.read()) / 340 + 36.53;

  // 读取陀螺仪数据
  imu_data.gx = Wire1.read() << 8 | Wire1.read();
  imu_data.gy = Wire1.read() << 8 | Wire1.read();
  imu_data.gz = Wire1.read() << 8 | Wire1.read();
}

void imu_print() {
  snprintf(temp_str, sizeof(temp_str), "IMU Temp: %d | Accel: %d %d %d | Gyro: %d %d %d", 
    imu_data.temp_imu, \
    imu_data.ax, imu_data.ay, imu_data.az, \
    imu_data.gx, imu_data.gy, imu_data.gz);
  ESP_LOGI("imu_print", "%s", temp_str);
  sd_write_str(KWRITE_I2C, temp_str);
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