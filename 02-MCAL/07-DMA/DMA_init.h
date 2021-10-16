/******************************************************************/
/*	Auther	    : zaki ahmed hamed								  */
/*  Date 	    : 16 September 2020								  */
/*  Description : DMA_init.h [DMA public functions and macros] 	  */
/*  Version     : V01											  */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef DMA_INIT_H
#define DMA_INIT_H

void MDMA_voidChannelInit(void);

void MDMA_voidChannelStart(u32 *Copy_u32SourceAdd ,u32 *Copy_u32DestinationAdd,u16 Copy_u16BlockLength);


#endif 