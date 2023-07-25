/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 12 FEB 2023						 			   */
/* Verstion    : 1.0 V	 										   */
/* Description : ULTRASONIC  								       */
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"

void ULTRASONIC_voidInit(void)
{
	GPIO_voidSetPinDirecation(ULTRASONIC_PORT,TRIG_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(ULTRASONIC_PORT,ECHO_PIN,INPUT_FLOATING);
}

u16 ULTRASONIC_u16GetDistance(void)
{
	u16 Local_u16Distance = 0;
	void GPIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN,LOW);
	_delayms(1);
	void GPIO_voidSetPinValue(ULTRASONIC_PORT,TRIG_PIN,HIGH);
	_delayms(0.000002);
	
	
}