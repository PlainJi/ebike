#pragma once

#include <sys/stat.h>
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "ff.h"
#include "gps_task.h"

#define MOUNT_POINT "/sdcard"

#define PIN_NUM_MISO 2
#define PIN_NUM_MOSI 15
#define PIN_NUM_CLK  14
#define PIN_NUM_CS   13
#define SPI_DMA_CHAN 2

void GpsLogInit();
void log_file_rename(gps_t *data);
void gps_write_log(char *buf, int len);