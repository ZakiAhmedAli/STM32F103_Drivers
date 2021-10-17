

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DMA_interface.h"
#include"DMA_private.h"
#include"DMA_config.h"

void (*DMA_CallBackChannel)(void);

void MDMA_voidChannelInit(CHANNEL_ID channel)
{
	//Disable DMA
	CLR_BIT(DMA->CHANNEL[channel].CCR , EN);
	
	//Wait Until DMA Disable
	while( GET_BIT(DMA->CHANNEL[channel].CCR , EN) == 1);
	
	/************DIRECTION************/
	#if   (DIRECTION == MEM_TO_MEM)
			 SET_BIT(DMA->CHANNEL[channel].CCR , MEM2MEM);
	 
	#elif (DIRECTION == PREI_TO_MEM)
			CLR_BIT(DMA->CHANNEL[channel].CCR , DIR);
	 
	#elif (DIRECTION == PREI_TO_MEM)
			SET_BIT(DMA->CHANNEL[channel].CCR , DIR);
	#endif

	#if   (CIRC_MODE == DMA_ENABLE_CIRCULAR)
		   SET_BIT(DMA->CHANNEL[channel].CCR ,CIRC);
	
	#elif (CIRC_MODE == DMA_DISABLE_CIRCULAR)
		   CLR_BIT(DMA->CHANNEL[channel].CCR ,CIRC);
	#endif

	#if   (PINC_MODE == PERIPHERAL_INCREMENT_ENABLE)
		   SET_BIT(DMA->CHANNEL[channel].CCR ,PINC);
	
	#elif (PINC_MODE == PERIPHERAL_INCREMENT_DISABLE)
		   CLR_BIT(DMA->CHANNEL[channel].CCR ,PINC);
	#endif

	#if   (MINC_MODE == MEM_INCREMENT_ENABLE)
		   SET_BIT(DMA->CHANNEL[channel].CCR ,PINC);
	
	#elif (MINC_MODE == MEM_INCREMENT_DISABLE)
		   CLR_BIT(DMA->CHANNEL[channel].CCR ,PINC);
	#endif

	#if		(PERIPHERAL_SIZE == BYTE)
		 `	 DMA->CHANNEL[channel].CCR |=( 0<<PSIZE1 )|(0<<PSIZE0);
	 
	#elif	(PERIPHERAL_SIZE == HALF_WORD)
			 DMA->CHANNEL[channel].CCR |=( 0<<PSIZE1 )|(1<<PSIZE0);

	#elif	(PERIPHERAL_SIZE == WORD)
			 DMA->CHANNEL[channel].CCR |=( 1<<PSIZE1 )|(0<<PSIZE0);	
	
	#endif
	
	
	#if		(MEMORY_SIZE == BYTE)
			DMA->CHANNEL[channel].CCR |=( 0<<MSIZE1 )|(0<<MSIZE0);
	 
	#elif	(MEMORY_SIZE == HALF_WORD)
			 DMA->CHANNEL[channel].CCR |=( 0<<MSIZE1 )|(1<<MSIZE0);

	#elif	(MEMORY_SIZE == WORD)
			 DMA->CHANNEL[channel].CCR |=( 1<<MSIZE1 )|(0<<MSIZE0);	
	
	#endif

	
	#if		(PRIORITY_LEVEL == DMA_LOW)
			 DMA->CHANNEL[channel].CCR |=( 0<<PL1 )|(0<<PL0);

	#elif	(PRIORITY_LEVEL == DMA_MEDIUM)
			 DMA->CHANNEL[channel].CCR |=( 0<<PL1 )|(1<<PL0);
	#elif	(PRIORITY_LEVEL == DMA_HIGH)
			 DMA->CHANNEL[channel].CCR |=( 1<<PL1 )|(0<<PL0);
	#elif	(PRIORITY_LEVEL == DMA_VERY_HIGH)
			 DMA->CHANNEL[channel].CCR |=( 1<<PL1 )|(1<<PL0);
	#endif

}

void MDMA_VoidSetAddress(CHANNEL_ID channel ,u32* PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16BlockLength)
{
	//make sure channel is disable
	//CLR_BIT(DMA->CHANNEL[channel].CCR , EN);
	
	//write Peripheral Address
	DMA->CHANNEL[channel].CPAR = (u32)PeripheralAddress;
	
	//write Memory Address
	DMA->CHANNEL[channel].CMAR = (u32)MemoryAddress;
	
	//write Block Length
	DMA->CHANNEL[channel].CNDTR = Copy_u16BlockLength;
	//enable channel
//	SET_BIT(DMA->CHANNEL[channel].CCR , EN);
	
}

void MDMA_VoidClearFlag(CHANNEL_ID channel  , u8 Copy_u8Flag)
{
	channel *=4;
	SET_BIT( DMA->IFCR ,(channel + Copy_u8Flag) );
}

u8 MDMA_VoidGetFlag(CHANNEL_ID channel  , u8 Copy_u8Flag)
{
	u8 LOC_u8Result = 0;
	
	channel *= 4;
	
	LOC_u8Result = GET_BIT(DMA->ISR , (channel + Copy_u8Flag) );
	
	return LOC_u8Result;
	
}

void MDMA_VoidDMAEnable(CHANNEL_ID channel )
{
	MDMA_VoidClearFlag(channel , DMA_GIF  );
    MDMA_VoidClearFlag(channel , DMA_TCIF );
    MDMA_VoidClearFlag(channel , DMA_HTIF );
    MDMA_VoidClearFlag(channel , DMA_TEIF );
}

void MDMA_VoidInerruptEnable(CHANNEL_ID channel , u8 Copy_u8INTSource )
{
	SET_BIT( DMA->CHANNEL[channel].CCR , Copy_u8INTSource);

}


void MDMA_VoidSetCallBackChannel( void ( *Ptr ) ( void ) )
{
	DMA_CallBackChannel = Ptr;
}


void DMA_IRQHandler(void)
{
	DMA_CallBackChannel();
}
