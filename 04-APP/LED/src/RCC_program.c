/*******************************************************************/
/* Author     : Abdalla Mahmoud 								   */
/* Data		  : 9 Dec 2022										   */
/* Version    : 1.0 V											   */
/* Descrpiton : RCC  											   */
/*******************************************************************/




#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"



/* Initialize types soruce of system clock */
void RCC_voidInitSystemClock(void)
{
	#if  RCC_CLOCK_TYPE  == RCC_HSI
		RCC_CR   = 0x00000081;   /* Enable high speed internal + triming = 0 */
		RCC_CFGR = 0X00000000;
		
	#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000;   /*Enable high speed external crystal*/
		RCC_CFGR = 0X00000001;
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR   = 0x00050000;   /*Enable high speed extrnal with bypass */
		RCC_CFGR = 0X00000001;
	#elif RCC_CLOCK_TYPE == RCC_PLL
		
		#if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
			RCC_CR = 0x01000001;   /*Enable PLL using high speed internal */
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
			RCC_CR = 0x01010000;
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
			RCC_CR = 0x01010000;
		#endif
		
		
	#else 
		#error("Incorrect options ")
	#endif
}

/* Enable clock on any peripheral  */
void RCC_voidEnableClock(u8 Copy_u8BusId , u32  Copy_u32PerId)
{
	if(Copy_u32PerId <= 31)
	{   /*switch on peripheral types*/
		switch(Copy_u8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR,Copy_u32PerId)  ;         break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR ,Copy_u32PerId);         break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR ,Copy_u32PerId);         break;
			default :   /*Error */             break;
		}
		
	}
	else 
	{
		/* Error */
	}
	
}

/* Disable clock on any peripheral  */
void RCC_voidDisableClock(u8 Copy_u8BusId , u32  Copy_u32PerId)
{
	if(Copy_u32PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR,Copy_u32PerId)  ;         break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR ,Copy_u32PerId);         break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR ,Copy_u32PerId);         break;
			default :   /*Error */             break;
		}
		
	}
	else 
	{
		/* Error */
	}
	
}
