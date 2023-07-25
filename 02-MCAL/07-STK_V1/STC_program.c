/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : STC										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STC_interface.h"
#include "STC_private.h"
#include "STC_config.h"


void MSTC_voidEnableSTC(void)
{
	SET_BIT(STK_CTRL,0);
}
void MSTC_voidDisableSTC(void)
{
	CLR_BIT(STK_CTRL,0);
}


void MSTC_voidEnableSTCINT(void)
{
	SET_BIT(STK_CTRL,1);
}
void MSTC_voidDisableSTCINT(void)
{
	CLR_BIT(STK_CTRL,1);
}
void MSTC_voidClockSource(CLOCK_SOURCE   copy_ClockSource)
{
	switch (copy_ClockSource)
	{
		case 0  : CLR_BIT(STK_CTRL,2);break;
		case 1  : SET_BIT(STK_CTRL,2);break;
		default :  //return error 
		break;
	}
}
void MSTC_voidloadValue(u32 copy_u32CounterValue)
{
	STK_LOAD = copy_u32CounterValue;
}

u8 MSTC_voidReadFlag(void)
{
	u8 Local_FalgValue = GET_BIT(STK_CTRL,16);
	return Local_FalgValue ;
}
