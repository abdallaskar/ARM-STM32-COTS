/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : EXTI										       */
/*******************************************************************/
#ifndef     EXTI_PRIVATE_H
#define 	EXTI_PRIVATE_H


// define EXTI register 


typedef struct 
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;
	
} EXTI_type ;
// pointer to struct register 
#define		EXTI		((volatile EXTI_type*)0x40010400)  


// define all lines 
#define    LINE0		0
#define    LINE1		1
#define    LINE2		2
#define    LINE3		3		
#define    LINE4		4
#define    LINE5		5
#define    LINE6		6
#define    LINE7		7
#define    LINE8		8


// define all modes 
#define    FALLING			0
#define    RISING			1
#define    ENY_CHANGE		2


#endif