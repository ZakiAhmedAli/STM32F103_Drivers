/*****************************************************/
/*	Auther	    : zaki ahmed hamed					 */
/*  Date 	    : 16 September 2020					 */
/*  Description : DMA_private.h [DMA register Map]	 */
/*  Version     : V01								 */
/*****************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;

}DMA_Channel;


typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel CHANNEL[7];
	
}DMA_REG;




#define DMA		( (volatile DMA_REG *)0x40020000)




#define CHANNEL_NUMBERS	7


//DMA CHANNELS
/*#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6*/


//Interrupt Enable
#define DMA_TCIE  		1
#define DMA_HTIE  		2
#define DMA_TEIE  		3
//Enable
#define DMA_ENABLE  	0
#define DMA_DISABLE 	1
//DMA Configuration	
//Direction	
#define MEM_TO_MEM  	0
#define PREI_TO_MEM 	1
#define MEM_TO_PERI 	2
//Circular
#define DMA_ENABLE_CIRCULAR  1
#define DMA_DISABLE_CIRCULAR 0
//PIN & MIN
#define PERIPHERAL_INCREMENT_ENABLE  1
#define PERIPHERAL_INCREMENT_DISABLE 0
//MIN
#define MEM_INCREMENT_ENABLE  		0
#define MEM_INCREMENT_DISABLE 		1
//Size
#define BYTE       					0
#define HALF_WORD  					1
#define WORD       					2
//Channel Priority
#define DMA_LOW         			0
#define DMA_MEDIUM      			1
#define DMA_HIGH        			2
#define DMA_VERY_HIGH   			3

/*DMA_CCRx BITS*/

#define	MEM2MEM          14
#define PL1  			 13
#define	PL0				 12        
#define	MSIZE1			 11
#define	MSIZE0			 10
#define	PSIZE1			 9
#define	PSIZE0			 8						
#define	MINC             7
#define	PINC             6
#define	CIRC             5
#define	DIR              4
#define	TEIE             3
#define	HTIE             2
#define	TCIE             1
#define	EN			     0


#endif
