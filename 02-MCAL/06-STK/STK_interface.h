/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Verstion    : 1.0 V	 										   */
/* Description : STK										       */
/*******************************************************************/
#ifndef     STK_INTERFACE_H
#define 	STK_INTERFACE_H


/**/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks , void (*copy_ptrF)(void));
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks , void (*copy_ptrF)(void));
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetReaminigTime(void);

# Enable System tic 
void MSTC_voidEnableSTC(void);
void MSTC_voidDisableSTC(void);
void MSTC_voidEnableSTCINT(void);
void MSTC_voidDisableSTCINT(void);
void MSTC_voidClockSource(clockSource   copy_clockSource);
void MSTC_voidloadValue(u32 copy_u32CounterValue);


enum clockSource
{
	AHB_8 = 0;
	AHB   = 1;
}








#endif
