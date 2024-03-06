#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <scgms.h>
#include <uart_print.h>

void task1(void *pParam) {
	while(1) 
	{
		print("task 1 run ");
		vTaskDelay(5000);
	}
}

void task2(void *pParam) {
	vTaskDelay(3000);
    build_filter_chain(NULL);
	create_level_event(10);
	create_level_event(12);
	create_level_event(14);

	while(1)
	{
		print("task2 run ");
		vTaskDelay(2000);
	}
}


/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
void _init(void) {;}


void main (void)
{
 	__libc_init_array();
    uart_init();

	xTaskCreate(task1, "LED_0", 128, NULL, 0, NULL);
	xTaskCreate(task2, "LED_1", 32 * 1024, NULL, 0, NULL); //512 Working 1024 and more, not???
	vTaskStartScheduler();
	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	while(1) {
		;
	}
}
