#include "gui_task.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"

#include "lvgl/lvgl.h"
#include "lvgl_esp32_drivers/lvgl_helpers.h"
#include "lv_app/ui.h"
#include "update.h"

#define LV_TICK_PERIOD_MS 1
char buf_satellites[3];
char buf_speed[3];
char buf_trip_dist[6];
char buf_trip_time[8];
char buf_total[6];
char buf_temp_humi[8];
char buf_left[5];

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

void GuiSetSdcardStatus(bool status) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        if (status) {
            lv_obj_clear_flag(ui_imgsdcard, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ui_imgsdcard, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetParkingStatus(bool status) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        if (status) {
            lv_obj_add_flag(ui_imgp, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_clear_flag(ui_imgp, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetBluetoothStatus(bool status) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        if (status) {
            lv_obj_clear_flag(ui_imgbluetooth, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ui_imgbluetooth, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetTimenow(const char *buf) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_texttimenow, buf);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetRecordStatus(bool display) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        if (display) {
            lv_obj_clear_flag(ui_Imgrecording, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Imgrecordidle, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_clear_flag(ui_Imgrecordidle, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Imgrecording, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

// true:  located
// false: locating
void GuiSetLocateStatus(bool status) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        if (status) {
            lv_obj_clear_flag(ui_imglocated, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_imglocating, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(ui_imglocated, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_imglocating, LV_OBJ_FLAG_HIDDEN);
        }
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetSatellitesCnt(int cnt) {
    snprintf(buf_satellites, sizeof(buf_satellites), "%d", cnt);
    
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_textsatellites, buf_satellites);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetSpeed(int speed) {
    if( speed < 0) {
        buf_speed[0] = '-';
        buf_speed[1] = '-';
        buf_speed[2] = '\0';
    } else {
        buf_speed[0] = speed%100/10 + '0';
        buf_speed[1] = speed%10 + '0';
        buf_speed[2] = '\0';
    }

    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_textspeed, buf_speed);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetDirection(float dir) {
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_img_set_angle(ui_imgdirection, (int)(dir*10));
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetTripDist(float trip_dist) {
    snprintf(buf_trip_dist, sizeof(buf_trip_dist), "%5.2f", trip_dist);

    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_texttrip, buf_trip_dist);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetTripTime(int seconds) {
    int min = seconds / 60;
    int sec = seconds % 60;
    buf_trip_time[0] = min/10 + '0';
    buf_trip_time[1] = min%10 + '0';
    buf_trip_time[2] = ' ';
    buf_trip_time[3] = ':';
    buf_trip_time[4] = ' ';
    buf_trip_time[5] = sec/10 + '0';
    buf_trip_time[6] = sec%10 + '0';
    buf_trip_time[7] = 0;
    
    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_texttriptime, buf_trip_time);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetTotal(float total) {
    snprintf(buf_total, sizeof(buf_total), "%.1f", total);

    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_texttotal, buf_total);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetTempretureHumidity(int temp, int humidity) {
    buf_temp_humi[0] = temp/10 + '0';
    buf_temp_humi[1] = temp%10 + '0';
    buf_temp_humi[2] = 'C';
    buf_temp_humi[3] = ' ';
    buf_temp_humi[4] = humidity/10 + '0';
    buf_temp_humi[5] = humidity%10 + '0';
    buf_temp_humi[6] = '%';
    buf_temp_humi[7] = 0;

    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_textarea_set_text(ui_textwenshi, buf_temp_humi);
        xSemaphoreGive(xGuiSemaphore);
    }
}

void GuiSetBattery(int battery, int left) {
    snprintf(buf_left, sizeof(buf_left), "%dKM", left);

    if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
        lv_bar_set_value(ui_barbattery, battery, LV_ANIM_ON);
        lv_textarea_set_text(ui_textleft, buf_left);
        xSemaphoreGive(xGuiSemaphore);
    }
}

static void lv_tick_task(void *arg) {
    (void) arg;
    lv_tick_inc(LV_TICK_PERIOD_MS);
}

extern void guiTask(void *pvParameter) {
    (void) pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();
    xSemaphoreTake(xGuiSemaphore, portMAX_DELAY);

    lv_init();

    /* Initialize SPI or I2C bus used by the drivers */
    lvgl_driver_init();

    lv_color_t* buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);

    /* Use double buffered when not working with monochrome displays */
    lv_color_t* buf2 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2 != NULL);

    static lv_disp_draw_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;

    /* Initialize the working buffer depending on the selected display.
     * NOTE: buf2 == NULL when using monochrome displays. */
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);

    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = 240;
    disp_drv.ver_res = 320;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = disp_driver_flush;
    lv_disp_drv_register(&disp_drv);

    /* Register an input device when enabled on the menuconfig */
#if CONFIG_LV_TOUCH_CONTROLLER != TOUCH_CONTROLLER_NONE
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.read_cb = touch_driver_read;
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);
#endif

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"
    };
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    /* Create the demo application */
    ui_init();

    xSemaphoreGive(xGuiSemaphore);
    while (1) {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));

        /* Try to take the semaphore, call lvgl related function on success */
        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
        }
    }

    /* A task should NEVER return */
    free(buf1);
#ifndef CONFIG_LV_TFT_DISPLAY_MONOCHROME
    free(buf2);
#endif
    vTaskDelete(NULL);
}

void GuiInit() {
    
    xTaskCreatePinnedToCore(guiTask, "gui", 4096*2, NULL, 0, NULL, 1);
    vTaskDelay(100);
    
    GuiSetSdcardStatus(false);
    GuiSetParkingStatus(false);
    GuiSetBluetoothStatus(false);
    GuiSetTimenow("-- : --");
    GuiSetRecordStatus(false);
    GuiSetLocateStatus(false);
    GuiSetSatellitesCnt(0);
    GuiSetSpeed(-1);
    GuiSetDirection(0);
    GuiSetTripDist(0);
    GuiSetTripTime(0);
    GuiSetTotal(0);
    GuiSetTempretureHumidity(0, 0);
    GuiSetBattery(0, 0);
}