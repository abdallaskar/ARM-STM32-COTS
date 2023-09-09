/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 4 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/*******************************************************************/
/* Description : LEDMATRIX	Display 						       */
/* This Project display My name and rotate it form right to left   */
/* for ever.                                                       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

#include "LEDMATRIX_interface.h"

/*This Function get sub array from main array */
void voidSubArray(u8* Copy_Pu8MainArry,u8 Copy_u8LengthMainArry,u8* Copy_Pu8SubArry,u8 Copy_u8Start,u8 Copy_u8End);



int main (){
	 // Array keep values of Character do you display it
	  u8 mainName[]={LEDMATRIX_A,LEDMATRIX_B,LEDMATRIX_D,LEDMATRIX_A,LEDMATRIX_L,LEDMATRIX_L,LEDMATRIX_A,LEDMATRIX_S,
			  LEDMATRIX_K,LEDMATRIX_A,LEDMATRIX_R};
	  u8 Local_u8LengthMainName= sizeof(mainName)/sizeof(mainName[0]);

	  // Initialize System clock and Enable Clock on PORTA and PORTB
	  RCC_voidInitSystemClock();
	  RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	  RCC_voidEnableClock(RCC_APB2,RCC_IOPB);

	  // Initialize LEDMARTRIX PINs as output
	  HLEDMATRIX_voidInit();

	while(1)
	{

		for(u8 i = 0; i<Local_u8LengthMainName;i++)
		{
			u8 Local_u8Charcter[8]={0};
			voidSubArray(mainName,Local_u8LengthMainName,Local_u8Charcter,i,(i+8)%(Local_u8LengthMainName+1));
			HLEDMATRIX_voidDisplay(Local_u8Charcter);
		}

	}

	return 0;
}

void voidSubArray(u8* Copy_Pu8MainArry,u8 Copy_u8LengthMainArry,u8* Copy_Pu8SubArry,u8 Copy_u8Start,u8 Copy_u8End)
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
