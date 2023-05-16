/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : EXTI										       */
/*******************************************************************/
#ifndef     EXTI_INTERFACE_H
#define 	EXTI_INTERFACE_H


// Initialization EXTI depend on configurations
void MEXTI_voidInit(void);
// Enable any line on EXTI
void MEXTI_voidEnableEXTI (u8 copy_u8Line);
// Disable any line on EXTI
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
// Make software Interrupt
void MEXTI_voidSwInterrupt(u8 copy_u8Line);
// Set line mode 
void MEXTI_voidSetLineMode(u8 copy_u8Line , u8 copy_u8Mode);








#endif 