/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : EXTI										       */
/*******************************************************************/
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include   "EXTI_interface.h"
#include   "EXTI_config.h"
#include   "EXTI_private.h"

// Initialization EXTI depend on configurations
void MEXTI_voidInit(void)
{
	#if    EXTI_MODE == FALLING 
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif  EXTI_MODE == RISING
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif  EXTI_MODE == ENY_CHANGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#else  #error   " Incorrect options "
	
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
	SET_BIT(EXTI -> SWIER , copy_u8Line)
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