#ifndef _SDCARD_H_
#define _SDCARD_H_

#include <esp32-hal.h>

typedef enum _WRITE_TYPE{
    kWRITE_GPS,
    KWRITE_I2C,
}WRITE_TYPE;

extern SemaphoreHandle_t xRecoderMutex;

void sd_init();
void sd_write_str(WRITE_TYPE write_type, const char *str);

#endif