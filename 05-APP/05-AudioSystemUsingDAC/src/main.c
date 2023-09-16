/*
 * main.c
 *
 *  Created on: Sep 12, 2023
 *      Author: abdalla
 */

#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

#include "DAC_interface.h"
#include "LEDMATRIX_interface.h"

#include "file.h"

u8*  ptru8Data = audio_raw;
u16 u16DataLength = 35666;

int main (){


 	RCC_voidInitSystemClock();
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	RCC_voidEnableClock(RCC_APB2,RCC_IOPB);

	MSTK_voidInit();
	HLEDMATRIX_voidInit();


	DAC_voidInit(ptru8Data,u16DataLength);
	DAC_voidOutDACValue(8000);



	while(1){




	}

	return 0;
}
