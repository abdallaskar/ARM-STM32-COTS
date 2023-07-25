/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 10 FEB 2023						 			   */
/* Verstion    : 1.0 V	 										   */
/* Description : STC										       */
/*******************************************************************/
#ifndef     STC_PRIVATE_H
#define 	STC_PRIVATE_H


#define		BASE_ADDRESS        0xE000E010


#define 	STK_CTRL		*((volatile u32*)0xE000E010)
#define 	STK_LOAD		*((volatile u32*)0xE000E014)
#define 	STK_VAL			*((volatile u32*)0xE000E018)
#define 	STK_CALIB		*((volatile u32*)0xE000E01c)




#endif
