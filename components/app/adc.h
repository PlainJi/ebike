#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"

typedef struct _battery_info {
    float voltage;
    uint32_t percentage;
    uint32_t left_mileage_km;
} battery_info_t;

void AdcInit(void);