/*******************************************************************/
/* Author      : Abdalla Sakr 								       */
/* Data		   : 5 Sep 2023	     					 			   */
/* Version     : 1.0 V	 										   */
/* Layer       : Application									   */
/* Description : 		       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "OS_interface.h"

void  Toggleled1(void);
void  Toggleled2(void);
void  Toggleled3(void);
void  Toggleled4(void);


int main()
{
	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);

	GPIO_voidSetPinDirecation(PORTA,PIN0,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN1,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN2,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN3,OUTPUT_2MZ_PP);



	GPIO_voidSetPinValue(PORTA,PIN0,LOW);
	GPIO_voidSetPinValue(PORTA,PIN1,LOW);
	GPIO_voidSetPinValue(PORTA,PIN2,LOW);
	GPIO_voidSetPinValue(PORTA,PIN3,LOW);



	OS_voidCreateTask(0,500,0,Toggleled1,READY);
	OS_voidCreateTask(1,1200,20,Toggleled2,READY);
	OS_voidCreateTask(2,2000,10,Toggleled3,READY);
	OS_voidCreateTask(3,4400,30,Toggleled4,READY);

	OS_voidStartTask();

	while(1)
	{


	}

	return 0;
}

void  Toggleled1(void){
	GPIO_voidTogglePinValue(PORTA,PIN0);
}
void  Toggleled2(void){
	GPIO_voidTogglePinValue(PORTA,PIN1);
}
void  Toggleled3(void)
{
	GPIO_voidTogglePinValue(PORTA,PIN2);
}
void  Toggleled4(void)
{
	GPIO_voidTogglePinValue(PORTA,PIN3);
}
