#include "event.h"
#include "include.h"

#include "update.h"
#include "gps_task.h"
#include "adc.h"
#include "ahtxx.h"
#include "gps_log.h"

static const char* TAG = "event";

ESP_EVENT_DEFINE_BASE(TASK_EVENTS);
esp_event_loop_handle_t event_handler;


// ESP_ERROR_CHECK(esp_event_post_to(event_handler, TASK_EVENTS, TASK_ITERATION_EVENT_1, &test1, sizeof(test1), portMAX_DELAY));
static void event_process(void *handler_args, esp_event_base_t base, int32_t id, void *event_data) {
    battery_info_t *battery_info = NULL;
    temp_humi_t *temp_humi = NULL;

    switch (id)
    {
        case EVENT_UPDATE_GPS:
            log_file_rename((gps_t*)event_data);
            update_gps(event_data);
            //ESP_LOGI(TAG, "GPS %u:%u:%u\n", (gps_t*)event_data->tim.hour, (gps_t*)event_data->tim.minute, (gps_t*)event_data->tim.second);
            break;
        case EVENT_UPDATE_TH:
            temp_humi = (temp_humi_t*)event_data;
            update_temp_humidity(temp_humi->temperature, temp_humi->humidity);
            //ESP_LOGI(TAG, "TH %f %f\n", temp_humi->temperature, temp_humi->humidity);
            break;
        case EVENT_UPDATE_BATTERY:
            battery_info = (battery_info_t*)event_data;
            update_battery(battery_info->percentage, battery_info->left_mileage_km);
            update_trip_dist(battery_info->voltage);
            //ESP_LOGI(TAG, "BAT %f %u %u\n", battery_info->voltage, battery_info->percentage, battery_info->left_mileage_km);
            break;
        case EVENT_UPDATE_LOG:
            gps_write_log((char*)event_data, strlen((char*)event_data));
            //ESP_LOGI(TAG, "%s", (char*)event_data);
            break;
        default:
            ESP_LOGI(TAG, "unknown event id: %d", id);
            break;
    }
}

void EventInit() {
    esp_event_loop_args_t loop_with_task_args = {
        .queue_size = 10,
        .task_name = "event_task",
        .task_priority = uxTaskPriorityGet(NULL),
        .task_stack_size = 4096,
        .task_core_id = tskNO_AFFINITY
    };

    ESP_ERROR_CHECK(esp_event_loop_create(&loop_with_task_args, &event_handler));
    ESP_ERROR_CHECK(esp_event_handler_instance_register_with(event_handler, TASK_EVENTS, ESP_EVENT_ANY_ID, event_process, event_handler, NULL));
}
