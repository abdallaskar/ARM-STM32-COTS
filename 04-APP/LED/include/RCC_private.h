/*******************************************************************/
/* Author     : Abdalla Mahmoud 								   */
/* Data		  : 9 Dec 2022										   */
/* Version    : 1.0 V											   */
/* Descrpiton : RCC  											   */
/*******************************************************************/
#ifndef   RCC_PRIVATE_H
#define   RCC_PRIVATE_H


/*Register Definition */

#define    RCC_CR             *((volatile u32*)0x40021000) 
#define    RCC_CFGR           *((volatile u32*)0x40021004)
#define    RCC_CIR            *((volatile u32*)0x40021008)
#define    RCC_APB2RSTR 	  *((volatile u32*)0x4002100c)
#define    RCC_APB1RSTR       *((volatile u32*)0x40021010)
#define    RCC_AHBENR         *((volatile u32*)0x40021014)
#define    RCC_APB2ENR        *((volatile u32*)0x40021018)
#define    RCC_APB1ENR        *((volatile u32*)0x4002101c)
#define    RCC_BDCR           *((volatile u32*)0x40021020)
#define    RCC_CSR            *((volatile u32*)0x40021024)




/* Clock types source */
#define   RCC_HSE_CRYSTAL     0
#define   RCC_HSE_RC		  1
#define   RCC_HSI			  2
#define   RCC_PLL 			  3


/* PLL input Options  */
#define  RCC_PLL_IN_HSI_DIV_2    0
#define  RCC_PLL_IN_HSE_DIV_2    1
#define  RCC_PLL_IN_HSE          2











#endif
