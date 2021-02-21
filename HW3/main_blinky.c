/*
 * Joshua Mack, Dhruv Mayur Gajaria, Sahil Hassan, Michael Inouye
 * Dr. Tosiron Adegbija
 * ECE 576B
 * 28 February 2021
 * Homework 3: Introduction to Real-Time Operating Systems (FreeRTOS)
 * NO FreeRTOSConfig.h configuration required.
 *
 * FreeRTOS V202012.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

/******************************************************************************
 * NOTE 1: The FreeRTOS demo threads will not be running continuously, so
 * do not expect to get real time behaviour from the FreeRTOS Linux port, or
 * this demo application.  Also, the timing information in the FreeRTOS+Trace
 * logs have no meaningful units.  See the documentation page for the Linux
 * port for further information:
 * https://freertos.org/FreeRTOS-simulator-for-Linux.html
 *
 * NOTE 2:  This project provides two demo applications.  A simple blinky style
 * project, and a more comprehensive test and demo application.  The
 * mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting in main.c is used to select
 * between the two.  See the notes on using mainCREATE_SIMPLE_BLINKY_DEMO_ONLY
 * in main.c.  This file implements the simply blinky version.  Console output
 * is used in place of the normal LED toggling.
 *
 * NOTE 3:  This file only contains the source code that is specific to the
 * basic demo.  Generic functions, such FreeRTOS hook functions, are defined
 * in main.c.
 ******************************************************************************
 *
 * main_blinky() creates one queue, one software timer, and two tasks.  It then
 * starts the scheduler.
 *
 * The Queue Send Task:
 * The queue send task is implemented by the prvQueueSendTask() function in
 * this file.  It uses vTaskDelayUntil() to create a periodic task that sends
 * the value 100 to the queue every 200 milliseconds (please read the notes
 * above regarding the accuracy of timing under Linux).
 *
 * The Queue Send Software Timer:
 * The timer is an auto-reload timer with a period of two seconds.  The timer's
 * callback function writes the value 200 to the queue.  The callback function
 * is implemented by prvQueueSendTimerCallback() within this file.
 *
 * The Queue Receive Task:
 * The queue receive task is implemented by the prvQueueReceiveTask() function
 * in this file.  prvQueueReceiveTask() waits for data to arrive on the queue.
 * When data is received, the task checks the value of the data, then outputs a
 * message to indicate if the data came from the queue send task or the queue
 * send software timer.
 *
 * Expected Behaviour:
 * - The queue send task writes to the queue every 200ms, so every 200ms the
 *   queue receive task will output a message indicating that data was received
 *   on the queue from the queue send task.
 * - The queue send software timer has a period of two seconds, and is reset
 *   each time a key is pressed.  So if two seconds expire without a key being
 *   pressed then the queue receive task will output a message indicating that
 *   data was received on the queue from the queue send software timer.
 *
 * NOTE:  Console input and output relies on Linux system calls, which can
 * interfere with the execution of the FreeRTOS Linux port. This demo only
 * uses Linux system call occasionally. Heavier use of Linux system calls
 * may crash the port.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Local includes. */
#include "console.h"

/* Priorities at which the tasks are created. */
#define sadCalc_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define	arrayGen1_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define	arrayGen2_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )

/* The rate at which data is sent to the queue.  The times are converted from
milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTASK_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 200UL )
#define mainTIMER_SEND_FREQUENCY_MS			pdMS_TO_TICKS( 2000UL )

/* The number of items the queue can hold at once. */
#define mainQUEUE_LENGTH					( 2 )

/* The values sent to the queue receive task from the queue send task and the
queue send software timer respectively. */
#define mainVALUE_SENT_FROM_TASK			( 100UL )
#define mainVALUE_SENT_FROM_TIMER			( 200UL )

#define ARRAY_SIZE 10
#define MAX_ITERATIONS 5
#define MAX_TIME 1000
#define TIMER_PERIOD pdMS_TO_TICKS( 100UL )

/*-----------------------------------------------------------*/

/*
 * The tasks as described in the comments at the top of this file.
 */
//static void prvQueueReceiveTask( void *pvParameters );
//static void prvQueueSendTask( void *pvParameters );
static void arrayGen1Task( void *pvParameters );
static void arrayGen2Task( void *pvParameters );
static void sadCalcTask( void *pvParameters );

/*
 * The callback function executed when the software timer expires.
 */
//static void prvQueueSendTimerCallback( TimerHandle_t xTimerHandle );
static void monitorCallback( TimerHandle_t xTimerHandle );
TaskHandle_t sadCalcHandle = NULL;

/*-----------------------------------------------------------*/

/* The queue used by both tasks. */
//static QueueHandle_t xQueue = NULL;
static QueueHandle_t Queue1 = NULL;
static QueueHandle_t Queue2 = NULL;

/* A software timer that is started from the tick hook. */
static TimerHandle_t xTimer = NULL;

SemaphoreHandle_t array1Semaphore;
SemaphoreHandle_t array2Semaphore;
SemaphoreHandle_t sadSemaphore;

/*-----------------------------------------------------------*/

/*** SEE THE COMMENTS AT THE TOP OF THIS FILE ***/
void main_blinky( void )
{
	const TickType_t xTimerPeriod = TIMER_PERIOD;
	
	array1Semaphore = xSemaphoreCreateBinary();
	array2Semaphore = xSemaphoreCreateBinary();
	sadSemaphore = xSemaphoreCreateBinary();

	/* Create the queue. */
	Queue1 = xQueueCreate( ARRAY_SIZE, sizeof( int ) );
	Queue2 = xQueueCreate( ARRAY_SIZE, sizeof( int ) );

	if (( Queue1 != NULL ) && ( Queue2 != NULL ))
	{
		/* Start the two tasks as described in the comments at the top of this
		file. */
		xTaskCreate( sadCalcTask,			/* The function that implements the task. */
					"sadCalc", 							/* The text name assigned to the task - for debug only as it is not used by the kernel. */
					configMINIMAL_STACK_SIZE, 		/* The size of the stack to allocate to the task. */
					NULL, 							/* The parameter passed to the task - not used in this simple case. */
					sadCalc_TASK_PRIORITY,/* The priority assigned to the task. */
					&sadCalcHandle );							/* The task handle is not required, so NULL is passed. */

		xTaskCreate( arrayGen1Task, "arrayGen1", configMINIMAL_STACK_SIZE, NULL, arrayGen1_TASK_PRIORITY, NULL );
		xTaskCreate( arrayGen2Task, "arrayGen2", configMINIMAL_STACK_SIZE, NULL, arrayGen2_TASK_PRIORITY, NULL );

		/* Create the software timer, but don't start it yet. */
		xTimer = xTimerCreate( "monitor",				/* The text name assigned to the software timer - for debug only as it is not used by the kernel. */
								xTimerPeriod,		/* The period of the software timer in ticks. */
								pdTRUE,				/* xAutoReload is set to pdTRUE. */
								NULL,				/* The timer's ID is not used. */
								monitorCallback );/* The function executed when the timer expires. */

		if( xTimer != NULL )
		{
			xTimerStart( xTimer, 0 );
		}

		/* Start the tasks and timer running. */
		xSemaphoreGive(array1Semaphore);
		//xSemaphoreGive(array2Semaphore);
		//xSemaphoreGive(sadSemaphore);
		vTaskStartScheduler();
		
	}

	/* If all is well, the scheduler will now be running, and the following
	line will never be reached.  If the following line does execute, then
	there was insufficient FreeRTOS heap memory available for the idle and/or
	timer tasks	to be created.  See the memory management section on the
	FreeRTOS web site for more details. */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void arrayGen1Task( void *pvParameters )
{
TickType_t xNextWakeTime;
const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
//const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;

	/* Prevent the compiler warning about the unused parameter. */
	( void ) pvParameters;

	/* Initialise xNextWakeTime - this only needs to be done once. */
	//xNextWakeTime = xTaskGetTickCount();
	
	int inputArray[ARRAY_SIZE];

	int taskCount = 0;

	for( ;; )
	{
		
		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, pdMS_TO_TICKS() was used to
		convert a time specified in milliseconds into a time specified in ticks.
		While in the Blocked state this task will not consume any CPU time. */
		//vTaskDelayUntil( &xNextWakeTime, xBlockTime );
		xSemaphoreTake(array1Semaphore, portMAX_DELAY);
		
		/* Send to the queue - causing the queue receive task to unblock and
		write to the console.  0 is used as the block time so the send operation
		will not block - it shouldn't need to block as the queue should always
		have at least one space at this point in the code. */
		for (int i = 0; i < ARRAY_SIZE; i++) {
			inputArray[i] = rand() % 100;
		}	
		
		for (int i = 0; i < ARRAY_SIZE; i++) {
			xQueueSend( Queue1, &inputArray[i], 0U );
			console_print( "Element %d sent to Queue1: %d\n", i, inputArray[i]);
		}
		
		xSemaphoreGive(array2Semaphore);
		
		taskCount++;
		if (taskCount >= MAX_ITERATIONS) {
			vTaskDelete(NULL);
		}
	}
}
/*-----------------------------------------------------------*/

static void arrayGen2Task( void *pvParameters )
{
TickType_t xNextWakeTime;
const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
//const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;

	/* Prevent the compiler warning about the unused parameter. */
	( void ) pvParameters;

	/* Initialise xNextWakeTime - this only needs to be done once. */
	//xNextWakeTime = xTaskGetTickCount();
	
	int inputArray[ARRAY_SIZE];

	int taskCount = 0;

	for( ;; )
	{
		
		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, pdMS_TO_TICKS() was used to
		convert a time specified in milliseconds into a time specified in ticks.
		While in the Blocked state this task will not consume any CPU time. */
		//vTaskDelayUntil( &xNextWakeTime, xBlockTime );
		xSemaphoreTake(array2Semaphore, portMAX_DELAY);
		
		/* Send to the queue - causing the queue receive task to unblock and
		write to the console.  0 is used as the block time so the send operation
		will not block - it shouldn't need to block as the queue should always
		have at least one space at this point in the code. */
		for (int i = 0; i < ARRAY_SIZE; i++) {
			inputArray[i] = rand() % 100;
		}	
		
		for (int i = 0; i < ARRAY_SIZE; i++) {
			xQueueSend( Queue2, &inputArray[i], 0U );
			console_print( "Element %d sent to Queue2: %d\n", i, inputArray[i]);
		}
	
		xSemaphoreGive(sadSemaphore);

		taskCount++;
		if (taskCount >= MAX_ITERATIONS) {
			vTaskDelete(NULL);
		}
	}
}
/*-----------------------------------------------------------*/

static void monitorCallback( TimerHandle_t xTimerHandle )
{
const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TIMER;

	/* This is the software timer callback function.  The software timer has a
	period of two seconds and is reset each time a key is pressed.  This
	callback function will execute if the timer expires, which will only happen
	if a key is not pressed for two seconds. */

	/* Avoid compiler warnings resulting from the unused parameter. */
	( void ) xTimerHandle;

	/* Send to the queue - causing the queue receive task to unblock and
	write out a message.  This function is called from the timer/daemon task, so
	must not block.  Hence the block time is set to 0. */
	//xQueueSend( xQueue, &ulValueToSend, 0U );
	console_print( "Current time: %d\n", xTaskGetTickCount() );
	
	if ( (xTaskGetTickCount() ) > MAX_TIME) {
		console_print( "Application runtime has exceeded MAX_TIME ms\n" );
		vTaskDelete(sadCalcHandle);
		vTaskDelete(NULL);
	}
}
/*-----------------------------------------------------------*/

static void sadCalcTask( void *pvParameters )
{
	int inputArray1[ARRAY_SIZE];
	int inputArray2[ARRAY_SIZE];


	/* Prevent the compiler warning about the unused parameter. */
	( void ) pvParameters;

	for( ;; )
	{
		xSemaphoreTake(sadSemaphore, portMAX_DELAY);
		
		/* Wait until something arrives in the queue - this task will block
		indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
		FreeRTOSConfig.h.  It will not use any CPU time while it is in the
		Blocked state. */
		for (int i = 0; i < ARRAY_SIZE; i++) {
			xQueueReceive( Queue1, &inputArray1[i], portMAX_DELAY );
			console_print( "Received %d from Queue1\n", inputArray1[i] );
		}
		
		for (int i = 0; i < ARRAY_SIZE; i++) {
			xQueueReceive( Queue2, &inputArray2[i], portMAX_DELAY );
			console_print( "Received %d from Queue2\n", inputArray2[i] );
		}
		
		int sad = 0;
		
		for (int i = 0; i < ARRAY_SIZE; i++) {
			sad += inputArray1[i] > inputArray2[i] ? inputArray1[i] - inputArray2[i] : inputArray2[i] - inputArray1[i];
		}
		
		console_print( "Sum of absolute differences: %d\n", sad );
		
		xSemaphoreGive(array1Semaphore);
		

	}
}
/*-----------------------------------------------------------*/
