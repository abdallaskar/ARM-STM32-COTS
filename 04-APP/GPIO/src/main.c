/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 21 JAN 2022									   */
/* Version     : 1.0 V	 										   */
/* Description : GPIO test     								       */
/*******************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

void delay(void){
	for(u16 i =0 ; i < 1000;i++ )
			{
				for(u16 j =0 ; j < 1000;j++ )
						{
							asm("NOP");
						}
			}
}

int main(){

	/* Initialize system clock */
	RCC_voidInitSystemClock();
	/* Enable clock to GPIOA peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	/* Enable clock to GPIOB peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	/* Enable clock to GPIOC peripheral */
	RCC_voidEnableClock(RCC_APB2,RCC_IOPC);


	GPIO_voidSetPinDirecation(PORTA,PIN0,INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
	
	GPIO_voidSetPinDirecation(PORTA,PIN1,OUTPUT_10MZ_PP);


	while (1)
	{
		if ( GPIO_u8GetPinValue(PORTA,PIN0) == 0 ){
			GPIO_voidSetPinValue(PORTA,PIN1,HIGH);
		}else {
			GPIO_voidSetPinValue(PORTA,PIN1,LOW);
		}
		
	}












	return 0;
}
