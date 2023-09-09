/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 July 2023						 			   */
/* Verstion    : 1.1 V	 										   */
/* Description : STK										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void (*CallBack)(void) = NULL ;
bool volatile  u8SignalOrPeriodic=0;
u32 volatile  u32Periodic_Ticks=0;


/* Choise clock source depend on configuration file */
void MSTK_voidInit(void)
{

	#if STK_CLOCK_SOURCE == AHB_8
	 	 CLR_BIT(STK_CTRL,2);
	#elif STK_CLOCK_SOURCE == AHB
	 	SET_BIT(STK_CTRL,2);
	#else
		#error "there is error in configuration file"
	#endif

}

/* make delay using timer and procesor still busy in this duration */
void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	STK_LOAD = copy_u32Ticks;
	SET_BIT(STK_CTRL,0);

	while(GET_BIT(STK_CTRL,16)==0);
	CLR_BIT(STK_CTRL,0);
}
/* execute funcation after specific time for one time*/
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks , void (*copy_ptrF)(void))
{
	u8SignalOrPeriodic = False;
	CallBack = copy_ptrF;
	// Enable systick and enable intterupt
	SET_BIT(STK_CTRL,0);
	SET_BIT(STK_CTRL,1);
   // load value to load register and set address for call back funcation
	STK_LOAD=copy_u32Ticks;

}

/* execute funcation after specific time using timer and still execute it periodic */
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks , void (*copy_ptrF)(void))
{
	    u8SignalOrPeriodic = True;
	    u32Periodic_Ticks = copy_u32Ticks;
		// Enable systick and enable intterupt
		SET_BIT(STK_CTRL,0);
		SET_BIT(STK_CTRL,1);
		// load value to load register and set address for call back funcation
		STK_LOAD=copy_u32Ticks;
		CallBack = copy_ptrF;
}
/* Stop interval wahtif singal or periodic */
void MSTK_voidStopInterval(void){
	// Stop timer
    	CLR_BIT(STK_CTRL,0);
}
/* Get reaming Time to reach to zero */
u32  MSTK_u32GetReaminigTime(void)
{
	u32 local_u32ReamingTime=0;
	local_u32ReamingTime = STK_VAL;

	return local_u32ReamingTime;
}

/*Get Elapse time : time the counter count it */
u32  MSTK_u32GetElapsedTime(void)
{

	u32 local_u32ElapsedTime=0;
	local_u32ElapsedTime = STK_LOAD - STK_VAL;

	return local_u32ElapsedTime;
}


void SysTick_Handler(void)
{
	u8 GetValueFlag= GET_BIT(STK_CTRL,16);
	if(u8SignalOrPeriodic ==0)
	{
		if(CallBack != NULL)
		CallBack();
	}
	else
	{
		if(CallBack != NULL)
		CallBack();
		STK_LOAD = u32Periodic_Ticks;
	}
}
