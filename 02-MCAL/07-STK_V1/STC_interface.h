/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : STC										       */
/*******************************************************************/
#ifndef     STC_INTERFACE_H
#define 	STC_INTERFACE_H

typedef enum
{
	AHB_8 = 0,
	AHB
} CLOCK_SOURCE ;



// Enable system tick
void MSTC_voidEnableSTC(void);
// Disable system tick
void MSTC_voidDisableSTC(void);

// Enable system tick interrupt flag
void MSTC_voidEnableSTCINT(void);
// Disable system tick interrupt flag
void MSTC_voidDisableSTCINT(void);

// Chose source of system tick
void MSTC_voidClockSource(CLOCK_SOURCE   copy_ClockSource);
// Load value in Timer Register
void MSTC_voidloadValue(u32 copy_u32CounterValue);

// Read flag to clear it
u8 MSTC_voidReadFlag(void);






#endif
