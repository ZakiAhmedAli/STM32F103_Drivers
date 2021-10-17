/***************************************************************************************
  Auther	    : zaki ahmed hamed						
  Date 	    : 16 September 2020						
  Description : DMA_config.h  [DMA configuration file] contains configuration parameter
  Version     : V01									
****************************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H


/* options : DMA_LOW      
             DMA_MEDIUM   
             DMA_HIGH     
             DMA_VERY_HIGH

*/
#define	PRIORITY_LEVEL		DMA_VERY_HIGH

/* options : 
			 BYTE     
			 HALF_WORD#define MEMORY_SIZE
			 WORD     
*/
#define PERIPHERAL_SIZE		WORD

/* options :
			 BYTE
			 HALF_WORD#define MEMORY_SIZE
			 WORD
*/
#define MEMORY_SIZE			WORD
/* options :  PERIPHERAL_INCREMENT_ENABLE 
              PERIPHERAL_INCREMENT_DISABLE

*/
#define PINC_MODE	PERIPHERAL_INCREMENT_ENABLE
	

/* options :MEM_INCREMENT_ENABLE 
            MEM_INCREMENT_DISABLE
*/
#define MINC_MODE	MEM_INCREMENT_ENABLE

/* options : DMA_ENABLE_CIRCULAR 
             DMA_DISABLE_CIRCULAR
*/
#define CIRC_MODE	DMA_DISABLE_CIRCULAR

/* options : MEM_TO_MEM  
             PREI_TO_MEM 
             MEM_TO_PERI 
*/
#define DIRECTION	MEM_TO_MEM






#endif //DMA_CONFIG_H
