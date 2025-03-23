#ifndef __AHT_BMP_IMU_H_
#define __AHT_BMP_IMU_H_

typedef struct _WeatherData {
    int temp_aht20;
    int humidity;
    int temp_bmp280;
    int pressure;
    int altitude;
}WeatherData;

typedef struct _ImuData {
    int temp_imu;
    int is_moving;
    double ax, ay, az;
    double gx, gy, gz;
}ImuData;

extern WeatherData weather_data;
extern ImuData imu_data;

void aht_bmp_imu_init();
void aht_update();
void aht_print();

void bmp_update();
void bmp_print();

void imu_update();
void imu_print();
// void scan();

#endif