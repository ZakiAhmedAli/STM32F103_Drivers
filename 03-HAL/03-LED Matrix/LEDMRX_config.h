/********************************************************************/
/*	Auther	    : zaki ahmed hamed								  	*/
/*  Date 	    : 28 August 2020								  	*/
/*  Description : LEDMRX_config.h confiuration file of LED matrix 	*/
/*  Version     : V01											    */
/********************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H



/*ROW Pins configuration -> PORTA*/
#define LEDMRX_ROW_PIN	  GPIOA

/*COlumn Pins configuration -> PORTB from pin8 to pin 15 */
#define LEDMRX_COL_PIN	  GPIOB

#endif
