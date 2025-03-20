#ifndef _GPS_H_
#define _GPS_H_

typedef struct _GpsData {
  bool updated;
  double longtitude;
  double latitude;
  double altitude;      // m
  double dist_with_last_pos;
  int speed;            // kmph
  int satellites;
  double hdop;
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
}GpsData;

extern GpsData gps_data;

void gps_init();
void gps_update();
void gps_print();

#endif