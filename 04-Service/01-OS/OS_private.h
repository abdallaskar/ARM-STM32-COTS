/*******************************************************************/
/* Author      : Abdalla Sakr 								       */
/* Data		   : 31 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Layer       : Service 										   */
/* Description : Operatind system for mange tasks			       */
/*******************************************************************/
#ifndef           OS_PRIVATE_H
#define 		  OS_PRIVATE_H



typedef struct 
{
	u16   u16Priodisty;
	void (*FptrTaskName)(void)  ;
	u16   u16FirstDelay;
	States  TaskState;
}Task;

static Task ArrayTasks[NUMBER_OF_TASKS] = {NULL};

static void OS_voidScheduler(void);



#endif 
