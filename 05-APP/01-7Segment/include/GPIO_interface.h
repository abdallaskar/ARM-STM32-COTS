/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 28 Dec 2022									   */
/* Verstion    : 1.0 V	 										   */
/* Description : GPIO										       */
/*******************************************************************/

#ifndef   GPIO_INTERFACE_H
#define   GPIO_INTERFACE_H

// Set pin mode and configurations
void GPIO_voidSetPinDirecation(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode);
// Set pin Value
void GPIO_voidSetPinValue     (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Value);
// Get pin Value
u8   GPIO_u8GetPinValue       (u8 copy_u8Port ,u8 copy_u8Pin);
// Set port value
void GPIO_voidSetPortValue(u8 copy_u8Port,u16 copy_u8Value);
// Lock pin direaction and configurations 
void GPIO_voidLockPin(u8 copy_u8Port ,u8 copy_u8Pin);

// Toggle pin value
void GPIO_voidTogglePinValue(u8 copy_u8Port ,u8 copy_u8Pin);



/* ports names */
#define     PORTA           0
#define     PORTB           1
#define     PORTC		    2

/* pins name*/
#define     PIN0      0
#define     PIN1      1
#define     PIN2      2
#define     PIN3      3
#define     PIN4      4
#define     PIN5      5
#define     PIN6      6
#define     PIN7      7
#define     PIN8      8
#define     PIN9      9
#define     PIN10     10
#define     PIN11     11
#define     PIN12     12  
#define     PIN13     13
#define     PIN14     14
#define     PIN15     15


/*output values */
#define   	LOW			    0
#define   	HIGH			1
  
/* difference modes */
/*input modes */
#define   	INPUT_ANALOG             0b0000
#define   	INPUT_FLOATING           0b0100
#define   	INPUT_PULL_UP_DOWN       0b1000

/*output modes */
// speed 2 MZ
#define     OUTPUT_2MZ_PP               0b0010
#define     OUTPUT_2MZ_OD				0b0110
#define     OUTPUT_2MZ_AFPP				0b1010
#define     OUTPUT_2MZ_AFOD				0b1110
// speed 10 MZ
#define     OUTPUT_10MZ_PP				0b0001
#define     OUTPUT_10MZ_OD				0b0101
#define     OUTPUT_10MZ_AFPP			0b1001
#define     OUTPUT_10MZ_AFOD			0b1101
// speed 50 MZ
#define     OUTPUT_50MZ_PP				0b0011
#define     OUTPUT_50MZ_OD				0b0111
#define     OUTPUT_50MZ_AFPP			0b1011
#define     OUTPUT_50MZ_AFOD			0b1111


#endif
