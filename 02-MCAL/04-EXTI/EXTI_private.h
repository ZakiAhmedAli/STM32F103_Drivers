/*
*  Auther	   : zaki ahmed hamed								  
*  Date 	   : 3 Sep 2020								  
*  Description : EXTI_private file include EXTI register map
*  Version     : V02											  
*/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/****************** EXTI Register description*******************/
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_type;

#define EXTI	 ((volatile EXTI_type*)(0x40010400))


#endif //EXTI_PRIVATE_H
