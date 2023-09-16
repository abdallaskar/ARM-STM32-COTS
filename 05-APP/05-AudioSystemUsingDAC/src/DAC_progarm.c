
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"

#include  "RCC_interface.h"
#include  "STK_interface.h"
#include  "GPIO_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"
#include "DAC_private.h"



volatile u16 u16iterator=0;
volatile u8* Ptru8Data;
volatile u16 u16length=0;

void DAC_voidInit(u8* Copy_Ptru8Data,u16 Copy_u16length){
	RCC_voidInitSystemClock();
	MSTK_voidInit();
	
	#if   DAC_PORT == PORTA
		RCC_voidEnableClock(RCC_APB2,RCC_IOPA);
	#elif DAC_PORT == PORTB
		RCC_voidEnableClock(RCC_APB2,RCC_IOPB);
	#endif 
	
	 Ptru8Data = Copy_Ptru8Data;
	 u16length = Copy_u16length;
	
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT0,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT1,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT2,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT3,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT4,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT5,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT6,OUTPUT_2MZ_PP);
	GPIO_voidSetPinDirecation(DAC_PORT,DAC_BIT7,OUTPUT_2MZ_PP);
	
}
void DAC_voidOutDACValue(u16 Copy_u16Frequencey){
	
	u16 Local_u16FrameTimer = 1000000 / Copy_u16Frequencey ;
	
	MSTK_voidSetIntervalPeriodic(Local_u16FrameTimer,DAC_voidOutDACFrame);
}


static void DAC_voidOutDACFrame(void)
{
	#if DAC_PORT == PORTA_Frist_Half
		GPIO_voidSetPortValue(DAC_PORT,Ptru8Data[u16iterator]);
	#elif DAC_PORT == PROTA_Second_Half
		u16 u16_value = ((u16)audio_raw[u16iterator]) << 8;
		GPIO_voidSetPortValue(DAC_PORT,u16_value);		
	#elif DAC_PORT == PROTB_Second_Half
		u16 u16_value = ((u16)audio_raw[u16iterator]) << 8;
		GPIO_voidSetPortValue(DAC_PORT,u16_value);		
	#endif
	
	u16iterator++;
	if(u16iterator==u16length)
	{
	   u16iterator=0;
	}

}
