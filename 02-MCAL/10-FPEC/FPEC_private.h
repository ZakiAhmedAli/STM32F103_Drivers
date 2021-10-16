/***************************************************************************************/
/*	Auther	    : zaki ahmed hamed						`		   					   */
/*  Date 	    : 10 October 2020								   					   */
/*  Description : FPEC_private.h file contains registers description and private macros*/
/*  Version     : V01											   					   */
/***************************************************************************************/


/**************************************************************************
* Description : Guard to Protect this file from include more than one time*
**************************************************************************/	
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H


/* Defines the FPEC registers.*/

typedef struct
{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_AR;
	volatile u32 FLASH_OBR;
	volatile u32 FLASH_WRPR
	
}FPEC_REG;


#define FPEC ((volatile FPEC_REG *)(0x40022000))


/*FLASH_SR register pins */

#define BSY			0
#define PGERR		2
#define WRPRTERR	4
#define EOP			5


/*FLASH_ACR register pins */
#define HLFCYA		3
#define PRFTB		4
#define PRFTBS		5


/*Flash control register (FLASH_CR) pins*/

#define	PG		   0
#define	PER  	   1
#define	MER        2
#define	OPTPG	   4
#define OPTER      5
#define STRT       6
#define LOCK       7
#define OPTWRE     9
#define ERRIE      10
#define EOPIE      12
/*******************************************************/

/*Key values*/
#define FPEC_KEY1			  0x45670123	
#define FPEC_KEY2			  0xCDEF89AB
#define RDPRT_KEY			  0x00A5
#define PAGE_SIZE   		  1024
#define FLASH_START_ADDRESS   0x08000000

#define    WRITE_COMPLETE    1
#define    WRITE_ERROR   	 0




#endif //FPEC_PRIVATE_H 