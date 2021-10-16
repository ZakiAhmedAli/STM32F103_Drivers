#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"NVIC_interface.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
	}
	else
	{/*ERROR STATUS*/}
}



void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber-=32;
		
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
	}
	else
	{/*ERROR STATUS*/}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
		
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{/*ERROR STATUS*/}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
		
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ICPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{/*ERROR STATUS*/}
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 LOC_u8Result=0;
		
	if(Copy_u8IntNumber < 32)
	{
		LOC_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber-=32;
		LOC_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	else
	{/*ERROR STATUS*/}
}




/*
void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority ,u8 Copy_u8SubPriority)
{
	u8 LOC_u8Priority= Copy_u8SubPriority | (Copy_u8GroupPriority <<((NO_OF_SUB_GROUP - 0x05FA0300)/256));
	
	if(Copy_s8IntID)//core peripheral
	{
		
	}
							
	else if(Copy_s8IntID >= 0 )	//External peripheral
	{
		NVIC_IPR[Copy_s8IntID] = (LOC_u8Priority << 4);
	}
		SCB_AIRCR = NO_OF_SUB_GROUP;
}
*/


void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx,u8 Copy_u8Priority)
{
	if(Copy_u8Priority < 60)
	{
		NVIC_IPR[Copy_PeripheralIdx]=Copy_u8Priority;
	}
	else
	{
		//Error_State
	}
}

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_DISTRIBUTION;
}

