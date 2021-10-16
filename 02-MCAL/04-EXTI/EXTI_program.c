/*
*  Auther	   : zaki ahmed hamed								  
*  Date 	   : 3 Sep 2020								  
*  Description : EXTI_program.c file include EXTI driver implement for STM32 
*  Version     : V02											  
*  Email	   : zaki82204@hmail.com
*/


#include"STD_TYPES.h"	/*include Standard types library*/
#include"BIT_MATH.h"	/*bit manipulation file*/


#include"EXTI_init.h"
#include"EXTI_config.h"
#include"EXTI_private.h"

void (*EXTI_CALLBACK)(void);


void MEXTI_voidInit(LineNumber	NUM , TriggerMode Mode)
{
	switch(Mode)
	{
		case RISING    : 	SET_BIT( EXTI -> RTSR , NUM);

		break;

		case FALING    : 	SET_BIT( EXTI -> FTSR , NUM);

		break;
		
		case ON_CHANGE :	SET_BIT( EXTI -> RTSR , NUM);
	                       
                            SET_BIT( EXTI -> FTSR , NUM);
		break;
		
		default:/*Error*/break;
						   
	}
	
	/**/
	SET_BIT(EXTI->IMR , NUM);
	
}

//Enable line number
void MEXTI_voidEnableEXTI(LineNumber	NUM)
{
	SET_BIT(EXTI -> IMR , NUM);
}

void MEXTI_voidDisableEXTI(LineNumber NUM)
{
	CLR_BIT(EXTI -> IMR , NUM);
}

void MEXTI_voidSwTrigger(LineNumber	NUM)
{
	
	SET_BIT(EXTI -> SWIER , NUM);
	CLR_BIT(EXTI -> PR , NUM);
}

/*void EXT_voidSetSignalLatch(LineNumber	NUM , TriggerMode Mode)
{
	switch(Mode)
	{
		case RISING    : 	SET_BIT( EXTI_type -> RTSR , NUM);	

		break;

		case FALING    : 	SET_BIT( EXTI_type -> FTSR , NUM);	

		break;
		
		case ON_CHANGE :	SET_BIT( EXTI_type -> RTSR , NUM);	
	                       
                            SET_BIT( EXTI_type -> FTSR , NUM);	
		break;
		
		default:  break;
						   
	}
}
*/


void MEXTI_voidSetCallBack(void (*Copy_Ptr)(void))
{
	EXTI_CALLBACK = Copy_Ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI_CALLBACK();
	/*clear pending Bit */
	CLR_BIT(EXTI -> PR , 0);
}

