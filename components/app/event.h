#pragma once

#include "esp_event.h"
#include "esp_event_base.h"

#ifdef __cplusplus
extern "C" {
#endif

ESP_EVENT_DECLARE_BASE(TASK_EVENTS);
extern esp_event_loop_handle_t event_handler;

enum {
    EVENT_UPDATE_GPS,
    EVENT_UPDATE_TH,
    EVENT_UPDATE_LOG,
    EVENT_UPDATE_BATTERY,
    EVENT_AUDIO,
};

void EventInit();

#ifdef __cplusplus
}
#endif