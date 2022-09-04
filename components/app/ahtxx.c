#include "include.h"
#include "ahtxx.h"

static const char *TAG = "AHTxx";

temp_humi_t temp_humi;

static uint8_t ahtxx_get_status()
{
    esp_err_t ret;
    uint8_t read_buf[1] = {0};
    uint8_t write_buf[1] = {0x71};
    ret = i2c_master_write_to_device(I2C_MASTER_NUM, AHTXX_SENSOR_ADDR, write_buf, 1, I2C_MASTER_TIMEOUT_MS / portTICK_RATE_MS);
    ret = i2c_master_read_from_device(I2C_MASTER_NUM, AHTXX_SENSOR_ADDR, read_buf, 1, I2C_MASTER_TIMEOUT_MS / portTICK_RATE_MS);
    if (ret == ESP_OK) {
        if ((read_buf[0]&0x18)!=0x18) {
            ESP_LOGI(TAG, "AHT Sensor Error, need init!!!");
        }
    }
    return read_buf[0];
}

static esp_err_t ahtxx_start_measure()
{
    esp_err_t ret;
    uint8_t write_buf[3] = {0xac, 0x33, 0x00};
    ret = i2c_master_write_to_device(I2C_MASTER_NUM, AHTXX_SENSOR_ADDR, write_buf, 3, I2C_MASTER_TIMEOUT_MS / portTICK_RATE_MS);
    return ret;
}

static esp_err_t ahtxx_get_result(float *temperature, float *humidity)
{
    while ((ahtxx_get_status() & 0x80) == 0x80)
    {
        printf("AHTXX Busy\n");
        vTaskDelay(10);
    }
    
    uint32_t RetuData;
    esp_err_t ret;
    uint8_t write_buf[1] = {0x71};
    uint8_t read_buf[10] = {0};
    ret = i2c_master_write_to_device(I2C_MASTER_NUM, AHTXX_SENSOR_ADDR, write_buf, 1, I2C_MASTER_TIMEOUT_MS / portTICK_RATE_MS);
    ret = i2c_master_read_from_device(I2C_MASTER_NUM, AHTXX_SENSOR_ADDR, read_buf, 7, I2C_MASTER_TIMEOUT_MS / portTICK_RATE_MS);
    //if (ret == ESP_OK) {
    //    printf("%02X %02X %02X %02X %02X %02X %02X\n", read_buf[0], read_buf[1], read_buf[2], read_buf[3], read_buf[4], read_buf[5], read_buf[6]);
    //}
    RetuData = 0;
    RetuData = (RetuData|read_buf[1]) << 8;
    RetuData = (RetuData|read_buf[2]) << 8;
    RetuData = (RetuData|read_buf[3]);
    RetuData >>= 4;
    *humidity = (float)RetuData*100*10/1024/1024/10;

    RetuData = 0;
    RetuData = (RetuData|read_buf[3]) << 8;
    RetuData = (RetuData|read_buf[4]) << 8;
    RetuData = (RetuData|read_buf[5]);
    RetuData &=  0xfffff;
    *temperature = ((float)RetuData*200*10/1024/1024-500) / 10;
    //printf("%f %f\n", *humidity, *temperature);

    return ret;
}

/**
 * @brief i2c master initialization
 */
static esp_err_t i2c_master_init(void)
{
    int i2c_master_port = I2C_MASTER_NUM;

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };

    i2c_param_config(i2c_master_port, &conf);

    return i2c_driver_install(i2c_master_port, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

void aht_task() {

    while (1) {
        ahtxx_start_measure();
        vTaskDelay(100);
        ahtxx_get_result(&temp_humi.temperature, &temp_humi.humidity);
        ESP_ERROR_CHECK(esp_event_post_to(event_handler, TASK_EVENTS, EVENT_UPDATE_TH, &temp_humi, sizeof(temp_humi), 100 / portTICK_PERIOD_MS));
        //update_temp_humidity(temperature, humidity);
    }
}

void AhtInit(void)
{
    ESP_ERROR_CHECK(i2c_master_init());
    ESP_LOGI(TAG, "I2C initialized successfully");

    ahtxx_get_status();
    xTaskCreate(aht_task, "aht_task", 4096, NULL, 20, NULL);
    //ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    //ESP_LOGI(TAG, "I2C unitialized successfully");
}
