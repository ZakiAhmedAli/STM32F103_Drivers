#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DMA_init.h"
#include"DMA_private.h"
#include"DMA_config.h"




void MDMA_voidChannelInit(void)
{
	/*
		Memory to memory
		Priority very high
		Source, destination size=32bit
		MINC , PINC activated
		No circular
		Direction: peripheral to memory
		Transfer complete interrupt enable
		Channel Disable
	*/
	
	#if	(CHANNELID == chanel_1)
		DMA->channle[CHANNELID].DMA_CCR=0x00007AC2; 
	
}

void MDMA_voidChannelStart(u32 *Copy_u32SourceAdd ,u32 *Copy_u32DestinationAdd,u16 Copy_u16BlockLength)
{
	
	/*make sure channel is disable */
	CLR_BIT(DMA->channel[CHANNELID].DMA_CCR , 0);
	
	/*write source address*/
	 DMA->channle[CHANNELID].DMA_CPAR = Copy_u32SourceAdd;
	 
	/*write destination address*/
	 DMA->channel[CHANNELID].DMA_CMAR = Copy_u32DestinationAdd;
	 
	 /*write Block Length*/
	 
	 DMA->channel[CHANNELID].DMA_CNDTR = Copy_u16BlockLength;
	 
	 /*Enable channel*/
	 SET  _BIT(DMA->channel[CHANNELID].DMA_CCR , 0);
}