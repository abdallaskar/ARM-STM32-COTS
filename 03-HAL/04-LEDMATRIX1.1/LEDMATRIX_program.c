/*******************************************************************/
/* Author      : Abdalla Sakr 								       */
/* Data		   : 15 Aug 2023							 			   */
/* Verstion    : 1.1 V	 										   */
/* Description : LEDMATRIX									       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_config.h"
#include "LEDMATRIX_private.h"

u8 u8SpeedNumber = 25;

/* Initialzation of led Matrix
 * ROWS Pins as output
 * Coulms pins as output
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



/*Display any character on led for little time */
void HLEDMATRIX_voidDisplay(u8* Copy_Pu8Data)
{
	u8 var = 10;
	while(var)
	{
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[0]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM0_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);

			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[1]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM1_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[2]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM2_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[3]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM3_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[4]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM4_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[5]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM5_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[6]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM6_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);
			DisapleAllCoulms();
			SetROWValues(Copy_Pu8Data[7]);
			GPIO_voidSetPinValue(LEDMATRIX_COULM7_PIN,LOW);
			//delay 250 Ms
			MSTK_voidSetBusyWait(2500);

			var --;
	}

}




static void voidSubArray(u8* Copy_Pu8MainArry,u8 Copy_u8LengthMainArry,u8* Copy_Pu8SubArry,u8 Copy_u8Start,u8 Copy_u8End)
{

	if(Copy_u8Start < Copy_u8End)
	{
		for(u8 i = Copy_u8Start,j=0 ; i < Copy_u8End ; i++,j++)
			{
			Copy_Pu8SubArry[j]=Copy_Pu8MainArry[i];
			}
	}
	else
	{
		u8 Local_u8var=0;
		for(u8 i = Copy_u8Start ; i < Copy_u8LengthMainArry; Local_u8var++,i++)
		{
			Copy_Pu8SubArry[Local_u8var]=Copy_Pu8MainArry[i];
		}
		for(u8 i = 0 ; i <= Copy_u8End; Local_u8var++,i++)
		{
			Copy_Pu8SubArry[Local_u8var]=Copy_Pu8MainArry[i];
		}
	}


}
void HLEDMATRIX_voidDisplayText(u8* u8ptrText,u8 u8CopyLength){

		for(u8 i = 0; i<u8CopyLength;i++)
			{
				u8 Local_u8Charcter[8]={0};
				voidSubArray(u8ptrText,u8CopyLength,Local_u8Charcter,i,(i+8)%(u8CopyLength+1));
				HLEDMATRIX_voidDisplay(Local_u8Charcter);

			}

}
void HLEDMATRIX_voidStopDisplay(u8* u8ptrText,u8 u8CopyLength){
	for(u8 i =0 ; i< u8CopyLength; i++)
	{
		u8ptrText[i]=0;
	}
}
void HLEDMATRIX_voidSpeedUp(void){
	if(u8SpeedNumber > 5 ){
		u8SpeedNumber-=3;
	}
}
void HLEDMATRIX_voidSpeedDown(void){
	if(u8SpeedNumber < 30 ){
			u8SpeedNumber+=3;
		}
}
