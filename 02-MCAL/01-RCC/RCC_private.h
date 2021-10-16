/*********************************************************/
/*	Auther	    : zaki ahmed							 */
/*  Date 	    : 09 August 2020						 */
/*  Description : RCC register address and private macros*/
/*  Version     : V01									 */
/*********************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	

#ifndef  _RCC_PRIVATE_H
#define  _RCC_PRIVATE_H

//clock type
#define RCC_HSE_CRYSTAL					1
			
#define RCC_HSE_RC		   				2
			
#define RCC_HSI							3	
			
#define RCC_PLL							4
			
//PLL Clock source			
#define	 RCC_PLL_HSI_DIV_2				0
#define  RCC_PLL_HSE_DIV_2				1
#define  RCC_PLL_HSE	        		2
		
//PLL multiplication factor
#define  PLL_NO_CLOCK_FACTOR			0
#define RCC_PLLMul_2                    ((u32)0x00000000)
#define RCC_PLLMul_3                    ((u32)0x00040000)
#define RCC_PLLMul_4                    ((u32)0x00080000)
#define RCC_PLLMul_5                    ((u32)0x000C0000)
#define RCC_PLLMul_6                    ((u32)0x00100000)
#define RCC_PLLMul_7                    ((u32)0x00140000)
#define RCC_PLLMul_8                    ((u32)0x00180000)
#define RCC_PLLMul_9                    ((u32)0x001C0000)
#define RCC_PLLMul_10                   ((u32)0x00200000)
#define RCC_PLLMul_11                   ((u32)0x00240000)
#define RCC_PLLMul_12                   ((u32)0x00280000)
#define RCC_PLLMul_13                   ((u32)0x002C0000)
#define RCC_PLLMul_14                   ((u32)0x00300000)
#define RCC_PLLMul_15                   ((u32)0x00340000)
#define RCC_PLLMul_16                   ((u32)0x00380000)


//RCC_CR Bits
#define	PLLRDY  			25
#define	PLLON				24
#define	HSERDY				17
#define HSIRDY				1


//RCC_CFGR Bits
#define	PLLXTPRE		17

#define	PLLSRC			16








/***********RCC Register Definitions*******************/

/*Clock control register (RCC_CR) Address offset: 0x00 */
#define  RCC_CR  		*((u32*)0x40021000)

/*Clock configuration register (RCC_CFGR) Address offset: 0x04*/
#define  RCC_CFGR  		*((u32*)0x40021004)

/*Clock interrupt register (RCC_CIR) Address offset: 0x08*/
#define  RCC_CIR		*((u32*)0x40021008)	

/*APB2 peripheral reset register (RCC_APB2RSTR) Address offset: 0x0C*/
#define RCC_APB2RSTR	*((u32*)0x4002100C)

/*APB1 peripheral reset register (RCC_APB1RSTR) Address offset: 0x10*/
#define RCC_APB1RSTR	*((u32*)0x40021010)

/*AHB peripheral clock enable register (RCC_AHBENR) Address offset: 0x14*/
#define RCC_AHBENR		*((u32*)0x40021014)

/*APB2 peripheral clock enable register (RCC_APB2ENR) Address: 0x18*/
#define RCC_APB2ENR		*((u32*)0x40021018)

/*APB1 peripheral clock enable register (RCC_APB1ENR) Address: 0x1C*/
#define RCC_APB1ENR		*((u32*)0x4002101C)

/*Backup domain control register (RCC_BDCR) Address offset: 0x20*/
#define RCC_BDCR		*((u32*)0x40021020)

/*Control/status register (RCC_CSR) Address: 0x24*/
#define RCC_CSR		*((u32*)0x40021024)





#endif
