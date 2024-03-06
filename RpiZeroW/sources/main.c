#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "pthread.h"

//#include <scgms.h>
#include <uart_print.h>

void task2(void *pParam) {
	//vTaskDelay(3000);
    /*build_filter_chain(NULL);
	create_level_event(10);
	create_level_event(12);
	create_level_event(14);*/

	while(1)
	{
		print("task2 run ");
		vTaskDelay(2000);
	}
}

void taskscg(void *pParam) {
	vTaskDelay(3000);
    	build_filter_chain(NULL);
	create_level_event(10);
	while(1)
	{
		print("task scgms run ");
		vTaskDelay(2000);
	}
}


void task1(void *pParam) {
static pthread_t xTxTask;
static pthread_attr_t xTxAttr;
static pthread_t xRxTask;
static pthread_attr_t xRxAttr;

	int iret = 0;

	iret = pthread_attr_init( &xTxAttr );
	configASSERT( !iret );
	iret = pthread_attr_init( &xRxAttr );
	configASSERT( !iret );

	struct sched_param xTxSchedParam = {.sched_priority = sched_get_priority_min(0),}; /* The task runs at the idle priority */
	struct sched_param xRxSchedParam = {.sched_priority = sched_get_priority_min(0) + 1,}; /* The task runs at a higher priority */
	pthread_attr_setstacksize( &xRxAttr , 32*1024);


	iret = pthread_attr_setschedparam(	&xTxAttr,
										&xTxSchedParam );
	configASSERT( !iret );
	iret = pthread_attr_setschedparam(	&xRxAttr,
										&xRxSchedParam );
	configASSERT( !iret );

	iret = pthread_create(	&xTxTask,
							&xTxAttr,	/* The thread attributes. */
							task2,	/* The function that implements the thread. */
							NULL );		/* The task parameter is not used, so set to NULL. */
	configASSERT( !iret );

	iret = pthread_create(	&xRxTask,
							&xRxAttr,	/* The thread attributes. */
							taskscg,	/* The function that implements the thread. */
							NULL );		/* The task parameter is not used, so set to NULL. */
	configASSERT( !iret );
	while(1) {
		;
	}
	while(1) 
	{
		print("task 1 run ");
		vTaskDelay(5000);
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
	//xTaskCreate(task2, "LED_1", 32 * 1024, NULL, 0, NULL); //512 Working 1024 and more, not???
	vTaskStartScheduler();
	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
















static pthread_t xTxTask;
static pthread_attr_t xTxAttr;
static pthread_t xRxTask;
static pthread_attr_t xRxAttr;

	int iret = 0;

	iret = pthread_attr_init( &xTxAttr );
	configASSERT( !iret );
	iret = pthread_attr_init( &xRxAttr );
	configASSERT( !iret );

	struct sched_param xTxSchedParam = {.sched_priority = sched_get_priority_min(0),}; /* The task runs at the idle priority */
	struct sched_param xRxSchedParam = {.sched_priority = sched_get_priority_min(0) + 1,}; /* The task runs at a higher priority */

	iret = pthread_attr_setschedparam(	&xTxAttr,
										&xTxSchedParam );
	configASSERT( !iret );
	iret = pthread_attr_setschedparam(	&xRxAttr,
										&xRxSchedParam );
	configASSERT( !iret );

	iret = pthread_create(	&xTxTask,
							&xTxAttr,	/* The thread attributes. */
							task2,	/* The function that implements the thread. */
							NULL );		/* The task parameter is not used, so set to NULL. */
	configASSERT( !iret );

	iret = pthread_create(	&xRxTask,
							&xRxAttr,	/* The thread attributes. */
							task2,	/* The function that implements the thread. */
							NULL );		/* The task parameter is not used, so set to NULL. */
	configASSERT( !iret );
	while(1) {
		;
	}
}





