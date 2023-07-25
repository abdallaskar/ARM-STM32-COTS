/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : STC										       */
/*******************************************************************/
#ifndef     STK_INTERFACE_H
#define 	STK_INTERFACE_H

typedef enum
{
	AHB_8 = 0,
	AHB
} CLOCK_SOURCE ;



// Enable system tick
void MSTK_voidEnableSystemTick(void);
// Disable system tick
void MSTK_voidDisableSystemTick(void);

// Enable system tick interrupt flag
void MSTK_voidEnableSTKIntterupt(void);
// Disable system tick interrupt flag
void MSTK_voidDisableSTKIntterupt(void);

// Chose source of system tick
void MSTK_voidClockSource(CLOCK_SOURCE   copy_ClockSource);
// Load value in Timer Register
void MSTK_voidloadValue(u32 copy_u32CounterValue);

// Read flag to clear it
u8 MSTK_voidReadFlag(void);






#endif
