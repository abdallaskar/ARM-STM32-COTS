/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Verstion    : 1.0 V	 										   */
/* Description : STK										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#inlcude "STK_interface.h"
#inlcude "STK_private.h"
#inlcude "STK_config.h"







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
void MSTC_voidClockSource(clockSource   copy_clockSource)
{
	switch (copy_clockSource)
	{
		case 0  : CLR_BIT(STK_CTRL,2)break;
		case 1  : SET_BIT(STK_CTRL,2)break;
		default :  //return error 
		break;
	}
}
void MSTC_voidloadValue(u32 copy_u32CounterValue)
{
	STK_VAL = copy_u32CounterValue;
}

