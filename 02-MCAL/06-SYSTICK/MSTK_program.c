#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"MSTK_init.h"
#include "MSTK_private.h"

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void (*STK_CALLBACK)(void);



void MSTK_voidInit(CLK_Sourse Clock)
{
	switch(Clock)
	{
		case _AHB_DIV8: CLR_BIT(SYSTICK -> STK_CTRL , CLKSOURCE);  break;
		case _AHB	  : SET_BIT(SYSTICK -> STK_CTRL , CLKSOURCE); break;

	}
	
	/*   Disable SysTick interrupt 
		 Disable Systick
	*/
	CLR_BIT(SYSTICK -> STK_CTRL , TICKINT);
	//CLR_BIT(SYSTICK -> STK_CTRL , ENABLE);
	MSTK_voidStopInterval();
	
}//end of function

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{	
	/*load value to register*/
	SYSTICK->STK_LOAD = Copy_u32Ticks;
	/*Enables the counter. When ENABLE is set to 1, the counter loads the RELOAD value from the
	LOAD register and then counts down. On reaching 0*/
	
	SET_BIT(SYSTICK->STK_CTRL , ENABLE);
	
	/* waiting flag =1 then loads the RELOAD value again, and begins counting.*/
	while( !GET_BIT(SYSTICK -> STK_CTRL ,COUNTFLAG) );
	
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
	
}//end of function


void MSTK_voidDelayMS(u32 copy_u32Ticks)
{
	MSTK_voidSetBusyWait(copy_u32Ticks*1000);
	/*SET_BIT(SYSTICK -> STK_CTRL , ENABLE);
	copy_u32Ticks *=1000;  //convert from MS to microsecond
	SYSTICK->STK_LOAD = copy_u32Ticks;

	while( !GET_BIT(SYSTICK -> STK_CTRL ,COUNTFLAG) );

	SYSTICK->STK_VAL=0X00000000;
*/
}



void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(SYSTICK -> STK_CTRL , TICKINT);
	/* Stop Timer */
	CLR_BIT(SYSTICK -> STK_CTRL , ENABLE);
	SYSTICK->STK_LOAD=0;
	SYSTICK->STK_VAL=0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	u32 LOC_u32Value=0;
	
	LOC_u32Value = (SYSTICK->STK_LOAD) - (SYSTICK->STK_VAL);
	
	return LOC_u32Value;
	
}

u32  MSTK_u32GetRemainingTime(void)
{
	return (SYSTICK->STK_VAL);
}
//
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_Ptr)(void) )
{	
	/*load ticks in load register*/
	 SYSTICK->STK_LOAD = Copy_u32Ticks;

	 /*Start timer*/
	 SET_BIT(SYSTICK->STK_CTRL , ENABLE);
	 /*save CallBack*/
	 STK_CALLBACK = Copy_Ptr;
	
	MSTK_u8ModeOfInterval =MSTK_SINGLE_INTERVAL ;
	
	/*when counter reaching to 0 generate interrupt*/
	SET_BIT(SYSTICK->STK_CTRL , TICKINT);
	
}  

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_Ptr)(void))
{
		/*load ticks in load register*/
	 SYSTICK->STK_LOAD = Copy_u32Ticks;

	 /*Start timer*/
	 SET_BIT(SYSTICK->STK_CTRL , ENABLE);
	 /*save CallBack*/
	 STK_CALLBACK = Copy_Ptr;
	
	 MSTK_u8ModeOfInterval =MSTK_PERIOD_INTERVAL;
	 
	/*when counter reaching to 0 generate interrupt*/
	SET_BIT(SYSTICK->STK_CTRL , TICKINT);
	
}





void Systick_Handler(void)
{
	//u8 LOC_u8Temporary;
	
	if(MSTK_u8ModeOfInterval==MSTK_SINGLE_INTERVAL)
	{
			CLR_BIT(SYSTICK -> STK_CTRL , TICKINT);
			CLR_BIT(SYSTICK -> STK_CTRL , ENABLE);
	}
	
	STK_CALLBACK();

	/* Clear interrupt flag */
	//LOC_u8Temporary = GET_BIT(SYSTICK -> STK_CTRL ,COUNTFLAG);
}
