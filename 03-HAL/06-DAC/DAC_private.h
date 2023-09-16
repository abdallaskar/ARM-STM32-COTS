/*******************************************************************/
/* Author      : Abdalla Skar 								       */
/* Data		   : 12 September 2023						 		   */
/* Version     : 1.0 V	 										   */
/* Layer       : HAL	 										   */
/* Description : DAC Driver for Dagital to Analog Converter        */
/*******************************************************************/

#ifndef            DAC_PRIVATE_H
#define  		   DAC_PRIVATE_H



static void DAC_voidOutDACFrame(void);

#define   PORTA_Frist_Half               0
#define   PORTA_Second_Half              1
#define   PROTB_Second_Half 			 2

#define   PORTA			0
#define   PORTB			1


/* DAC PORT Configartion */
#if   DAC_PORT_Config == PORTA_Frist_Half
	#define   DAC_PORT     PORTA
#elif DAC_PORT_Config == PORTA_Second_Half
	#define   DAC_PORT     PORTA
#elif DAC_PORT_Config == PROTB_Second_Half
	#define   DAC_PORT     PORTB
#endif
	
	/* DAC PIN Configartion */
#if DAC_PORT_Config == PORTA_Frist_Half

	#define   DAC_BIT0        PIN0
	#define   DAC_BIT1        PIN1
	#define   DAC_BIT2        PIN2
	#define   DAC_BIT3        PIN3
	#define   DAC_BIT4        PIN4
	#define   DAC_BIT5        PIN5
	#define   DAC_BIT6        PIN6
	#define   DAC_BIT7        PIN7

#elif DAC_PORT_Config == PORTA_Second_Half

	#define   DAC_BIT0        PIN8
	#define   DAC_BIT1        PIN9
	#define   DAC_BIT2        PIN10
	#define   DAC_BIT3        PIN11
	#define   DAC_BIT4        PIN12
	#define   DAC_BIT5        PIN13
	#define   DAC_BIT6        PIN14
	#define   DAC_BIT7        PIN15
	
#elif DAC_PORT_Config == PROTB_Second_Half
	#define   DAC_BIT0        PIN8
	#define   DAC_BIT1        PIN9
	#define   DAC_BIT2        PIN10
	#define   DAC_BIT3        PIN11
	#define   DAC_BIT4        PIN12
	#define   DAC_BIT5        PIN13
	#define   DAC_BIT6        PIN14
	#define   DAC_BIT7        PIN15
#endif






#endif