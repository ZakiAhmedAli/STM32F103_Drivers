/************************************************************************/
/*	File name	: RTOS_interface.h								  		*/
/*	Auther	    : zaki ahmed hamed								        */
/*  Date 	    : 7 september 2020								  	    */
/*  Description : this file contain public function and public macros	*/
/*  Version     : V01											   		*/
/************************************************************************/


/*******************************************************************************
*     Description : Guard to Protect this file from include more than one time *
*******************************************************************************/	
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

/*********************************************
*     Description : Functions Prototypes	 *
*********************************************/

/*
	Function Name        : RTOS_VoidCreateTask
	Function Returns     : void
	Function Arguments   : u8 Copy_u8Priority , u16 Copy_Periodicity, void (*Copy_ptrTask)(void) , u16 Copy_u16FirstDelay
	Function Description : function used to create Tasks 
*/
void RTOS_VoidCreateTask(u8 Copy_u8Priority , u16 Copy_Periodicity, void (*Copy_ptrTask)(void) , u16 Copy_u16FirstDelay);

/*
	Function Name        : RTOS_VoidStart
	Function Returns     : void
	Function Arguments   : void
	Function Description : function used to start tasks activity
*/
void RTOS_VoidStart( void );

/*
	Function Name        : RTOS_VoidSuspendTask
	Function Returns     : void
	Function Arguments   : u8 Copy_u8TaskID
	Function Description : function used to change states of tasks
*/

void RTOS_VoidSuspendTask ( u8 Copy_u8TaskID );

/*
	Function Name        : RTOS_VoidResumeTask
	Function Returns     : void
	Function Arguments   : u8 Copy_u8TaskID
	Function Description : function used to resume tasks
*/
void RTOS_VoidResumeTask  ( u8 Copy_u8TaskID );

/*
	Function Name        : RTOS_VoidDeleteTask
	Function Returns     : void
	Function Arguments   : u8 Copy_u8TaskID
	Function Description : function used to Delete tasks
*/
void RTOS_VoidDeleteTask  ( u8 Copy_u8TaskID );




#endif //RTOS_INTERFACE_H_