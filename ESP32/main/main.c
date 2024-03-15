#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "scgms.h"

void app_main(void)
{
    printf("ESP32 SCGMS DEMO\n");
    printf("------------------------------------------\n");
    build_filter_chain(NULL);
    while(1)
    {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    };
}
