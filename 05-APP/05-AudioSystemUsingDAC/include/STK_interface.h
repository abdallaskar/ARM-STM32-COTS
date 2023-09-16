/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 July 2023						 			   */
/* Verstion    : 1.1 V	 										   */
/* Description : STK										       */
/*******************************************************************/
#ifndef     STK_INTERFACE_H
#define 	STK_INTERFACE_H





void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks , void (*copy_ptrF)(void));
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks , void (*copy_ptrF)(void));
void MSTK_voidStopInterval(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetReaminigTime(void);





#endif
