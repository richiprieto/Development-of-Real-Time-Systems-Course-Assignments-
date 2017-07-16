/*
Development of Real-Time Systems
Assignment 1
14/07/2017
Ricardo Manuel Prieto Galarza
*/
/**********************************Programming assignment*********************************/
-Download the FreeRTOS project Here

-Import the project into Visual Studio Express 2015. More information from our Documentation.

-In Visual Studio click the “build” menu and “Build solution”. This will compile the project. More information from our Documentation.

-Now run the project. More information from our Documentation

-Familiarize yourself with the FreeRTOS API and locate to the main() function in the FreeRTOS project in Visual Studio Express

-Here, create two tasks with the following parameters seen in the code window (hint look at xTaskCreate() in the API)
Task1 name="Task1"Task2 name="Task2"
Task1 stack size = 1000
Task2 stack size = 100
Task1 priority = 3
Task2 priority = 1

-Create task functions containing the following functionality

Task1 should print out "This is task 1" every 100 milliseconds (hint use fflush(stdout) after printf())

Task2 should print out "This is task 2" every 500 milliseconds

-Provide a screenshot of the execution in a report and the source code of your solution.
/****************************************************************************************/

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Std C includes. */
#include <stdio.h>

/* The task functions. */
void task1(void *pvParameters);
void task2(void *pvParameters);

/* Config Constants. */
#define name1 "task1"
#define name2 "task2"
#define stackSize1 1000
#define stackSize2 100
#define taskPrior1 3
#define taskPrior2 1
#define delayTime1 100
#define delayTime2 500

/*-----------------------------------------------------------*/

int main(void)
{
	/* Create the task1 */
	xTaskCreate(task1, name1, stackSize1, NULL, taskPrior1, NULL);

	/* Create the task2. */
	xTaskCreate(task2, name2, stackSize2, NULL, taskPrior2, NULL);

	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;; );
	return 0;
}
/*-----------------------------------------------------------*/

void task1(void *pvParameters)
{
	const char *pcTaskName = "This is task 1 Time:";
	const TickType_t xDelay = delayTime1 / portTICK_PERIOD_MS;
	
	for (;; )
	{
		/* Print out the name of this task. */
		printf("%s %d\r\n", pcTaskName, xTaskGetTickCountFromISR() * portTICK_RATE_MS);
		fflush(stdout);

		/* Delay for a period. */
		vTaskDelay(xDelay);
	}
}
/*-----------------------------------------------------------*/

void task2(void *pvParameters)
{
	const char *pcTaskName = "This is task 2 Time:";
	const TickType_t xDelay = delayTime2 / portTICK_PERIOD_MS;
	
	for (;; )
	{
		/* Print out the name of this task. */
		printf("%s %d\r\n", pcTaskName, xTaskGetTickCountFromISR() * portTICK_RATE_MS);
		fflush(stdout);

		/* Delay for a period. */
		vTaskDelay(xDelay);
	}
}
