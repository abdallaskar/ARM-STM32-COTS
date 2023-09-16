/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 29 July 2023						 			   */
/* Verstion    : 1.1 V	 										   */
/* Description : STK										       */
/*******************************************************************/
#ifndef     STK_PRIVATE_H
#define 	STK_PRIVATE_H


#define		BASE_ADDRESS        0xE000E010


#define 	STK_CTRL		*((volatile u32*)0xE000E010)
#define 	STK_LOAD		*((volatile u32*)0xE000E014)
#define 	STK_VAL			*((volatile u32*)0xE000E018)
#define 	STK_CALIB		*((volatile u32*)0xE000E01c)

#define	 	AHB_8 	  0
#define 	AHB       1



#endif
