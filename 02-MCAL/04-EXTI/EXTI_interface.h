/*******************************************************************/
/* Author      : Abdalla Skar   								   */
/* Data		   : 29 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : EXTI										       */
/*******************************************************************/
#ifndef     EXTI_INTERFACE_H
#define 	EXTI_INTERFACE_H


// Initialization EXTI depend on configurations
void MEXTI_voidInit(void);
// Change snese mode and line number on run time
void MEXTI_voidSetSignalLatch(u8 Copy_u8SenseMode,u8 Copy_u8LineNumber);
// Enable any line on EXTI
void MEXTI_voidEnableEXTI (u8 copy_u8Line);
// Disable any line on EXTI
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
// Make software Interrupt
void MEXTI_voidSwInterrupt(u8 copy_u8Line);
// Set Call back funcation
void MEXTI_voidSetCallBack(void (*Copy_Fptr)(void));
// Set line mode 
void MEXTI_voidSetLineMode(u8 copy_u8Line , u8 copy_u8Mode);








#endif 
