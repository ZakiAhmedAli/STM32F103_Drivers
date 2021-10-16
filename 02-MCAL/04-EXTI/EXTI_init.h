/*
*	Auther	    : zaki ahmed hamed								  
*  Date 	    : 3 Sep 2020								  
*  Description : EXTI interface file include[function prototypes, public macros
*  Version     : V02											  
*/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef EXTI_INIT_H
#define EXTI_INIT_H

/*enum describe bit numbers*/
typedef enum
{
	LINE0 =0,
	LINE1,
	LINE2,
	LINE3,
	LINE4,
	LINE5,
	LINE6,
	LINE7,
	LINE8,
	LINE9,
	LINE10,
	LINE11,
	LINE12,
	LINE13,
	LINE14,
    LINE15

}LineNumber;

/*enum for trigger mode*/
typedef enum
{
	RISING,	
    FALING,	
    ON_CHANGE
	
}TriggerMode;

/*
 *	Description: function used to initialize EXTI[choose LineNumber , Trigger Mode]
 *	Input 	   : lineNumber, Mode												   
 *	Return	   : void															   
 */
void MEXTI_voidInit(LineNumber	NUM , TriggerMode Mode);

/**********************************************************/
/*	Description: function used to Enable line number	  */
/*	Input 	   : lineNumber								  */			   
/*	Return	   : void									  */					   
/**********************************************************/
void MEXTI_voidEnableEXTI(LineNumber	NUM);

/**********************************************************/
/*	Description: function used to Disable line number	  */
/*	Input 	   : lineNumber								  */			   
/*	Return	   : void									  */					   
/**********************************************************/
void MEXTI_voidDisableEXTI(LineNumber	NUM);

/******************************************************************/
/*	Description: function used to fire Software interrupt trigger */
/*	Input 	   : lineNumber								  		  */			   
/*	Return	   : void									          */					   
/******************************************************************/
void MEXTI_voidSwTrigger(LineNumber	NUM);

/******************************************************************/
/*	Description: CallBack function used to pass *Copy_Ptr to      */
/*				 EXTI0_IRQHandler to Execute interrupt code 	  */
/*	Input 	   : [*Copy_Ptr]pointr to function					  */			   
/*	Return	   : void									          */					   
/******************************************************************/
void MEXTI_voidSetCallBack(void (*Copy_Ptr)(void));




#endif //EXTI_INIT_H
