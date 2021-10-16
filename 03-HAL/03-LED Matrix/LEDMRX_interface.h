/****************************************************************************/
/*	Auther	    : zaki ahmed hamed								  	   		*/
/*  Date 	    : 28 August 2020								  	   		*/
/*  Description : LEDMRX_interface.h file contain public functios and macros*/
/*  Version     : V01											       		*/
/****************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

/******************************************************************************/
/* Description : this functions is used to initialize LED Matrix Pin Direction*/
/* Input 	   : void														  */
/* Return      : void														  */
/******************************************************************************/
void HLEDMRX_voidInit(void);

/****************************************************************************************/
/* Description : this functions is used to Display Rows and Coumns values on LED matrix */
/* Input 	   : u8 * arr														  			*/
/* Return      : void														  			*/
/****************************************************************************************/
void LDM_VidEnable ( u8 * arr );



#endif //LEDMRX_INTERFACE_H
