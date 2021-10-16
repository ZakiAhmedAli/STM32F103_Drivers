/********************************************************************/
/*	Auther	    : zaki ahmed									  	*/
/*  Date 	    : 12 August 2020								  	*/
/*  Description : GPIO_private[register address and private macros] */
/*  Version     : V01											  	*/
/********************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef	GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


											
#define GPIOA_BASE_ADDRESS		0x40010800	// Register boundary addresses for GPIO portA
#define GPIOB_BASE_ADDRESS		0x40010C00	// Register boundary addresses for GPIO portB
#define GPIOC_BASE_ADDRESS		0x40011000	// Register boundary addresses for GPIO portC


 /*       REGISTERS ADDRESSES FOR Port A        */
#define		GPIOA_CRL	*((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define		GPIOA_CRH	*((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define		GPIOA_IDR	*((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define		GPIOA_ODR	*((u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define		GPIOA_BSRR	*((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define		GPIOA_BRR	*((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define		GPIOA_LCKR	*((u32 *)(GPIOA_BASE_ADDRESS + 0x18))

 /*       REGISTERS ADDRESSES FOR Port B        */
#define		GPIOB_CRL	*((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define		GPIOB_CRH	*((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define		GPIOB_IDR	*((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define		GPIOB_ODR	*((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define		GPIOB_BSRR	*((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define		GPIOB_BRR	*((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define		GPIOB_LCKR	*((u32 *)(GPIOB_BASE_ADDRESS + 0x18))

 /*       REGISTERS ADDRESSES FOR Port C        */
#define		GPIOC_CRL	*((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define		GPIOC_CRH	*((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define		GPIOC_IDR	*((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define		GPIOC_ODR	*((u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define		GPIOC_BSRR	*((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define		GPIOC_BRR	*((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define		GPIOC_LCKR	*((u32 *)(GPIOC_BASE_ADDRESS + 0x18))
/*******************************************************************/







#endif /*GPIO_PRIVATE_H*/
