
/*
 * File        : HLED_Program.c
 * Description : This file includes LED Driver implementations for STM
 * Author      : Zaki Ahmed Embedded SW Engineer 
 * Date        : 20 August 2020
 * Git account : https://github.com/ZakiAhmedAli
 * mail        :  
 */

 /*******************************************
 *	Description : Libirary Directive  		*
 *******************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

 /*******************************************
 *	Description : DIO Directive  			*
 *******************************************/
#include"GPIO_init.h"

#include"LED_init.h"

/****************************************************************/
/*	Description : this function is used to initialize Pin Mode	*/
/*	Input		: Pin number									*/
/*	Output		: Nothing										*/
/****************************************************************/
void LED_voidInit(u8 Copy_u8LedNum)
{
	//SET pin Mode as output
	GPIO_voidSetPinDirection(LED_PORT , Copy_u8LedNum , OUTPUT_SPEED_10MHZ_PP);
}

/************************************************************/
/*	Description : this function is used to Set Pin ON		*/
/*	Input		: Pin number								*/
/*	Return		: void										*/
/************************************************************/
void LED_voidLedON(u8 Copy_u8LedNum)
{
	// Set pin Value as ON
	GPIO_voidSetPinvalue(LED_PORT , Copy_u8LedNum ,GPIO_HIGH);
}

/************************************************************/
/*	Description : this function is used to Set Pin OFF		*/
/*	Input		: Pin number								*/
/*	Return		: void										*/
/************************************************************/
void LED_voidLedOFF(u8 Copy_u8LedNum)
{
	// Set pin Value as off
	GPIO_voidSetPinvalue(LED_PORT , Copy_u8LedNum ,GPIO_LOW);
}
