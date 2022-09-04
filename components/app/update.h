#pragma once

#include "esp_system.h"

void update_sdcard(bool status);
void update_parking(bool status);
void update_bluetooth(bool status);
void update_record(bool status);
void update_gps(void *arg);
void update_trip_time(int seconds);
void update_temp_humidity(float temp, float humidity);
void update_battery(int battery, int left);
void update_total(float total);
void update_trip_dist(float dist);
void update_direction(float dir);
void update_speed(int speed);