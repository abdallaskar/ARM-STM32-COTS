/*******************************************************************/
/* Author      : Abdalla Sakr 								       */
/* Data		   : 31 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Layer       : Service 										   */
/* Description : Operatind system for mange tasks			       */
/*******************************************************************/
#ifndef           OS_INTERFACE_H
#define 		  OS_INTERFACE_H


typedef enum {
	READY,
	WATING
}States;


void  OS_voidCreateTask(u8 Copy_u8TaskID,u16 Copy_u16Priodisty,u16 Copy_u16FirstDelay,void (Copy_Fptr) (void),States state);
void  OS_voidStartTask(void);
void  OS_voidSuspendTask(u8 Copy_u8TaskID);
void  OS_voidResumeTask(u8 Copy_u8TaskID);







#endif 
