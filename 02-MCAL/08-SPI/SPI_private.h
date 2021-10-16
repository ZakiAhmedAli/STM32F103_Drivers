/******************************************************************/
/*	Auther	    : zaki ahmed hamed								  */
/*  Date 	    : 16 September 2020								  */
/*  Description : SPI_private.h [SPI register decription]	 	  */
/*  Version     : V01											  */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/****************** SPI Register description*******************/

#define SPI1  (0x40013000)
#define SPI2  (0x40003800)
#define SPI3  (0x40003C00)


typedef struct
{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
	volatile u32 SPI_I2SCFGR;
	volatile u32 SPI_I2SPR;
}SPI_R;

static volatile SPI_R* SPI_NUM[3]={

		((volatile SPI_R*)(SPI1)),
		((volatile SPI_R*)(SPI2)),
		((volatile SPI_R*)(SPI3))
};



/*
#define SPI1   ((volatile SPI_R *)(0x40013000))
#define SPI2   ((volatile SPI_R * )(0x40003800))
#define SPI2   ((volatile SPI_R * )(0x40003400))
*/


/****************  SPI_SR pins  ***********/
#define	BSY 		7
#define	OVR 		6
#define	MODF		5
#define	CRCERR 		4
#define	UDR 		3
#define	CHSIDE 		2
#define	TXE 		1	
#define	RXNE		0

/****************  SPI_CR1 pins  ***********/
#define	BIDIMODE	15
#define	BIDIOE		14
#define	CRCEN		13
#define	CRCNEXT		12
#define	DFF 		11
#define	RXONLY 		10
#define	SSM 		9
#define	SSI 		8
#define	LSBFIRST 	7
#define	SPE			6
#define	BR2			5
#define	BR1			4
#define	BR0			3
#define	MSTR 		2
#define	CPOL 		1
#define	CPHA		0
/**********************************************/

#endif // SPI_PRIVATE_H
