/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : STC										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_config.h"
#include "STK_interface.h"
#include "STK_private.h"



// Enable System Tick
void MSTK_voidEnableSystemTick(void)
{
	SET_BIT(STK_CTRL,0);
}
// Disable System tick
void MSTK_voidDisableSystemTick(void)
{
	CLR_BIT(STK_CTRL,0);
}


void MSTK_voidEnableSTKIntterupt(void)
{
	SET_BIT(STK_CTRL,1);
}
void MSTK_voidDisableSTKIntterupt(void)
{
	CLR_BIT(STK_CTRL,1);
}

void MSTK_voidClockSource(CLOCK_SOURCE  copy_ClockSource)
{
	switch (copy_ClockSource)
	{
		case 0  : CLR_BIT(STK_CTRL,2);
			break;
		case 1  : SET_BIT(STK_CTRL,2);
			break;
		default :  //return error 
			break;
	}
}
void MSTK_voidloadValue(u32 copy_u32CounterValue)
{
	STK_LOAD = copy_u32CounterValue;
}

u8 MSTK_voidReadFlag(void)
{
	u8 Local_FalgValue = GET_BIT(STK_CTRL,16);
	return Local_FalgValue ;
}
