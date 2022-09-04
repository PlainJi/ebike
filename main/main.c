/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include "include.h"

#include "gui_task.h"
#include "gps_task.h"
#include "ahtxx.h"
#include "update.h"
#include "adc.h"
#include "gps_log.h"
#include "event.h"

void PrintTaskInfo(void) {
    uint8_t pcWriteBuffer[500];

    vTaskDelay(100);

    printf("=======================================================\r\n");
    printf("task           state   priority      stack   id\r\n");
    vTaskList((char *)&pcWriteBuffer);
    printf("%s\r\n", pcWriteBuffer);

    printf("\r\ntask            run_count              usage\r\n");
    vTaskGetRunTimeStats((char *)&pcWriteBuffer);
    printf("%s\r\n", pcWriteBuffer);
}

void app_main(void)
{
    printf("Hello world!\n");
    EventInit();
    GpsLogInit();
    GuiInit();
    GpsInit();
    AhtInit();
    AdcInit();
    //AudioInit();

    // while (1)
    // {
    //     vTaskDelay(100);
    //     PrintTaskInfo();
    // }
}
