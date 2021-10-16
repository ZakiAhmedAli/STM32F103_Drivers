
/********************************************/
/*	File name	: RTOS_program.c			*/
/*	Auther	    : zaki ahmed hamed			*/
/*  Date 	    : 7 september 2020			*/
/*  Description : implement OS functions	*/
/*  Version     : V01						*/
/********************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"MSTK_init.h"

#include"RTOS_interface.h"
#include"RTOS_private.h"
#include"RTOS_config.h"



/*Array of struct*/
static TASK_TCB TASKS[TASK_NUMBERS] = { NULLPTR };



void RTOS_VoidCreateTask(u8 Copy_u8Priority , u16 Copy_Periodicity, void (*Copy_ptrTask)(void) , u16 Copy_u16FirstDelay)
{
	TASKS[Copy_u8Priority].Periodicity = Copy_Periodicity;
	TASKS[Copy_u8Priority].TaskHander  = Copy_ptrTask	 ;
	TASKS[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay	 ;
	TASKS[Copy_u8Priority].State	   = TASK_READY		 ;
}

void RTOS_VoidStart( void )
{
	/* initialize SystiK HSE=8MHZ -> 1000 microsecond*/
	MSTK_voidInit(_AHB_DIV8);	
	
	/*MSTK_voidSetIntervalPeriodic function call OS_schedular every 1 msec
	OS_schedular ordering Tasks */
	MSTK_voidSetIntervalPeriodic(TICK_TIME , RTOS_VoidSchedular);
}

void RTOS_VoidSuspendTask ( u8 Copy_u8TaskID )
{
	TASKS[Copy_u8TaskID].State = TASK_SUSPEND;
}

void RTOS_VoidResumeTask  ( u8 Copy_u8TaskID )
{
	TASKS[Copy_u8TaskID].State = TASK_READY;
}

void RTOS_VoidDeleteTask  ( u8 Copy_u8TaskID )
{
	TASKS[Copy_u8TaskID].TaskHander = NULLPTR;
}

void RTOS_VoidSchedular(void)
{
	u8 LOC_u8TaskCounter=0;
	
	for(LOC_u8TaskCounter=0 ; LOC_u8TaskCounter < TASK_NUMBERS; LOC_u8TaskCounter++)
	{
		if( (TASKS[LOC_u8TaskCounter].TaskHander !=NULLPTR)&& (TASKS[LOC_u8TaskCounter].State ==TASK_READY))
		{
			if(TASKS[LOC_u8TaskCounter].FirstDelay == 0)
			{
				
				TASKS[LOC_u8TaskCounter].FirstDelay = TASKS[LOC_u8TaskCounter].Periodicity-1;
				TASKS[LOC_u8TaskCounter].TaskHander();
			}
			else
			{
				TASKS[LOC_u8TaskCounter].FirstDelay--;
			}
		}
		else
		{
			/* No thing*/
		}
	}
}
