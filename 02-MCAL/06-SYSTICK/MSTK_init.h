/***********************************************************************/
/*	Auther	    : zaki ahmed hamed								  	   */
/*  Date 	    : 26 August 2020								  	   */
/*  Description : MSTK_init.h function prototypes and public macros    */
/*  Version     : V01											       */
/***********************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef MSTK_INIT_H
#define MSTK_INIT_H



typedef enum
{
	_AHB_DIV8,
	_AHB,

}CLK_Sourse;

/********************************************************************/
/*	Description : function used to generate delay in MS				*/
/*	Input		: Time in Millisecond								*/
/*	Return		: void												*/
/********************************************************************/
void STK_voidDelayMS(u32 copy_u32Ticks);


/******************************************************/
/* Description : -function used to select clock source*/
/*				 -Disable SysTick interrupt           */
/*				 -Disable Systick	                  */
/* Input 	   : clock source optios[AHB,AHB/8]       */
/* Return 	   : void 								  */
/******************************************************/

void MSTK_voidInit(CLK_Sourse Clock);


/********************************************************************/
/*	Description : Synchronous function used to count number of ticks*/
/*	Input		: number of ticks									*/
/*	Return		: void												*/
/********************************************************************/
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );


void MSTK_voidStopInterval(void);

u32  MSTK_u32GetElapsedTime(void);

u32  MSTK_u32GetRemainingTime(void);

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_Ptr)(void) );

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_Ptr)(void));



#endif //MSTK_INIT_H
