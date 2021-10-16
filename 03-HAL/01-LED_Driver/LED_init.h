/*
 * File        : LED_init.h
 * Description : This file includes LED interface
 * Author      : Zaki Ahmed Embedded SW Engineer 
 * Date        : 20 August 2020
 * Git account : https://github.com/ZakiAhmedAli
 * mail        :  
 */

/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef	LED_INIT_H
#define	LED_INIT_H

#define LED_PORT  GPIOA


/****************************************************************/
/*	Description : this function is used to initialize Pin Mode	*/
/*	Input		: Pin number									*/
/*	Output		: Nothing										*/
/****************************************************************/
void LED_voidInit(u8 Copy_u8LedNum);
/************************************************************/
/*	Description : this function is used to Set Pin ON		*/
/*	Input		: Pin number								*/
/*	Return		: void										*/
/************************************************************/
void LED_voidLedON(u8 Copy_u8LedNum); 
/************************************************************/
/*	Description : this function is used to Set Pin OFF		*/
/*	Input		: Pin number								*/
/*	Return		: void										*/
/************************************************************/
void LED_voidLedOFF(u8 Copy_u8LedNum);


#endif //LED_H
