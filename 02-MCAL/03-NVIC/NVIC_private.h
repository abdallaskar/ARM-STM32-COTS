/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 25 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : NVIC										       */
/*******************************************************************/
#ifndef 	NVIC_PRIVATE_H
#define 	NVIC_PRIVATE_H


#define     BASE_ADDRESS     0xE000E100

// Enable External Interrupt from 0 to 64
#define    NVIC_ISER0		*((volatile u32*) 0xE000E100 )
#define    NVIC_ISER1		*((volatile u32*) 0xE000E104 )
// Disable External Interrupt from 0 to 64 
#define    NVIC_ICER0		*((volatile u32*) 0xE000E180 )
#define    NVIC_ICER1		*((volatile u32*) 0xE000E184 )
// Set pending flag 
#define    NVIC_ISPR0		*((volatile u32*) 0xE000E200 )
#define    NVIC_ISPR1		*((volatile u32*) 0xE000E204 )
// Clear pending flag
#define    NVIC_ICPR0		*((volatile u32*) 0xE000E280 )
#define    NVIC_ICPR1		*((volatile u32*) 0xE000E284 )
// Read active flag
#define    NVIC_IABR0		*((volatile u32*) 0xE000E300 )
#define    NVIC_IABR1		*((volatile u32*) 0xE000E304 )

#define    NVIC_IPR          ((volatile u8*)  0xE000E400 )

#define	   SCB_AIRCR		*((volatile u32*) 0xE000ED0C )


#define    GROUP4_SUB0       0x05FA0300
#define    GROUP3_SUB1       0x05FA0400
#define    GROUP2_SUB2       0x05FA0500
#define    GROUP1_SUB3   	 0x05FA0600
#define    GROUP0_SUB4		 0x05FA0700



#endif
