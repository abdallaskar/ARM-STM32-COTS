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

// Delay funcation make delay 1 second
void delay(){
	for (u16 i = 0 ; i <1000;i++){
		for (u16 j = 0 ; j <1000;j++){
			asm("NOP");
		}
	}
}

// Initialize pin mode and configuration 
void  LED_voidInit(void){
	GPIO_voidSetBinDirection(LED_PORT,LED_PIN,OUTPUT_PP);
}

// On led 
void LED_voidOnLed(void)
{
    GPIO_voidSetBinValue(LED_PORT,LED_PIN,GPIO_HIGH)
}
// Off led 
void LED_voidOffLed(void)
{
	
    GPIO_voidSetBinValue(LED_PORT,LED_PIN,GPIO_LOW)
}


// not use this code becaus it stock in it 
void LED_voidToggelLed(void)
{
	while(1){
		GPIO_voidSetBinValue(LED_PORT,LED_PIN,GPIO_HIGH);
		delay();
		GPIO_voidSetBinValue(LED_PORT,LED_PIN,GPIO_LOW);
		delay();
		
	}
    
}





