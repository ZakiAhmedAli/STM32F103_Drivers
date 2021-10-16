/********************************************************/
/*	Auther	    : zaki ahmed							*/
/*  Date 	    : 09 August 2020						*/
/*  Description : program.c For RCC 					*/
/*  Version     : V01									*/
/********************************************************/


/*********************** STD LIB DIRECTIVES *********************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

/*********************** Component DIRECTIVES *******************/
#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"


/**************************************************************************/
/* Description	: this function used to Enable and select clock for RCC   */

void RCC_voidInitSystemClock(void)
{
	#if  CLOCK_TYPE == RCC_HSE_CRYSTAL	
			RCC_CR   = 0x00010000; 				//Enable HSE with NO bypass
			RCC_CFGR = 0x00000001; 				//HSE selected as system clock
			while(!(GET_BIT(RCC_CR , HSERDY)));//check HSE Ready flags
			           		
	#elif CLOCK_TYPE == RCC_HSE_RC			
	        RCC_CR = 0x00050000;   				// Enable HSE with bypass         
	        RCC_CFGR = 0x00000001; 				//HSE selected as system clock           			
	
	#elif CLOCK_TYPE == RCC_HSI
			RCC_CR = 0x00000081  				// Enable HSI + Trimming = 0 
			RCC_CFGR = 0x00000000; 				//HSI selected as system clock
			while(!(GET_BIT(RCC_CR , HSIRDY)));//check HSI Ready flags
			
	#elif CLOCK_TYPE == RCC_PLL
			#if PLL_CLOCK_SOURCE ==	RCC_PLL_HSI_DIV_2
					//PLL selected as system clock
					RCC_CFGR 	= 0x00000002; 
					//select multiplication factor option
					RCC_CFGR|= RCC_PLL_MUL_VALUE 
					/*select HSI oscillator clock / 2 selected as PLL input clock
						and Enable HSI*/
					RCC_CR = 0x01000001; 

			#elif PLL_CLOCK_SOURCE == RCC_PLL_HSE_DIV_2
					/*PLL selected as system clock& HSE clock divided by 2*/
					RCC_CFGR = 0x00030002; 
					/*select multiplication factor option*/
					RCC_CFGR|= RCC_PLL_MUL_VALUE 
					/*  HSE divider for PLL entry : clock divided
						HSE oscillator clock selected as PLL input clock*/
					RCC_CR = 0x01010000; 
					
			#elif PLL_CLOCK_SOURCE == RCC_PLL_HSE
					RCC_CFGR = 0x00010002; 		/*PLL selected as system clock  
												 HSE oscillator clock selected as PLL input clock*/
		
					RCC_CFGR|= RCC_PLL_MUL_VALUE /*select multiplication factor option*/
												 
					RCC_CR = 0x01010000; /*PLL & HSE clock enable*/
			#endif
			
			
	
	#endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_PreId)
{
	
	if(Copy_PreId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHP  : SET_BIT(RCC_AHBENR  , Copy_PreId);   break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_PreId);   break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_PreId);   break;
		}
	}
	else
	{
		//return error
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_PreId)
{
	
	if(Copy_PreId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHP  : CLR_BIT(RCC_AHBENR  , Copy_PreId);   break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_PreId);   break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_PreId);   break;
		}
	}
	else
	{
		//return error
	}
}
