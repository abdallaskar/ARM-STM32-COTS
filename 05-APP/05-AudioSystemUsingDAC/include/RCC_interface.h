/*******************************************************************/
/* Author     : Abdalla Mahmoud 								   */
/* Data		  : 9 Dec 2022										   */
/* Version    : 1.0 V											   */
/* Descrpiton : RCC  											   */
/*******************************************************************/
#ifndef   RCC_INTERFACE_H
#define   RCC_INTERFACE_H

/* Initialize types soruce of system clock */
void RCC_voidInitSystemClock(void);
/* Enable clock on any peripheral  */
void RCC_voidEnableClock(u8 Copy_u8BusId , u32  Copy_u32PerId);
/* Disable clock on any peripheral  */
void RCC_voidDisableClock(u8 Copy_u8BusId , u32  Copy_u32PerId);


/*RCC BUS types*/
#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2

/*RCC peripheral on APB2*/
#define RCC_AFIO    0
#define RCC_IOPA    2
#define RCC_IOPB	3
#define RCC_IOPC	4
#define RCC_IOPD	5
#define RCC_IOPE	6
#define RCC_IOPF	7
#define RCC_IOPG	8
#define RCC_ADC1	9
#define RCC_ADC2	10
#define RCC_TIM1	11
#define RCC_SPI1	12
#define RCC_TIM8	13
#define RCC_USART	14
#define RCC_ADC3	15

#define RCC_TIM9	19
#define RCC_TIM10	20
#define RCC_TIM11	21


















#endif
