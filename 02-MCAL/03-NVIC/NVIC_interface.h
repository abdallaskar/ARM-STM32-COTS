/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 25 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : NVIC										       */
/*******************************************************************/
#ifndef     NVIC_INTERFACE_H
#define 	NVIC_INTERFACE_H

//Enable External Interrupt 
void MNVIC_voidEnableInterrupt(u8 copy_u8InttNumber);
// Disable External Interrupt 
void MNVIC_voidDisableInterrupt(u8 copy_u8InttNumber);

// Set pending flag
void MNVIC_voidSetPendingFlag(u8 copy_u8InttNumber);
// Clear pending flag
void MNVIC_voidClearPendingFlag(u8 copy_u8InttNumber);

// Get active Flag
u8 MNVIC_u8GetActivFlag(u8 copy_u8InttNumber);

// set group priority and sup priority
void MNVIC_voidSetPriority(s8 copy_s8InttNumber,u8 copy_u8GroupPriority,u8 copy_u8SupPriority);



        
#endif
