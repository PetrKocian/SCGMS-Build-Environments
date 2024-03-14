#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <scgms.h>
#include <uart_print.h>

void _init(void) {;}

void main (void)
{
 	__libc_init_array();
    uart_init();
	build_filter_chain(NULL);
	vTaskStartScheduler();
}





