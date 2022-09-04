#ifndef __GUI_TASK_H
#define __GUI_TASK_H

#include "esp_system.h"

void GuiSetSdcardStatus(bool status);
void GuiSetParkingStatus(bool status);
void GuiSetBluetoothStatus(bool status);
void GuiSetTimenow(const char *buf);
void GuiSetRecordStatus(bool display);
void GuiSetLocateStatus(bool status);
void GuiSetSatellitesCnt(int cnt);
void GuiSetSpeed(int speed);
void GuiSetDirection(float dir);
void GuiSetTripDist(float trip_dist);
void GuiSetTripTime(int seconds);
void GuiSetTotal(float total);
void GuiSetTempretureHumidity(int temp, int humidity);
void GuiSetBattery(int battery, int left);

void GuiInit();

#endif