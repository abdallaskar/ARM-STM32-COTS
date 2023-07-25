/*******************************************************************/
/* Author     : Abdalla Skar    				   */
/* Data		  : 24 July 2023				   */
/* Version    : 1.0 V						   */
/* Description: Led Animations  				   */
/*******************************************************************/
/*******************************************************************/
/* Description : Led Animations  				   */
/* 1- Shift left/right (ping-pong) led to led --> 200 ms, 4 times  */
/* 2- In/out (Fat7y yawarda) led ot led --> 200 ms, 4 times	   */
/* 3- Flashing flash every -- > 500 ms , 8 times 	           */
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"

void Flashing(void);
void InOut(void);

static u8 u8ModeCounter=0;
static u8 u8PingpinNumber = 0;
static u8 u8PingTemp=7;
static u8 u8MoveLeft =3;
static u8 u8MoveRight =4;
static u8 u8FlashFalg=1;
static bool increasing = True ;

int main(void)
{		// Initialization system clock
 	RCC_voidInitSystemClock();
	 // Enable clock on GPIOA
	RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	// Enable system timer
	MSTK_voidEnableSystemTick();
	MSTK_voidEnableSTKIntterupt();
	MSTK_voidClockSource(0);
	MSTK_voidloadValue(150000);

	// Configure 8 pins on portA as output push pull
	GPIO_voidSetPinDirecation(PORTA,PIN0,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN1,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN2,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN3,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN4,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN5,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN6,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(PORTA,PIN7,OUTPUT_2MZ_PP);

	GPIO_voidSetPinValue(PORTA,PIN0,HIGH);


	while(1)
	{
		InOut();
		Flashing();

	}
	return 0;
}

void InOut(void)
{
	if (u8ModeCounter >=4 && u8ModeCounter<8 )
	{
		if (increasing)
		{
			// Increment counter and open LED if counter is 8
			GPIO_voidSetPinValue(PORTA,u8MoveLeft,HIGH);
			GPIO_voidSetPinValue(PORTA,u8MoveRight,HIGH);
			if (u8MoveLeft == 8)
			{
				increasing = False;
			}
		}
		else
		{
			// Decrement counter and close LED if counter is 0
			GPIO_voidSetPinValue(PORTA,u8MoveLeft,LOW);
			GPIO_voidSetPinValue(PORTA,u8MoveRight,LOW);
			if (u8MoveLeft == 3)
			{
				increasing = True;
				u8ModeCounter++;
			}
	    }
	}
}

void Flashing(void)
{
	if(u8ModeCounter >= 8 )
	{
		if (u8FlashFalg==1)
		{
			//on led
			GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN1,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN2,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN3,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN4,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN5,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN6,HIGH);
			GPIO_voidSetPinValue(PORTA,PIN7,HIGH);

		}
		else
		{
			GPIO_voidSetPinValue(PORTA,PIN0,LOW);
			GPIO_voidSetPinValue(PORTA,PIN1,LOW);
			GPIO_voidSetPinValue(PORTA,PIN2,LOW);
			GPIO_voidSetPinValue(PORTA,PIN3,LOW);
			GPIO_voidSetPinValue(PORTA,PIN4,LOW);
			GPIO_voidSetPinValue(PORTA,PIN5,LOW);
			GPIO_voidSetPinValue(PORTA,PIN6,LOW);
			GPIO_voidSetPinValue(PORTA,PIN7,LOW);
		}
	}
}

void SysTick_Handler(void)
{
	 MSTK_voidReadFlag();
     if(u8ModeCounter < 4 )
     {
    	 if(u8PingpinNumber < 8)
		 {
			GPIO_voidSetPinValue(PORTA,u8PingpinNumber,LOW);
			u8PingpinNumber++;
			GPIO_voidSetPinValue(PORTA,u8PingpinNumber,HIGH);
		 }
		 else if (u8PingpinNumber == 8 )
		 {


			 GPIO_voidSetPinValue(PORTA,u8PingTemp,LOW);
			 u8PingTemp--;
			 GPIO_voidSetPinValue(PORTA,u8PingTemp,HIGH);
			 if(u8PingTemp==0)
			 {
				 u8PingpinNumber=0;
				 u8PingTemp=7;
				 u8ModeCounter++;
			 }
			 if (u8ModeCounter==4)
			 {
				 GPIO_voidSetPinValue(PORTA,PIN0,LOW);
			 }
		 }

    	 MSTK_voidloadValue(150000);
     }
     else if (u8ModeCounter >=4 && u8ModeCounter < 8)
     {
		 if (increasing)
		 {
			 // Increment counter and open LED if counter is 8
			u8MoveLeft++;
			u8MoveRight--;
		  }
		  else
		  {
			 // Decrement counter and close LED if counter is 0
			 u8MoveLeft--;
			 u8MoveRight++;
		  }
		 if(u8ModeCounter==8)
		 {
			 MSTK_voidloadValue(450000);
		 }
		 else
		 {
			 MSTK_voidloadValue(150000);
		 }

     }
     else if(u8ModeCounter >= 8)
     {
    	 u8FlashFalg ^=1;
    	 u8ModeCounter++;
    	 MSTK_voidloadValue(450000);
    	 if(u8ModeCounter==16)
    	 {
    		 u8ModeCounter=0;
    		 GPIO_voidSetPinValue(PORTA,PIN0,HIGH);
    		 MSTK_voidloadValue(150000);
    	 }

     }
     else
     {

     }

}
