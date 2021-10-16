/********************************************************/
/*	Auther	    : zaki ahmed							*/
/*  Date 	    : 09 August 2020						*/
/*  Description : RCC configuration file				*/
/*  Version     : V01									*/
/********************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef		_RCC_CONFIG_H
#define 	_RCC_CONFIG_H


/*	options:   RCC_HSE_CRYSTAL
               RCC_HSE_RC
               RCC_HSI
               RCC_PLL*/
#define		CLOCK_TYPE  RCC_HSE_CRYSTAL

/*	options:	RCC_PLL_HSI_DIV_2
				RCC_PLL_HSE_DIV_2
				RCC_PLL_HSE
Note select the value if you have PLL as input clock*/

#if	CLOCK_TYPE == RCC_PLL
#define	PLL_CLOCK_SOURCE 	RCC_PLL_HSE_DIV_2
#endif				


/*	options: from 2 to 16
	choose mul value first then enable PLL*/

/*clockFactor may be :											
					1-	NO_CLOCK_FACTOR  For HSI or HSE  								
					2-	MULTIPLY_BY_2				
					3-	MULTIPLY_BY_3					
					4-	MULTIPLY_BY_4					
					5-	MULTIPLY_BY_5					
					6-	MULTIPLY_BY_6					
					7-	MULTIPLY_BY_7					
					8-	MULTIPLY_BY_8					
					9-	MULTIPLY_BY_9					
					10-	MULTIPLY_BY_10					
					11-	MULTIPLY_BY_11					
					12-	MULTIPLY_BY_12					
					13-	MULTIPLY_BY_13					
					14-	MULTIPLY_BY_14					
					15-	MULTIPLY_BY_15					
					16-	MULTIPLY_BY_16	*/

#if	CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VALUE	PLL_NO_CLOCK_FACTOR
#endif





#endif
