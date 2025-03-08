#include <Wire.h>

// MPU6050 I2C 地址
const uint8_t MPU6050_ADDR = 0x68;

// 加速度计和陀螺仪数据变量
int16_t ax, ay, az; // 加速度计数据
int16_t gx, gy, gz; // 陀螺仪数据

void imu_init() {
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
}

void update_imu() {
  // 请求读取加速度计和陀螺仪数据
  Wire1.beginTransmission(MPU6050_ADDR);
  Wire1.write(0x3B); // 从加速度计数据寄存器开始读取
  Wire1.endTransmission(false);
  Wire1.requestFrom(MPU6050_ADDR, 14, true); // 读取 14 字节数据

  // 读取加速度计数据
  ax = Wire1.read() << 8 | Wire1.read();
  ay = Wire1.read() << 8 | Wire1.read();
  az = Wire1.read() << 8 | Wire1.read();

  // 读取温度数据（可选）
  int16_t temp = Wire1.read() << 8 | Wire1.read();

  // 读取陀螺仪数据
  gx = Wire1.read() << 8 | Wire1.read();
  gy = Wire1.read() << 8 | Wire1.read();
  gz = Wire1.read() << 8 | Wire1.read();
}

void imu_print_result() {
  ESP_LOGI("imu", "Accel: X=%d Y=%d Z=%d | Gyro: X=%d Y=%d Z=%d", ax, ay, az, gx, gy, gz);
}