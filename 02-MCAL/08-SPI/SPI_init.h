/********************************************************/
/*	Auther	    : zaki ahmed hamed						*/
/*  Date 	    : 16 September 2020						*/
/*  Description : SPI_init.h [publi macros and SPI APIs]*/
/*  Version     : V01									*/
/********************************************************/


/***************************************************************************
*  Description : Guard to Protect this file from include more than one time*
***************************************************************************/	
#ifndef SPI_INIT_H
#define SPI_INIT_H


/* clock phase macros option */
#define	CPHA_LOW	 		0
#define	CPHA_HIGH			1

/* clock polarity macros*/
#define IDLE_LOW         	0
#define IDLE_HIGH        	1

/*********** prescaler options ***************/

#define  FPCLK_DIV_2		0
#define  FPCLK_DIV_4		1
#define  FPCLK_DIV_8		2
#define  FPCLK_DIV_16		3
#define  FPCLK_DIV_32		4
#define  FPCLK_DIV_64		5
#define  FPCLK_DIV_128		6
#define  FPCLK_DIV_256		7

/* Data order macros*/
#define LSB_FIRST			1
#define MSB_FIRST			0

#define SW_MANAGE_ENABLE	2
#define SW_MANAGE_DISABLE	3

/* Data format macros*/
#define _8BIT				0
#define _16BIT				1


#define MASTER				1
#define SLAVE				0



#define RECEIVE_ONLY		0
#define SEND_RECEIVE		1




/*************************************************************/
/* Description : this function used to init SPI Configuration*/
/* Input	   : nothing[void]								 */
/* Return	   : nothing[void]								 */
/*************************************************************/
void MSPI_voidInit( u8 Copy_u8SPINumbers);

/*************************************************************************
* Description : this function used to Send and receive data Synchronous
* Input	  	  : SPI numbers[SPI1=0 , SPI2=0 , SPI3=2] ,Data To Transmit , DataToReceive
* Return	  : nothing[void]
*************************************************************************/

void MSPI_voidSendRecieveSynch(u8 Copy_u8SPINumbers ,u8 Copy_u8DataToTransmit ,u8 *Copy_u8DataToReceive);

/*************************************************************************************************/
/* Description : this function used to Send and receive data Synchronous 						 */
/* Input	   : SPI numbers[SPI1=0 , SPI2=1 , SPI3=2],DataToTransmit ,u8 *Copy_u8DataToReceive */
/* Return	   : nothing[void]								 			 						 */
/*************************************************************************************************/
void MSPI_voidSendRecieveASynch(u8 Copy_u8SPINumbers ,u8 Copy_u8DataToTransmit , void(*Copy_CallBack)(u8) );





#endif //SPI_INIT_H
