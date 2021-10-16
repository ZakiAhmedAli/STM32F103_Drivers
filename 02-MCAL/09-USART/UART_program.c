/************************************************************************/
/*	Auther	    : zaki ahmed											*/
/*  Date 	    : 21 Sep 2020											*/
/*  Description : UART_program.c file used to implement					*/
/*					USART Functions this driver handle Five UART 		*/
/*  Version     : V02													*/
/************************************************************************/

#include"STD_TYPES.H"
#include"BIT_MATH.h"

#include"UART_interface.h"
#include"UART_private.h"
#include"UART_config.h"


#define THRESHOLD_VALUE  9000000UL


void (*MUSART_CallBack)(void);

void MUSART_voidInit(UART_Channel UART_Num )
{

	//9600 BAUDE RATE
	USARTNumbers[UART_Num]->USART_BRR =  BAUDE_RATE;
	
	#if (WORD_LENGTH == _8BIT_DATA)
		  CLR_BIT(USARTNumbers[UART_Num]->USART_CR1 , M);

	#elif (WORD_LENGTH == _9BIT_DATA)
		    SET_BIT(USARTNumbers[UART_Num]->USART_CR1 , M);
	#endif

	
	#if (STOP_BIT == _1STOP_BIT)
			USARTNumbers[UART_Num]->USART_CR2 |= (0<<STOP1)|(0<<STOP0);
	
	#elif (STOP_BIT == _0_5_STOP_BIT)
			USARTNumbers[UART_Num]->USART_CR2 |= (0<<STOP1)|(1<<STOP0);
	
	#elif (STOP_BIT == _2STOP_BIT)
			USARTNumbers[UART_Num]->USART_CR2 |= (1<<STOP1)|(0<<STOP0);
		
			#elif (STOP_BIT == _1_5_STOP_BIT)
			USARTNumbers[UART_Num]->USART_CR2 |= (1<<STOP1)|(1<<STOP0);
	#endif
				

		
		
	/*
		put baud rates
		enable TX
		enable RX
		enable UART
	*/
	//USARTNumbers[UART_Num]->USART_BRR = 0x341;
	USARTNumbers[UART_Num]->USART_CR1 |=(1<<UE)|(1<<TE)|(1<<RE);
	
	/*cleare status register*/
	USARTNumbers[UART_Num]->USART_SR= CLR_REGISTER;
}



void MUART_voidTransmitSynch(UART_Channel UART_Num  ,u8 Copy_u8DataArr[])
{
	u8 LOC_u8Counter=0;
	
	while(Copy_u8DataArr[LOC_u8Counter] !='\0' )
	{
		USARTNumbers[UART_Num]->USART_DR = Copy_u8DataArr[LOC_u8Counter];
		/*wait till transmition  complete */
		while( GET_BIT(USARTNumbers[UART_Num]->USART_SR ,TC) ==0 );
		LOC_u8Counter++;
	}
}



u8 MUART_u8ReceiveSynch(UART_Channel UART_Num )
{
	u8 LOC_u8DataRecieve=0;
	
	u16 TimeOut=0;
	 /*wait till Receive complete */
	while( GET_BIT(USARTNumbers[UART_Num]->USART_SR ,RXNE) ==0 && TimeOut ==THRESHOLD_VALUE)
	{
		TimeOut++;
	}
	if(TimeOut ==THRESHOLD_VALUE)
	{
		LOC_u8DataRecieve=255;
	}
	else
	{
		LOC_u8DataRecieve= (USARTNumbers[UART_Num]->USART_DR);
	}
	
	return (LOC_u8DataRecieve);
		
}

void MUSART_void_SetCallBack( (void)(*Ptr)(void) )
{
	MUSART_CallBack = Ptr;
}

/*Interrupt Service Routines*/
void USART1_IRQHandler(void)
{
	//clrear flag
	//CLR_BIT(USARTNumbers[USART_ONE]->USART_SR ,RXNE);
	
	USARTNumbers[USART_ONE]->USART_SR =0;
	MUSART_CallBack();
}


void USART2_IRQHandler(void)
{
	//clrear flag
	//CLR_BIT(USARTNumbers[USART_TwO]->USART_SR ,RXNE);
	
	USARTNumbers[USART_TwO]->USART_SR =0;
	MUSART_CallBack();
}

void USART3_IRQHandler(void)
{
	//clrear flag
	//CLR_BIT(USARTNumbers[USART_THREE]->USART_SR ,RXNE);
	
	USARTNumbers[USART_THREE]->USART_SR =0;
	MUSART_CallBack();
}



void USART4_IRQHandler(void)
{
	//clrear flag
	//CLR_BIT(USARTNumbers[UART_FOUR]->USART_SR ,RXNE);
	
	USARTNumbers[UART_FOUR]->USART_SR =0;
	MUSART_CallBack();
}

void USART5_IRQHandler(void)
{
	//clrear flag
	//CLR_BIT(USARTNumbers[UART_FIVE]->USART_SR ,RXNE);
	
	USARTNumbers[UART_FIVE]->USART_SR =0;
	MUSART_CallBack();
}