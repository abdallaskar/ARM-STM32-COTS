/*******************************************************************/
/* Author      : Abdalla Skar   								   */
/* Data		   : 29 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : EXTI										       */
/*******************************************************************/

#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "EXTI_interface.h"
#include   "EXTI_config.h"
#include   "EXTI_private.h"

void (*CallBack) (void) = NULL ;


// Initialization EXTI two factors line number and sense mode  depend on configurations
void MEXTI_voidInit(void)
{
	#if    EXTI_SENSE_MODE == FALLING
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif  EXTI_SENSE_MODE == RISING
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif  EXTI_SENSE_MODE == ENY_CHANGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#else
		#error   " Incorrect sense mode options "
	#endif
	
	#if    EXTI_LINE == LINE0
		SET_BIT(EXTI -> IMR , LINE0);
	#elif  EXTI_LINE == LINE1
		SET_BIT(EXTI -> IMR , LINE1);
	#elif  EXTI_LINE == LINE2
		SET_BIT(EXTI -> IMR , LINE2);
	#elif  EXTI_LINE == LINE3
		SET_BIT(EXTI -> IMR , LINE3);
	#elif  EXTI_LINE == LINE4
		SET_BIT(EXTI -> IMR , LINE4);
	#elif  EXTI_LINE == LINE5
		SET_BIT(EXTI -> IMR , LINE5);
	#elif  EXTI_LINE == LINE6
		SET_BIT(EXTI -> IMR , LINE6);
	#elif  EXTI_LINE == LINE7
		SET_BIT(EXTI -> IMR , LINE7);
	#elif  EXTI_LINE == LINE8
		SET_BIT(EXTI -> IMR , LINE8);
	#else
		#error   " Incorrect LINE opetions "
	#endif
}

// Change snese mode and line number on run time
void MEXTI_voidSetSignalLatch(u8 Copy_u8SenseMode,u8 Copy_u8LineNumber){
	switch(Copy_u8SenseMode)
	{
		case FALLING :
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
			break;
		case RISING:
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			break;
		case ENY_CHANGE:
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			break;
		default:
			break;
	}
	switch (Copy_u8LineNumber)
	{
		case LINE0:
			SET_BIT(EXTI -> IMR , LINE0);
			break;
		case LINE1:
			SET_BIT(EXTI -> IMR , LINE1);
			break;
		case LINE2:
			SET_BIT(EXTI -> IMR , LINE2);
			break;
		case LINE3:
			SET_BIT(EXTI -> IMR , LINE2);
			break;
		case LINE4:
			SET_BIT(EXTI -> IMR , LINE4);
			break;
		case LINE5:
			SET_BIT(EXTI -> IMR , LINE5);
			break;
		case LINE6:
			SET_BIT(EXTI -> IMR , LINE6);
			break;
		case LINE7:
			SET_BIT(EXTI -> IMR , LINE7);
			break;
		case LINE8:
			SET_BIT(EXTI -> IMR , LINE8);
			break;
		default:
			break;
	}


}

// Enable any line on EXTI
void MEXTI_voidEnableEXTI (u8 copy_u8Line)
{
	SET_BIT(EXTI -> IMR , copy_u8Line);
}
// Disable any line on EXTI
void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , copy_u8Line);
}
// Make software Interrupt
void MEXTI_voidSwInterrupt(u8 copy_u8Line){
	SET_BIT(EXTI -> SWIER , copy_u8Line);
}
// Set Call back funcation
void MEXTI_voidSetCallBack(void (*Copy_Fptr)(void)){
	CallBack = Copy_Fptr;
}
// Set line mode 
void MEXTI_voidSetLineMode(u8 copy_u8Line , u8 copy_u8Mode)
{
	switch (copy_u8Mode) 
	{
		case FALLING :
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
		break;
		case RISING :
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
		break;
		case ENY_CHANGE :
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
		break;
		
	}
}


void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI -> PR,0);
	if (CallBack != NULL)
		CallBack();

}
