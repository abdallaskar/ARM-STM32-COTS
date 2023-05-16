/*
 * main.c
 *
 *  Created on: Dec 21, 2022
 *      Author: abdalla
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"

#define PORTA_CRL     *((volatile u32*)0x40010800)
#define PORTA_ODR     *((volatile u32*)0x4001080C)


int main()
{
	RCC_voidInitSystemClock();         /*initialize system clock*/
	RCC_voidEnableClock(RCC_APB2,2);   /*enable clock on APB2 number   ( PortA peripheral)*/

    /*Configure pin0 on portA as output push pull */
	PORTA_CRL = 0x22222222;
	/*set 1 on pin 0 in portA*/
	PORTA_ODR = 0x0000ffff;

	while(1)
	{


	}


}


