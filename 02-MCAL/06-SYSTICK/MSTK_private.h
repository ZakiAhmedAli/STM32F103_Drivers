/******************************************************************/
/*	Auther	    : zaki ahmed hamed								  */
/*  Date 	    : 26 August 2020								  */
/*  Description : MSTK_private.h [Systick register decription] 	  */
/*  Version     : V01											  */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H


typedef struct
{
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;

}STK_type;

#define SYSTICK	((volatile STK_type*) 0xE000E010)


//SysTick control and status register (STK_CTRL) BITS 
#define COUNTFLAG	16

#define ENABLE		0

#define TICKINT		1

#define CLKSOURCE	2



#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1








#endif //MSTK_PRIVATE_H
