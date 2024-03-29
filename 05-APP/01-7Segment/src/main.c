/*******************************************************************/
/* Author     : Abdalla Skar    								   */
/* Data		  : 22 Jan 2023										   */
/* Version    : 1.0 V											   */
/* Description: 7Segment										   */
/*******************************************************************/
/*******************************************************************/
/* Description: 7Segment    		     						   */
/* This project print from 0 to 9 on 7Segment and do that for ever */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SEGMENT_interface.h"
#include "SEGMENT_config.h"
#include "SEGMENT_private.h"

void delay(void);

int main(){

	// Initialization system clock
	RCC_voidInitSystemClock();
	// Active clock on Input Output A
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	// Initialization 7Segment
	SEGMENT_voidInit();

	// print from 0 to 9 in super loop
	while(1){
		SEGMENT_voidPrintNumber(0);
		delay();
		SEGMENT_voidPrintNumber(1);
		delay();
		SEGMENT_voidPrintNumber(2);
		delay();
		SEGMENT_voidPrintNumber(3);
		delay();
		SEGMENT_voidPrintNumber(4);
		delay();
		SEGMENT_voidPrintNumber(5);
		delay();
		SEGMENT_voidPrintNumber(6);
		delay();
		SEGMENT_voidPrintNumber(7);
		delay();
		SEGMENT_voidPrintNumber(8);
		delay();
		SEGMENT_voidPrintNumber(9);
		delay();

	}

	return 0;
}



void delay(void){
	for (u16 i=0 ; i < 1000 ; i++){
		for (u16 j=0 ; j <1000 ; j++){
			asm("NOP");
		}
	}
}

