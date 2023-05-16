/*******************************************************************/
/* Author     : Abdalla Mahmoud 								   */
/* Data		  : 9 Dec 2022										   */
/* Verstion   : V01												   */
/*******************************************************************/
#ifndef   RCC_INTERFACE_H
#define   RCC_INTERFACE_H


void RCC_voidInitSystemClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId , u32  Copy_u32PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u32  Copy_u32PerId);


#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2









#endif
