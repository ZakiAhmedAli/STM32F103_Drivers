/******************************************************************/
/*	Auther	    : zaki ahmed									  */
/*  Date 	    : 09 August 2020								  */
/*  Description : RCC interface file[function prototypes , macros]*/
/*  Version     : V01											  */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H


#define RCC_AHP		 	0 

#define RCC_APB1	 	1

#define RCC_APB2	 	2







void RCC_voidInitSystemClock(void);

void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_PreId);

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_PreId);







#endif//_RCC_INTERFACE_H
