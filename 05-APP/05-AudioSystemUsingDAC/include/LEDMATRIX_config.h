/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 3 August 2023						 			   */
/* Version     : 1.0 V	 										   */
/* Description : LEDMATRIX									       */
/*******************************************************************/
#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H


// Set ROWS GPIO pins in this form PORTx,PINx  Example ====> PORTA,PIN0
#define		LEDMATRIX_ROW0_PIN   PORTA,8
#define		LEDMATRIX_ROW1_PIN   PORTA,9
#define		LEDMATRIX_ROW2_PIN   PORTA,10
#define		LEDMATRIX_ROW3_PIN   PORTA,11
#define		LEDMATRIX_ROW4_PIN   PORTA,12
#define		LEDMATRIX_ROW5_PIN   PORTB,13
#define		LEDMATRIX_ROW6_PIN   PORTB,14
#define		LEDMATRIX_ROW7_PIN   PORTB,15
 

// Set Calms GPIO pins in this form PORTx,PINx  Example ====> PORTB,PIN0
#define		LEDMATRIX_COULM0_PIN   PORTB,0
#define		LEDMATRIX_COULM1_PIN   PORTB,1
#define		LEDMATRIX_COULM2_PIN   PORTB,5
#define		LEDMATRIX_COULM3_PIN   PORTB,6
#define		LEDMATRIX_COULM4_PIN   PORTB,7
#define		LEDMATRIX_COULM5_PIN   PORTB,8
#define		LEDMATRIX_COULM6_PIN   PORTB,9
#define		LEDMATRIX_COULM7_PIN   PORTB,10




#endif
