/****************************************************************/
/*	Auther	    : zaki ahmed									*/
/*  Date 	    : 21 Sep 2020									*/
/*  Description : UART_interface.h file contains public finction*/
/*  Version     : V01											*/
/****************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum
{
	USART_ONE=0,
	USART_TwO,
	USART_THREE,
	UART_FOUR,
	UART_FIVE

	
}UART_Channel;

/*
	Function Name		: MUSART_voidInit
	
	Function Description: function used to intialize USART configuration
	
	Function Argument	: u8 Copy_u8UARTNumber
	
	Function Return		: void
	
*/

void MUSART_voidInit(UART_Channel UART_Num);

/*
	Function Name		: MUART_voidTransmit
	
	Function Description: function used to tramsmit Data 
	
	Function Argument	: u8u8 Copy_u8UARTNumber , u8 Copy_u8DataArr[]
	
	Function Return		: void
	
*/

void MUART_voidTransmitSynch(UART_Channel UART_Num , u8 Copy_u8DataArr[]  );

/*
	Function Name		: MUART_u8Receive
	
	Function Description: function used to Receive Data 
	
	Function Argument	: u8u8 Copy_u8UARTNumber 
	
	Function Return		: u8
	
*/
u8 MUART_u8ReceiveSynch(UART_Channel UART_Num );

#endif //UART_INTERFACE_H
