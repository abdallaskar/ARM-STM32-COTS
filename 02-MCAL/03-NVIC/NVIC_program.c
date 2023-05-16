/*******************************************************************/
/* Author      : Abdalla Mahmoud 								   */
/* Data		   : 25 JAN 2023									   */
/* Verstion    : 1.0 V	 										   */
/* Description : NVIC										       */
/*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


//Enable External Interrupt 
void MNVIC_voidEnableInterrupt(u8 copy_u8InttNumber)
{
	if(copy_u8InttNumber <= 31)
	{
		NVIC_ISER0 = (1 << copy_u8InttNumber);
		
	}
	else if(copy_u8InttNumber <= 59)
	{
		copy_u8InttNumber -= 32 ;
		NVIC_ISER1 = (1 << copy_u8InttNumber);
	}
	else 
	{
		//return Error
	}
	
}
//Disable External Interrupt 
void MNVIC_voidDisableInterrupt(u8 copy_u8InttNumber)
{
	if(copy_u8InttNumber <= 31)
	{
		NVIC_ICER0 = (1 << copy_u8InttNumber);
		
	}
	else if(copy_u8InttNumber <= 59)
	{
		copy_u8InttNumber -= 32 ;
		NVIC_ICER1 = (1 << copy_u8InttNumber);
	}
	else 
	{
		//return Error
	}
	
}
// Set pending flag
void MNVIC_voidSetPendingFlag(u8 copy_u8InttNumber)
{
	if(copy_u8InttNumber <= 31)
	{
		NVIC_ISPR0 = (1 << copy_u8InttNumber);
		
	}
	else if(copy_u8InttNumber <= 59)
	{
		copy_u8InttNumber -= 32 ;
		NVIC_ISPR1 = (1 << copy_u8InttNumber);
	}
	else 
	{
		//return Error
	}
	
}
// Clear pending flag
void MNVIC_voidClearPendingFlag(u8 copy_u8InttNumber)
{
	if(copy_u8InttNumber <= 31)
	{
		NVIC_ICPR0 = (1 << copy_u8InttNumber);
		
	}
	else if(copy_u8InttNumber <= 59)
	{
		copy_u8InttNumber -= 32 ;
		NVIC_ICPR0 = (1 << copy_u8InttNumber);
	}
	else
	{
		//return Error
	}
	
}
// Get active Flag
u8 MNVIC_u8GetActivFlag(u8 copy_u8InttNumber){
	u8 local_u8FlagValue = 0;
	if(copy_u8InttNumber < 32)
	{
		local_u8FlagValue = GET_BIT(NVIC_IABR0,copy_u8InttNumber);
		
	}
	else if(copy_u8InttNumber < 60)
	{
		copy_u8InttNumber -= 32 ;
		local_u8FlagValue = GET_BIT(NVIC_IABR0,copy_u8InttNumber);
	}
	else
	{
		//return Error
	}
	return local_u8FlagValue;
}

void MNVIC_voidSetPriority(s8 copy_s8InttNumber,u8 copy_u8GroupPriority,u8 copy_u8SupPriority)
{
	// group and sup priority
	SCB_AIRCR = MNVIC_GROUB_SUB_DISTIRBUTION;
	// set priority for external interrupt
	u8 local_u8Prioirity = copy_u8SupPriority | ( copy_u8GroupPriority <<((MNVIC_GROUB_SUB_DISTIRBUTION - 0x05FA0300)/0x100) );
	
	if (copy_s8InttNumber >= 0 )
	{
		NVIC_IPR[copy_s8InttNumber] =   local_u8Prioirity << 4 ;
	}		
	else
	{
		//return error
	}
	

}
