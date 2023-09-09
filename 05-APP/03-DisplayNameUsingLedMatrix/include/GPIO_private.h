/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 28 Dec 2022									   */
/* Verstion    : 1.0 V	 										   */
/* Description : GPIO										       */
/*******************************************************************/

#ifndef   GPIO_PRIVATE_H
#define   GPIO_PRIVATE_H

/*Define base address for GPIOA ,GPIOB and GPIOC*/
#define   GPIOA_BASE_ADDRESS            0x40010800
#define   GPIOB_BASE_ADDRESS            0x40010c00
#define   GPIOC_BASE_ADDRESS            0x40011000


/*Register Definition GPIOA*/

#define    GPIOA_CRL             *((volatile u32*)(GPIOA_BASE_ADDRESS +0x00)) 
#define    GPIOA_CRH             *((volatile u32*)(GPIOA_BASE_ADDRESS +0x04))
#define    GPIOA_IDR             *((volatile u32*)(GPIOA_BASE_ADDRESS +0x08))
#define    GPIOA_ODR	         *((volatile u32*)(GPIOA_BASE_ADDRESS +0x0c))
#define    GPIOA_BSRR            *((volatile u32*)(GPIOA_BASE_ADDRESS +0x10))
#define    GPIOA_BRR             *((volatile u32*)(GPIOA_BASE_ADDRESS +0x14))
#define    GPIOA_LCKR            *((volatile u32*)(GPIOA_BASE_ADDRESS +0x18))

/*Register Definition GPIOB*/

#define    GPIOB_CRL             *((volatile u32*)(GPIOB_BASE_ADDRESS +0x00)) 
#define    GPIOB_CRH             *((volatile u32*)(GPIOB_BASE_ADDRESS +0x04))
#define    GPIOB_IDR             *((volatile u32*)(GPIOB_BASE_ADDRESS +0x08))
#define    GPIOB_ODR	         *((volatile u32*)(GPIOB_BASE_ADDRESS +0x0c))
#define    GPIOB_BSRR            *((volatile u32*)(GPIOB_BASE_ADDRESS +0x10))
#define    GPIOB_BRR             *((volatile u32*)(GPIOB_BASE_ADDRESS +0x14))
#define    GPIOB_LCKR            *((volatile u32*)(GPIOB_BASE_ADDRESS +0x18))

/*Register Definition GPIOC*/

#define    GPIOC_CRL             *((volatile u32*)(GPIOC_BASE_ADDRESS +0x00)) 
#define    GPIOC_CRH             *((volatile u32*)(GPIOC_BASE_ADDRESS +0x04))
#define    GPIOC_IDR             *((volatile u32*)(GPIOC_BASE_ADDRESS +0x08))
#define    GPIOC_ODR	         *((volatile u32*)(GPIOC_BASE_ADDRESS +0x0c))
#define    GPIOC_BSRR            *((volatile u32*)(GPIOC_BASE_ADDRESS +0x10))
#define    GPIOC_BRR             *((volatile u32*)(GPIOC_BASE_ADDRESS +0x14))
#define    GPIOC_LCKR            *((volatile u32*)(GPIOC_BASE_ADDRESS +0x18))





#endif 