/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 22 JAN 2022									   */
/* Version     : 1.0 V	 										   */
/* Description : SEGMENT         								   */
/*******************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SEGMENT_interface.h"
#include "SEGMENT_config.h"
#include "SEGMENT_private.h"



const u16 u16NumberArr[10]  = {0x003f, 0x0006, 0x005B, 0x004f, 0x0066, 0x006D,0x007d, 0x0007, 0x007f, 0x0067};



// Initialize segment configuration
void SEGMENT_voidInit(void)
{
	#if SEGMETN_PORT == PORTA 
		#if SEGMETN_HALF == FIRST_HALF
			GPIO_voidSetPinDirecation(PORTA,PIN0,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN1,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN2,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN3,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN4,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN5,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN6,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN7,OUTPUT_10MZ_PP);
		#elif SEGMETN_HALF == SECOND_HALF
			GPIO_voidSetPinDirecation(PORTA,PIN8,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN9,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN10,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN11,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN12,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN13,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN14,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTA,PIN15,OUTPUT_10MZ_PP);
		#endif 
	#elif SEGMETN_PORT == PORTB
		#if SEGMETN_HALF == FIRST_HALF
			GPIO_voidSetPinDirecation(PORB,PIN0,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN1,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN2,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN3,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN4,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN5,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN6,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORB,PIN7,OUTPUT_10MZ_PP);
		#elif SEGMETN_HALF == SECOND_HALF
			GPIO_voidSetPinDirecation(PORTB,PIN8,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN9,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN10,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN11,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN12,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN13,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN14,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTB,PIN15,OUTPUT_10MZ_PP);
		#endif 
	#elseif SEGMETN_PORT == PORTC
		#if SEGMETN_HALF == FIRST_HALF
			GPIO_voidSetPinDirecation(PORTC,PIN0,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN1,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN2,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN3,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN4,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN5,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN6,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN7,OUTPUT_10MZ_PP);
		#elif SEGMETN_HALF == SECOND_HALF
			GPIO_voidSetPinDirecation(PORTC,PIN8,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN9,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN10,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN11,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN12,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN13,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN14,OUTPUT_10MZ_PP);
			GPIO_voidSetPinDirecation(PORTC,PIN15,OUTPUT_10MZ_PP);
		#endif 
	#endif
	
}
// print number on seven segment
void SEGMENT_voidPrintNumber(u8 copy_u8Number)
{  
	#if SEGMETN_HALF == FIRST_HALF
		#if SEGMENT_TYPE == COMMEN_CATHOD
			GPIO_voidSetPortValue(SEGMENT_PORT  , u16NumberArr[copy_u8Number]);
		#elif SEGMENT_TYPE == COMMON_ANODE
			GPIO_voidSetPortValue(SEGMETN_PORT,~u16NumberArr[copy_u8Number]);
		#endif
	#elif  SEGMETN_HALF == SECOND_HALF
		#if SEGMENT_TYPE == COMMON_CATHOD
			GPIO_voidSetPortValue(SEGMETN_PORT,(u16NumberArr[copy_u8Number]<<8));
		#elif SEGMENT_TYPE == COMMON_ANODE
			GPIO_voidSetPortValue(SEGMETN_PORT,((~u16NumberArr[copy_u8Number])<<8));
		#endif
	#endif 
}
