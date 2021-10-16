
 /*****************************************************************************************************/
 /* File        : NVIC_Private.c															          */	
 /* Description : This file includes NVIC  memory maps and private macros and declarations for STM32  */
 /* Author      : Zaki Ahmed Hamed 																	  */
 /* Date        : 22 August 2020																	  */
 /* Git account : https://github.com/ZakiAhmedAli	 												  */
 /*****************************************************************************************************/

/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef		NVIC_PRIVATE_H
#define		NVIC_PRIVATE_H

#define NVIC_BASE	0xE000E100
#define	SCB_BASE	0xE000ED00

/* Enable External interrupts from 0  to 31 */
#define	NVIC_ISER0		*((volatile u32 *)(NVIC_BASE+0x00))
/* Enable External interrupts from 32 to 63 */
#define	NVIC_ISER1		*((volatile u32 *)(NVIC_BASE+0x04))


//Disable interrupt
#define	NVIC_ICER0		*((volatile u32 *)(NVIC_BASE+0x080))

#define	NVIC_ICER1		*((volatile u32 *)(NVIC_BASE+0x084))

#define	NVIC_ISPR0		*((volatile u32 *)(NVIC_BASE+0x100))

#define	NVIC_ISPR1		*((volatile u32 *)(NVIC_BASE+0x104))


#define	NVIC_ICPR0		*((volatile u32 *)(NVIC_BASE+0x180))

#define	NVIC_ICPR1		*((volatile u32 *)(NVIC_BASE+0x184))


#define	NVIC_IABR0		*((volatile u32 *)(NVIC_BASE+0x200))

#define	NVIC_IABR1		*((volatile u32 *)(NVIC_BASE+0x204))


#define NVIC_IPR		((volatile u8*)(NVIC_BASE+0x300))

#define SCB_AIRCR		((volatile u32*)(SCB_BASE+0x0C))


/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define		GROUP4		0x05FA0300 
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define		GROUP3		0x05FA0400 
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define		GROUP2		0x05FA0500 
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define		GROUP1		0x05FA0600 
/* in (SCB => AIRCR) 0 group for 4 bits for sub												*/
#define		GROUP0		0x05FA0700 


#endif