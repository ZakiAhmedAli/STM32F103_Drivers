/************************************************************************/
/*	File name	: RTOS_private.h								  		*/
/*	Auther	    : zaki ahmed hamed								        */
/*  Date 	    : 7 september 2020								  	    */
/*  Description : this file contain private function and private macros	*/
/*  Version     : V01											   		*/
/************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	


#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

/******** struct contain TASK parameters *****/
typedef struct
{
	u16 Periodicity;			;
	void (*TaskHander)(void);
	u16 FirstDelay			;
	u8 State				;
	
}TASK_TCB;


/********************************************************
*	Description	: TASK States							*
********************************************************/
#define TASK_READY       0
#define TASK_SUSPEND     1

/************************************************************/
/*	Function Name	: RTOS_VidSchedular						*/
/*  Description 	: private function used to manage tasks	*/
/*  Input	     	: void									*/
/*  Return			: void									*/
/************************************************************/

void RTOS_VoidSchedular( void );








#endif
