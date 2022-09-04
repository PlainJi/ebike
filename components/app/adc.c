#include "include.h"
#include "adc.h"

//ADC Channels
#define ADC1_EXAMPLE_CHAN0          ADC1_CHANNEL_0
//ADC Attenuation
#define ADC_EXAMPLE_ATTEN           ADC_ATTEN_DB_11
#define R1                          220000
#define R2                            5100
#define BATTERY_FULL                53.3f
#define BATTERY_EMPTY               43.4f

static const char *TAG = "ADC";
bool cali_enable = false;
static int voltage_result[10];
static esp_adc_cal_characteristics_t adc1_chars;
battery_info_t battery_info;

static bool adc_calibration_init(void)
{
    esp_err_t ret;

    ret = esp_adc_cal_check_efuse(ESP_ADC_CAL_VAL_EFUSE_VREF);
    if (ret == ESP_ERR_NOT_SUPPORTED) {
        ESP_LOGW(TAG, "Calibration scheme not supported, skip software calibration");
    } else if (ret == ESP_ERR_INVALID_VERSION) {
        ESP_LOGW(TAG, "eFuse not burnt, skip software calibration");
    } else if (ret == ESP_OK) {
        cali_enable = true;
        esp_adc_cal_characterize(ADC_UNIT_1, ADC_EXAMPLE_ATTEN, ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);
    } else {
        ESP_LOGE(TAG, "Invalid arg");
    }

    if (cali_enable) {
        ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
        ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_EXAMPLE_CHAN0, ADC_EXAMPLE_ATTEN));
    }

    return cali_enable;
}

int cal_avg_voltage() {
    int temp = 0;
    int count = sizeof(voltage_result)/sizeof(int);

    for (size_t i = 0; i < count; i++) {
        temp += voltage_result[i];
    }
    temp /= count;

    return (int)((float)temp * (R1+R2) / R2 / 1000);
}

uint32_t get_left_mileage(uint32_t percentage) {
    return 0;
}

void adc_task() {
    int cnt = 0;
    int cur_valtage = 0;
    int calib_voltage = 0;
    char log_buf[16] = {0};
    while (1) {
        cur_valtage = adc1_get_raw(ADC1_EXAMPLE_CHAN0);
        if (cali_enable) {
            calib_voltage = esp_adc_cal_raw_to_voltage(cur_valtage, &adc1_chars);
            //ESP_LOGI("ADC1", "cali data: %d mV", calib_voltage);
            voltage_result[cnt++] = calib_voltage;
            if (cnt == sizeof(voltage_result)/sizeof(int)) {
                cnt = 0;
                float battery_voltage = cal_avg_voltage();
                uint32_t battery_percentage = 0;
                if (battery_percentage < BATTERY_EMPTY) {
                    battery_percentage = 0;
                } else if (battery_percentage > BATTERY_FULL) {
                    battery_percentage = 100;
                } else {
                    battery_percentage = (uint32_t)(100.0 * (battery_voltage-BATTERY_EMPTY) / (BATTERY_FULL - BATTERY_EMPTY));
                }

                battery_info.voltage = battery_voltage;
                battery_info.percentage = battery_percentage;
                battery_info.left_mileage_km = get_left_mileage(battery_percentage);
                ESP_ERROR_CHECK(esp_event_post_to(event_handler, TASK_EVENTS, EVENT_UPDATE_BATTERY, &battery_info, sizeof(battery_info), 100 / portTICK_PERIOD_MS));

                sprintf(log_buf, "%.1f %u %u\n", battery_info.voltage, battery_info.percentage, battery_info.left_mileage_km);
                ESP_ERROR_CHECK(esp_event_post_to(event_handler, TASK_EVENTS, EVENT_UPDATE_LOG, log_buf, sizeof(log_buf), 100 / portTICK_PERIOD_MS));
            }
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void AdcInit(void)
{
    adc_calibration_init();
    xTaskCreate(adc_task, "adc_task", 4096, NULL, 20, NULL);
}

// 53.3 ~ 43.3
// 220K 5K
// 5 / 200  1/40
// 1184mV 0962mV

// 53.3 ~ 43.3
// 220K 6.8K
// 5 / 200  1/40
// 1598mV 1298mV
