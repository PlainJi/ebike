#include "update.h"
#include "gui_task.h"
#include "gps_task.h"
#include "PPS.h"

//void GuiSetSdcardStatus(bool status);
//void GuiSetBluetoothStatus(bool status);
//void GuiSetTimenow(const char *buf);
//void GuiSetLocateStatus(bool status);
//void GuiSetSatellitesCnt(int cnt);
//void GuiSetSpeed(int speed);
//void GuiSetDirection(float dir);
void GuiSetTripDist(float trip_dist);
//void GuiSetTripTime(int seconds);
void GuiSetTotal(float total);
void GuiSetTempretureHumidity(int temp, int humidity);
void GuiSetBattery(int battery, int left);

gps_time_t timenow;
char buf_timenow[8] = {0};
uint8_t valid = 0;
uint8_t sats_in_use = 0;
float speed = 0;
float direction = 0;
int trip_time = 0;

void update_sdcard(bool status) {
    GuiSetSdcardStatus(status);
}

void update_parking(bool status) {
    GuiSetParkingStatus(status);
}

void update_bluetooth(bool status) {
    GuiSetBluetoothStatus(status);
}

void update_record(bool status) {
    GuiSetRecordStatus(status);
}

void update_gps(void *arg) {
    gps_t *gps = (gps_t *)arg;
    if (gps->tim.hour != timenow.hour || gps->tim.minute != timenow.minute) {
        timenow.hour = gps->tim.hour;
        timenow.minute = gps->tim.minute;
        buf_timenow[0] = timenow.hour/10 + '0';
        buf_timenow[1] = timenow.hour%10 + '0';
        buf_timenow[2] = ' ';
        buf_timenow[3] = ':';
        buf_timenow[4] = ' ';
        buf_timenow[5] = timenow.minute/10 + '0';
        buf_timenow[6] = timenow.minute%10 + '0';
        buf_timenow[7] = '\0';
        GuiSetTimenow(buf_timenow);
    }
    if (gps->sats_in_use != sats_in_use) {
        sats_in_use = gps->sats_in_use;
        GuiSetSatellitesCnt(sats_in_use);
    }
    if (gps->cog != direction) {
        direction = gps->cog;
        GuiSetDirection(direction);
    }
    
    if (gps->valid != valid) {
        valid = gps->valid;
        GuiSetLocateStatus(valid);
    }
    if (gps->valid) {
        if (gps->speed != speed) {
            speed = gps->speed;
            GuiSetSpeed(speed);
        }
    } else {
        GuiSetSpeed(-1);
    }
}

void update_trip_time(int seconds) {
    GuiSetTripTime(seconds);
}

void update_temp_humidity(float temp, float humidity) {
    GuiSetTempretureHumidity((int)temp, (int)humidity);
}

void update_speed(int speed) {
    GuiSetSpeed(speed);
}

void update_direction(float dir) {
    GuiSetDirection(dir);
}

void update_trip_dist(float dist) {
    GuiSetTripDist(dist);
}

void update_total(float total) {
    GuiSetTotal(total);
}

void update_battery(int battery, int left) {
    GuiSetBattery(battery, left);
}
