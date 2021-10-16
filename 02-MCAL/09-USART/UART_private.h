/********************************************************************************************/
/*	Auther	    : zaki ahmed																*/
/*  Date 	    : 21 Sep 2020																*/
/*  Description : UART_private.h file contains registers Description and private information*/
/*  Version     : V01																		*/
/********************************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define USART1 0x40013800
#define USART2 0x40004400
#define USART3 0x40004800
#define UART4  0x40004C00
#define UART5  0x40005000

typedef struct
{
	volatile u32 USART_SR;
	volatile u32 USART_DR;
	volatile u32 USART_BRR;;
	volatile u32 USART_CR1;
	volatile u32 USART_CR2;
	volatile u32 USART_CR3;
	volatile u32 USART_GTPR;
		
}USART_REG;

static volatile USART_REG* USARTNumbers[5]=
{
	((volatile USART_REG*)(USART1)),
	((volatile USART_REG*)(USART2)),
	((volatile USART_REG*)(USART3)),
	((volatile USART_REG*)(UART4)),
	((volatile USART_REG*)(UART5))
	
};

#define CLR_REGISTER          0X00000000



#define USART_NUM1		(0x0)
#define USART_NUM2		(0x1)
#define USART_NUM3		(0x2)
#define USART_NUM4		(0x3)
#define USART_NUM5		(0x4)


/*
#define USART1 ((volatile USART_REG * )(0x40013800))

#define USART2 ((volatile USART_REG * )(0x40004400))

#define USART3 ((volatile USART_REG * )(0x40004800))

#define USART4 ((volatile USART_REG * )(0x40004C00))*/

/**********************************************************/

#define _9BIT_DATA		9
#define _8BIT_DATA		8


#define _1STOP_BIT		0
#define _0_5_STOP_BIT	1
#define _2STOP_BIT		2
#define _1_5_STOP_BIT	3


//Clock: 1 MHz 
#define UART_BAUDRATE_1200_CLK_1M       0X0341
#define UART_BAUDRATE_2400_CLK_1M       0X01A0
#define UART_BAUDRATE_4800_CLK_1M       0X00D0
#define UART_BAUDRATE_9600_CLK_1M       0X0068
#define UART_BAUDRATE_19200_CLK_1M      0X0034
//Clock: 8 MHz 
#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
#define UART_BAUDRATE_2400_CLK_8M       0X0D05
#define UART_BAUDRATE_4800_CLK_8M       0X0683
#define UART_BAUDRATE_9600_CLK_8M       0X0341
#define UART_BAUDRATE_19200_CLK_8M      0X01A1

//SR REGISTER Defnitons
#define PE           0
#define FE           1
#define OREE         2
#define NE           3
#define IDLE         4
#define RXNE         5
#define TC           6
#define TXE          7
#define LDB          8
#define CTS          9


//CR1 REGISTER Definiteness
#define SPK          0
#define RWU          1
#define RE           2
#define TE           3
#define IDLEIE       4
#define RXNEIE       5
#define TCIE         6
#define TXEIE        7
#define PEIE         8
#define PS           9
#define PCE          10
#define WAKE         11
#define M            12
#define UE           13
/***************   Control register 1 (USART_CR1)Bits   *******************/
#define	UE 			13
#define	M 			12
#define	WAKE 		11
#define	PCE 		10
#define	PS 			9
#define	PEIE 		8
#define	TXEIE 		7
#define	TCIE 		6
#define	RXNEIE 		5
#define	IDLEIE 		4
#define	TE 			3
#define	RE			2 
#define	RWU 		1
#define	SBK			0


/***************   Control register 2 (USART_CR2)Bits   *******************/

#define STOP1		13
#define STOP0		12
#define	CLKEN 		11
#define	CPOL 		10
#define	CPHA 		9
#define	LBCL 		8
#define	LBDIE 		6
#define	LBDL		5


/***************   Control register 3 (USART_CR3)Bits   *******************/
#define	CTSIE 		10			
#define	CTSE  		9			
#define	RTSE  		8			
#define	DMAT  		7			
#define	DMAR  		6			
#define	SCEN  		5			
#define	NACK  		4			
#define	HDSEL 		3			
#define	IRLP  		2			
#define	IREN  		1			
#define	EIE	  		0			
              
#endif        
