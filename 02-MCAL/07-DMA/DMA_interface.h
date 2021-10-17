/******************************************************************/
/*	Auther	    : zaki ahmed hamed								   */
/*  Date 	    : 16 September 2020								   */
/*  Description : DMA_interface.h [DMA public functions and macros]*/
/*  Version     : V01											   */
/******************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


typedef enum
{
	chanel1 = 0 ,
    chanel2 	,
    chanel3 	,
    chanel4 	,
    chanel5 	,
    chanel6 	,
    chanel7
	
}CHANNEL_ID;

//DMA Flags
#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3


//Interrupt Enable
#define DMA_TCIE  1
#define DMA_HTIE  2
#define DMA_TEIE  3
/*
	Function Name		: MDMA_voidChannelInit
	
	Function Description: function used to Set DMA Configuration
	
	Function Argument	: CHANNEL_ID channel 
	
	Function Return		: void
	
*/

void MDMA_voidChannelInit(CHANNEL_ID channel);

/*
	Function Name		: MDMA_VoidSetAddress
	
	Function Description: Set source and destination address and block data length
	
	Function Argument	: CHANNEL_ID channel ,u32* PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16BlockLength 
	
	Function Return		: void
	
*/
void MDMA_VoidSetAddress(CHANNEL_ID channel ,u32* PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16BlockLength);

/***************************************************************************************
	Function Name		: MDMA_VoidClearFlag                                           *
																					   *
	Function Description: function used to clear nterrupt flags[CTEIF,CHTIF,CTCIF,CGIF]*
																					   *
	Function Argument	: CHANNEL_ID channel  , u8 Copy_u8Flag                         *
																					   *
	Function Return		: void                                                         *
																					   *
***************************************************************************************/
void MDMA_VoidClearFlag(CHANNEL_ID channel  , u8 Copy_u8Flag);


/*****************************************************************************
	Function Name		: MDMA_VoidGetFlag                                   *
																			 *
	Function Description: function used to get which channel flags is set    *
																			 *
	Function Argument	: CHANNEL_ID channel  , u8 Copy_u8Flag               *
																			 *
	Function Return		: u8                                                 *
																			 *
*****************************************************************************/
u8   MDMA_VoidGetFlag(CHANNEL_ID channel  , u8 Copy_u8Flag);


/*************************************************
	Function Name		: MDMA_VoidDMAEnable     *
												 *
	Function Description: ecable DMA channels    *
												 *
	Function Argument	: CHANNEL_ID channel     *  
												 *
	Function Return		: void                   *
												 *
*************************************************/
void MDMA_VoidDMAEnable(CHANNEL_ID channel );

void MDMA_VoidInerruptEnable(CHANNEL_ID channel , u8 Copy_u8INTSource );

/********************************************************************
	Function Name		: MDMA_VidSetCallBackChannel     			*
																	*
	Function Description: to call MDA ISR    						*
																	*
	Function Argument	: void ( *Ptr ) ( void ) pointr to function *  
																	*
	Function Return		: void                   					*
																	*
********************************************************************/
void MDMA_VoidSetCallBackChannel( void ( *Ptr ) ( void ) );




#endif //DMA_INTERFACE_H
