/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 3 FEB 2023							 			   */
/* Verstion    : 1.0 V	 										   */
/* Description : AFIO										       */
/*******************************************************************/
#ifndef     AFIO_PRIVATE_H
#define 	AFIO_PRIVATE_H


// define AFIO register 


typedef struct 
{
	volatile u32 EVCR ;
	volatile u32 MAPR ;
	volatile u32 EXTICR[4] ;
	volatile u32 MAPR2 ;
	
} AFIO_type ;
// pointer to struct register 
#define		AFIO		((volatile AFIO_type*)0x40010000)  


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



#endif