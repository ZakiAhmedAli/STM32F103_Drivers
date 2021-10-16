/******************************************************************/
/*	Auther	    : zaki ahmed hamed								  */
/*  Date 	    : 16 September 2020								  */
/*  Description : DMA_private.h [DMA register decription] 	  */
/*  Version     : V01											  */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 DMA_CCR;
	volatile u32 DMA_CNDTR;
	volatile u32 DMA_CPAR;
	volatile u32 DMA_CMAR;
	volatile u32 Reserved;
}DMA_Channel;


typedef struct
{
	volatile u32 DMA_ISR;
	volatile u32 DMA_IFCR;
	DMA_Channel channle[7];	
	
}DMA_REG;



#define DMA		((volatile DMA_REG*)(0x40020000))



#define chanel_1	0
#define chanel_2	1
#define chanel_3	2
#define chanel_4	3
#define chanel_5	4
#define chanel_6	5
#define chanel_7	6








#endif