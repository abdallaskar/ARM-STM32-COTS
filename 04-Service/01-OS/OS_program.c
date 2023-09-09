/*******************************************************************/
/* Author      : Abdalla Sakr 								       */
/* Data		   : 31 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Layer       : Service 										   */
/* Description : Operatind system for mange tasks			       */
/*******************************************************************/
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "STK_interface.h"

#include   "OS_interface.h"
#include   "OS_config.h"
#include   "OS_private.h"


//volatile u16  u16_SchedulerCounter = 0;



static void OS_voidScheduler(void){

	for(u16 i = 0; i < NUMBER_OF_TASKS ; i++)
	{
		if( ArrayTasks[i].FptrTaskName != NULL && ArrayTasks[i].TaskState == READY)
		{
			if(ArrayTasks[i].u16FirstDelay == 0)
			{
				ArrayTasks[i].FptrTaskName();
				ArrayTasks[i].u16FirstDelay=ArrayTasks[i].u16Priodisty-1;
			}
			else
			{
				ArrayTasks[i].u16FirstDelay--;
			}
		}
		else
		{
			//  do noting because this Task pointer equal null OR Task state not ready
		}
	}


}


void  OS_voidCreateTask(u8 Copy_u8TaskID,u16 Copy_u16Priodisty,u16 Copy_u16FirstDelay,void (Copy_Fptr) (void),States state){

	ArrayTasks[Copy_u8TaskID].u16Priodisty = Copy_u16Priodisty;
	ArrayTasks[Copy_u8TaskID].FptrTaskName = Copy_Fptr;
	ArrayTasks[Copy_u8TaskID].u16FirstDelay = Copy_u16FirstDelay;
	ArrayTasks[Copy_u8TaskID].TaskState = state;

}

void  OS_voidStartTask(void)
{
		// Intilaiziation tick every 1 micro second
		 MSTK_voidInit();
		// every 1 melli second call scheduler funcation
		 MSTK_voidSetIntervalPeriodic(1000 , OS_voidScheduler);
}


void  OS_voidSuspendTask(u8 Copy_u8TaskID){
	ArrayTasks[Copy_u8TaskID].TaskState = WATING;
}

void  OS_voidResumeTask(u8 Copy_u8TaskID){
	ArrayTasks[Copy_u8TaskID].TaskState = READY;
}






