#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "scgms.h"

void app_main(void)
{
    printf("ESP32 SCGMS DEMO\r\n");
    printf("------------------------------------------\r\n");
    build_filter_chain(NULL);
    while(1)
    {
        create_level_event(10);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    };
}
