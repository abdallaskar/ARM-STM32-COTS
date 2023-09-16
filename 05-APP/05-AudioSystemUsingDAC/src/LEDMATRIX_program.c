/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 3 August 2023							 		   */
/* Version     : 1.0 V	 										   */
/* Description : LEDMATRIX									       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_config.h"
#include "LEDMATRIX_private.h"



volatile u8* ptru8_letterData;
volatile u8  u8_iterator  = 0;
volatile u8  u8_counter = 0;


/* Initialization of led Matrix
 * ROWS Pins as output
 * Calms pins as output
 * Pins Number depend on configuration file */
void HLEDMATRIX_voidInit(void)
{
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW0_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW1_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW2_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW3_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW4_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW5_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW6_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_ROW7_PIN,OUTPUT_2MZ_PP);

	GPIO_voidSetPinDirecation(LEDMATRIX_COULM0_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM1_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM2_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM3_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM4_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM5_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM6_PIN,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(LEDMATRIX_COULM7_PIN,OUTPUT_2MZ_PP);

	
}

static void DisapleAllCoulms(void)
{
	GPIO_voidSetPinValue(LEDMATRIX_COULM0_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM1_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM2_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM3_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM4_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM5_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM6_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMATRIX_COULM7_PIN,HIGH);

}
static void SetROWValues(u8 Copy_u8value)
{
	u8 bit = 0;
	bit = GET_BIT(Copy_u8value,0);
	GPIO_voidSetPinValue(LEDMATRIX_ROW0_PIN,bit);
	bit = GET_BIT(Copy_u8value,1);
	GPIO_voidSetPinValue(LEDMATRIX_ROW1_PIN,bit);
	bit = GET_BIT(Copy_u8value,2);
	GPIO_voidSetPinValue(LEDMATRIX_ROW2_PIN,bit);
	bit = GET_BIT(Copy_u8value,3);
	GPIO_voidSetPinValue(LEDMATRIX_ROW3_PIN,bit);
	bit = GET_BIT(Copy_u8value,4);
	GPIO_voidSetPinValue(LEDMATRIX_ROW4_PIN,bit);
	bit = GET_BIT(Copy_u8value,5);
	GPIO_voidSetPinValue(LEDMATRIX_ROW5_PIN,bit);
	bit = GET_BIT(Copy_u8value,6);
	GPIO_voidSetPinValue(LEDMATRIX_ROW6_PIN,bit);
	bit = GET_BIT(Copy_u8value,7);
	GPIO_voidSetPinValue(LEDMATRIX_ROW7_PIN,bit);
}



void LED_CallBack(void)
{
	DisapleAllCoulms();
	SetROWValues(ptru8_letterData[u8_iterator ]);
	switch (u8_iterator )
	{
		case 0 : GPIO_voidSetPinValue(LEDMATRIX_COULM0_PIN,LOW);
			break;
		case 1 : GPIO_voidSetPinValue(LEDMATRIX_COULM1_PIN,LOW);
			break ;
		case 2 : GPIO_voidSetPinValue(LEDMATRIX_COULM2_PIN,LOW);
			break ;
		case 3 : GPIO_voidSetPinValue(LEDMATRIX_COULM3_PIN,LOW);
			break ;
		case 4 : GPIO_voidSetPinValue(LEDMATRIX_COULM4_PIN,LOW);
			break;
		case 5 : GPIO_voidSetPinValue(LEDMATRIX_COULM5_PIN,LOW);
			break ;
		case 6 : GPIO_voidSetPinValue(LEDMATRIX_COULM6_PIN,LOW);
			break ;
		case 7 : GPIO_voidSetPinValue(LEDMATRIX_COULM7_PIN,LOW);


				u8_iterator =0;
				u8_counter++;
				if(u8_counter == 25)
				{
					MSTK_voidStopInterval();
					u8_counter = 0;
				}
			break ;
		default:
			break ;

	}

	u8_iterator ++;

}


/*Display any character on led for little time */
void HLEDMATRIX_voidDisplay(u8* Copy_Pu8Data)
{
	ptru8_letterData = Copy_Pu8Data;
    MSTK_voidSetIntervalPeriodic(2500,LED_CallBack);

}

