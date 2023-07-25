/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 21 JAN 2022									   */
/* Version     : 1.0 V	 										   */
/* Description : GPIO										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

// Set bin mode and congiguration 
void GPIO_voidSetPinDirecation(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode)
{
	switch (copy_u8Port)
	{
		case PORTA:
			if(copy_u8Pin < 8){
				GPIOA_CRL &= ~(0b1111 << (copy_u8Pin * 4));      // Reset value in pin place
				GPIOA_CRL |= (copy_u8Mode << (copy_u8Pin * 4));  // set value mode
				
			}else if (copy_u8Pin < 16){
				copy_u8Pin -= 8;
				GPIOA_CRH &= ~(0b1111 << (copy_u8Pin * 4));    // Reset value in pin place
				GPIOA_CRH |= (copy_u8Mode << (copy_u8Pin * 4));// set value mode
			}
		break;
		case PORTB:
			if(copy_u8Pin < 8){
				GPIOB_CRL &= ~(0b1111 << (copy_u8Pin * 4));     // Reset value in pin place
				GPIOB_CRL |= (copy_u8Mode << (copy_u8Pin * 4)); // set value mode
				
			}else if (copy_u8Pin < 16){
				copy_u8Pin -= 8;
				GPIOB_CRH &= ~(0b1111 << (copy_u8Pin * 4));     // Reset value in pin place
				GPIOB_CRH |= (copy_u8Mode << (copy_u8Pin * 4)); // set value mode
			}
		break;
		case PORTC:
			if(copy_u8Pin < 8){
				GPIOC_CRL &= ~(0b1111 << (copy_u8Pin * 4));     // Reset value in pin place
				GPIOC_CRL |= (copy_u8Mode << (copy_u8Pin * 4)); // set value mode
				
			}else if (copy_u8Pin < 16){
				copy_u8Pin -= 8;
				GPIOC_CRH &= ~(0b1111 << (copy_u8Pin * 4));     // Reset value in pin place
				GPIOC_CRH |= (copy_u8Mode << (copy_u8Pin * 4)); // set value mode
			}
		
		break;
		default:
		
		break;
	}
}

// Set bin value 
void GPIO_voidSetPinValue     (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Value)
{ 	switch(copy_u8Port)
	{
		case PORTA:
			if(copy_u8Value == 	HIGH){
				SET_BIT(GPIOA_ODR,copy_u8Pin); // Set bit in register ODR 
			}else if(copy_u8Value == 	LOW){
				CLR_BIT(GPIOA_ODR,copy_u8Pin); // Clear bit in register ODR 
			}
		break;
		case PORTB:
			if(copy_u8Value == HIGH){
				SET_BIT(GPIOB_ODR,copy_u8Pin);// Set bit in register ODR 
			}else if(copy_u8Value == LOW){
				CLR_BIT(GPIOB_ODR,copy_u8Pin); // Clear bit in register ODR 
			}
		break;
		case PORTC:
			if(copy_u8Value == 	HIGH){
				SET_BIT(GPIOC_ODR,copy_u8Pin); // Set bit in register ODR 
			}else if(copy_u8Value == 	LOW){
				CLR_BIT(GPIOC_ODR,copy_u8Pin); // Clear bit in register ODR 
			}
		
		break; 
		
		default: break;
	}
	
}

// Get bin value and return it 
u8   GPIO_u8GetPinValue       (u8 copy_u8Port ,u8 copy_u8Pin)
{	
	u8 local_u8Value = 0;    // varible to return value 
	switch(copy_u8Port)
	{
		case PORTA:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOA_IDR,copy_u8Pin); //Get bin value 
			}
		break;
		case PORTB:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOB_IDR,copy_u8Pin); //Get bin value 
			}
		break;
		case PORTC:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOC_IDR,copy_u8Pin); //Get bin value 
			}
		
		break;
		default:break;
	}
	return local_u8Value;
}
// Toggle pin value

void GPIO_voidTogglePinValue(u8 copy_u8Port ,u8 copy_u8Pin)
{
	u8 local_u8Value = 0;    // variable to return value
	switch(copy_u8Port)
	{
		case PORTA:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOA_IDR,copy_u8Pin); //Get bin value
			}
		break;
		case PORTB:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOB_IDR,copy_u8Pin); //Get bin value
			}
		break;
		case PORTC:
			if(copy_u8Pin < 16){
				local_u8Value = GET_BIT(GPIOC_IDR,copy_u8Pin); //Get bin value
			}

		break;
		default:break;
	}

	switch(copy_u8Port)
	{
		case PORTA:
			if(local_u8Value == 	LOW){
				SET_BIT(GPIOA_ODR,copy_u8Pin); // Set bit in register ODR
			}else if(local_u8Value == 	HIGH){
				CLR_BIT(GPIOA_ODR,copy_u8Pin); // Clear bit in register ODR
			}
		break;
		case PORTB:
			if(local_u8Value == LOW){
				SET_BIT(GPIOB_ODR,copy_u8Pin);// Set bit in register ODR
			}else if(local_u8Value == HIGH){
				CLR_BIT(GPIOB_ODR,copy_u8Pin); // Clear bit in register ODR
			}
		break;
		case PORTC:
			if(local_u8Value == 	LOW){
				SET_BIT(GPIOC_ODR,copy_u8Pin); // Set bit in register ODR
			}else if(local_u8Value == 	HIGH){
				CLR_BIT(GPIOC_ODR,copy_u8Pin); // Clear bit in register ODR
			}

		break;

		default: break;
	}

}

// Set port value
void GPIO_voidSetPortValue(u8 copy_u8Port,u16 copy_u8Value)
{
	switch(copy_u8Port)
	{
		case PORTA:
			GPIOA_ODR &=0x0000;
			GPIOA_ODR |=copy_u8Value;
			
		break;
		case PORTB:
			GPIOB_ODR &=0x0000;
			GPIOB_ODR |=copy_u8Value;
		break;
		case PORTC:
			GPIOC_ODR &=0x0000;
			GPIOC_ODR |=copy_u8Value;
		
		break; 
		
		default: break;
	}
}
// Lock pin direaction and configurations 
void GPIO_voidLockPin(u8 copy_u8Port ,u8 copy_u8Pin)
{
	switch(copy_u8Port){
		case PORTA :
			GPIOA_LCKR = (1 << copy_u8Pin );
		break;
		case PORTB :
			GPIOB_LCKR = (1 << copy_u8Pin );
		break;
		case PORTC :
			GPIOC_LCKR = (1 << copy_u8Pin );
		break;
		default :
			break;
		
	}
}
