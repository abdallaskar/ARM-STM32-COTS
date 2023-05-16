/*
 * main.c
 *
 *  Created on: Jan 22, 2023
 *      Author: abdalla
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"



int main(){

	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	LED_voidInit();
	LED_voidOnLed();
	LED_voidDelay();
	LED_voidOffLed();
	LED_voidToggelLed();

	while(1){




	}
}
