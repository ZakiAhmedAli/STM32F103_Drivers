/****************************************************************************/
/*	Auther	    : zaki ahmed hamed								  			*/
/*  Date 	    : 12 August 2020								  			*/
/*  Description : GPIO interface file[function prototypes and public macros]*/
/*  Version     : V03											  			*/
/*	LOG			: V01 -> Initial creation						  			*/
/*              : V02 -> Add functio GPIO_voidSetPortDirection	  			*/		
/*              : V03 -> Add function GPIO_voidWritePortValue	  			*/
/****************************************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	
#ifndef GPIO_INIT_H
#define GPIO_INIT_H

#define HIGH_PORTL 0x00FF
#define HIGH_PORTH 0xFF00


/***************pin number macros************************/
#define PIN0			0
#define PIN1			1
#define PIN2			2
#define PIN3			3
#define PIN4			4
#define PIN5			5		
#define PIN6			6
#define PIN7			7
#define PIN8			8
#define PIN9			9
#define PIN10			10
#define PIN11			11	
#define PIN12			12	
#define PIN13			13
#define PIN14			14
#define PIN15			15

/*********************** ports macros numbers**********/ 
#define GPIOA		1 
#define GPIOB		2 
#define GPIOC		3 



#define GPIO_HIGH	1
#define GPIO_LOW	0

/*I/P Configuration mode macros*/

#define	INPUT_ANALOG   				0b0000
#define	INPUT_FLOATING				0b0100
#define	INPUT_PULLUP_PULLDOWN   	0b1000
   
/*Output MODE bits for 10MHZ speed*/
#define	OUTPUT_SPEED_10MHZ_PP		0b0001
#define	OUTPUT_SPEED_10MHZ_OD		0b0101
#define	OUTPUT_SPEED_10MHZ_AF		0b1001
#define	OUTPUT_SPEED_10MHZ_AF_OD	0b1101

/*Output MODE bits for 2MHZ speed*/
#define	OUTPUT_SPEED_2MHZ_PP		0b0010
#define	OUTPUT_SPEED_2MHZ_OD		0b0110
#define	OUTPUT_SPEED_2MHZ_AF		0b1010
#define	OUTPUT_SPEED_2MHZ_AF_OD		0b1110

/*Output MODE bits for 50MHZ speed*/
#define	OUTPUT_SPEED_50MHZ_PP		0b0011
#define	OUTPUT_SPEED_50MHZ_OD		0b0111
#define	OUTPUT_SPEED_50MHZ_AF		0b1011
#define	OUTPUT_SPEED_50MHZ_AF_OD	0b1111


/*APB2 peripheral clock enable register (RCC_APB2ENR)
 * Low-, medium-, high- and XL-density reset and clock control (RCC)*/

#define 	IOPAEN					2

#define 	IOPBEN					3

#define 	IOPCEN					4


/*******************************************************************/
/* Descrption : this function is used to set pin mode[input/output]*/
/* Input      : Port Name , Pin Number , Pin Mode				   */	
/* Return	  : void											   */
/*******************************************************************/
void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);

/*******************************************************************/
/* Descrption : this function is used to set pin value[high/low]   */
/* Input      : Port Name , Pin Number , Pin Value				   */	
/* Return	  : void											   */
/*******************************************************************/
void GPIO_voidSetPinvalue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/*******************************************************************/
/* Descrption : this function is used to Return pin value		   */
/* Input      : Port Name , Pin Number 							   */	
/* Return	  : pin value[high/low]								   */
/*******************************************************************/
u8 GPIO_u8GetPinvalue(u8 Copy_u8Port , u8 Copy_u8Pin);

/********************************************************************/
/* Descrption : this function is used to set port mode[input/output]*/
/* Input      : Port Name , Port Mode						  	    */	
/* Return	  : void											    */
/********************************************************************/
void GPIO_voidSetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Mode);

/*****************************************************************/
/* Descrption : this function is used to set por value[high/low] */
/* Input      : Port Name , Port value						 	 */	
/* Return	  : void											 */
/*****************************************************************/
void GPIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

/**************************************************************/
/* Descrption : this function is used to write value on port  */
/* Input      : Port Name , Port value						  */	
/* Return	  : void										  */
/**************************************************************/
void GPIO_voidWritePortValue(u8 Copy_u8Port , u8 Copy_u8Value);





#endif
