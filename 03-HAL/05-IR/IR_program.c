/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 13 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Layer       : HAL	 										   */
/* Description : IR Sensor and remot control  				       */
/*******************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"

volatile u32 u32Frame[50] = {0};
volatile u8  u8Counter = 0;
volatile u8  u8StartFalg = 0;
volatile u8  u8ButtonNumber = 0;
volatile u8  u8ButtonPresed =0;

// Initlization IR pin as input floating 
void HIR_voidInit(void)
{
	GPIO_voidSetPinDiraction(IR_PIN,INPUTFLOATING);
}

u8 u8GetButtonNumber(void)
{
	return u8ButtonNumber;
}



// Return number of button 
void voidTakeAcation(void){
	u8ButtonNumber = 0;
	if( (u32Frame[0] >= 1000) && (u32Frame[0] <= 1400)  )
	{
		for(u8 i = 0 ; i < 8 ; i++)
		{
			if( (u32Frame[i+17] >= 2000) && (u32Frame[i+17]<= 2300))
			{
				SET_BIT(u8ButtonNumber,i);
			}
			else
			{
				CLR_BIT(u8ButtonNumber,i);
			}
		}
		u8ButtonPresed = 1;			
	}
	else
	{
		// corrpted frame 
	}
	u32Frame[0]=0;
	u8StartFalg = 0;
	u8Counter  = 0;
}

void voidGetFrame()
{
	
	if(u8StartFalg == 0)
	{
		u8ButtonPresed = 0 ;
		MSTK_voidSetIntervalSingle(1000000,voidTakeAcation);
		u8StartFalg = 1;
	}
	else
	{

		u32Frame[u8Counter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAcation);
		u8Counter++;
	}
}