/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 22 JAN 2022									   */
/* Version     : 1.0 V	 										   */
/* Description : LED         								       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

// Delay function make delay 1 second
void LED_voidDelay(){
	for (u16 i = 0 ; i <1000;i++){
		for (u16 j = 0 ; j <1000;j++){
			asm("NOP");
		}
	}
}

// Initialize pin mode and configuration 
void  LED_voidInit(void){
	 GPIO_voidSetPinDirecation(LED_PORT ,LED_PIN ,OUTPUT_10MZ_PP);
}

// On led 
void LED_voidOnLed(void)
{
    GPIO_voidSetPinValue(LED_PORT,LED_PIN,HIGH);
}
// Off led 
void LED_voidOffLed(void)
{
	
    GPIO_voidSetPinValue(LED_PORT,LED_PIN,LOW);
}


// not use this code because it stock in it
void LED_voidToggelLed(void)
{
	while(1){
		GPIO_voidSetPinValue(LED_PORT,LED_PIN,HIGH);
		LED_voidDelay();
		GPIO_voidSetPinValue(LED_PORT,LED_PIN,LOW);
		LED_voidDelay();
		
	}
    
}





