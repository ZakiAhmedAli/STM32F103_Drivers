/***********************************************************
*     Author      : Zaki Ahmed hamed                       *
*     Description : program.c Implementaion GPIO APIs      * 	                 
*     Date        : 12 August 2020                         *
*     Version     : V02                                    *
***********************************************************/



/**********************************************************************************
 *	Description : Libirary Directive  											  *
 *********************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

 /******************************************************
 *	Description : DIO Directive  					   *
 ******************************************************/
#include"GPIO_init.h"
#include"GPIO_private.h"



/*******************************************************************/
/* Descrption : this function is used to set pin mode[input/output]*/
/* Input      : Port Name , Pin Number , Pin Mode				   */	
/* Return	  : void											   */
/*******************************************************************/

void GPIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
					if(Copy_u8Pin < 8)
					{
						GPIOA_CRL &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOA_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4));
					}
					else if(Copy_u8Pin < 16)
					{
						Copy_u8Pin = Copy_u8Pin-8;
						GPIOA_CRH &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOA_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)) ;
					}
		break;

		case GPIOB:
					if(Copy_u8Pin < 8)
					{
						GPIOB_CRL &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOB_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4));
					}
					else if(Copy_u8Pin < 16)
					{
						Copy_u8Pin = Copy_u8Pin-8;
						GPIOB_CRH &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOB_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)) ;
					}
		break;

		case GPIOC:
					if(Copy_u8Pin < 8)
					{
						GPIOC_CRL &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOC_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin * 4));
					}
					else if(Copy_u8Pin < 16)
					{
						Copy_u8Pin = Copy_u8Pin-8;
						GPIOC_CRH &=~((0b1111)<<(Copy_u8Pin * 4)) ;
						GPIOC_CRH |= ((Copy_u8Mode)<<(Copy_u8Pin * 4)) ;
					}
		break;

		default: break;		
	}
}

/*******************************************************************/
/* Descrption : this function is used to set pin value[high/low]   */
/* Input      : Port Name , Pin Number , Pin Value				   */	
/* Return	  : void											   */
/*******************************************************************/
void GPIO_voidSetPinvalue(u8 Copy_u8Port , u8 copy_u8Pin , u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
					if(Copy_u8Value == GPIO_HIGH)
					{
						/*
						//puting value in specific Bit using GPIOA_ODR
						SET_BIT( GPIOA_ODR , Copy_u8Pin );*/
						//SET value in a specific Bit using GPIOA_BSRR
						GPIOA_BSRR = (1<<copy_u8Pin);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						/*
						//puting value in specific pin using GPIOA_ODR
						CLR_BIT(GPIOA_ODR , copy_u8Pin);
						//SET value in  specific Bit using GPIOA_BSRR
						GPIOA_BSRR = (1<<(copy_u8Pin+16));*/
						//SET value in specific Bit using GPIOA_BRR
						GPIOA_BRR = (1<<(copy_u8Pin));
					}
		break;
		
		case GPIOB:
					if(Copy_u8Value == GPIO_HIGH)
					{
						/*
						//puting value in specific Bit using GPIOB_ODR
						SET_BIT(GPIOB_ODR , copy_u8Pin);*/
						//SET value in specific Bit using GPIOB_BSRR
						GPIOB_BSRR = (1<<copy_u8Pin);
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						/*puting value in copy_u8Pin Bit using GPIOB_ODR
						CLR_BIT(  GPIOB_ODR , Copy_u8Pin );
						//SET value in specific Bit using GPIOB_BSRR
						GPIOB_BSRR = (1<<(copy_u8Pin+16));*/

						//SET value in specific Bit using GPIOB_BRR
						GPIOB_BRR = (1<<(copy_u8Pin));
					}
		break;
		
		case GPIOC:
					if(Copy_u8Value == GPIO_HIGH)
					{
						/*set spcific Bit using ODR , BSRR
					   SET_BIT(GPIOC_ODR , copy_u8Pin);	*/
					   GPIOC_BSRR = (1<<(copy_u8Pin));
					}
					else if(Copy_u8Value == GPIO_LOW)
					{
						/*puting value in specific pin using GPIOC_ODR
						CLR_BIT(GPIOC_ODR , copy_u8Pin);
						//SET value in sin specific pin using GPIOC_BSRR
						GPIOC_BSRR = (1<<(copy_u8Pin+16));*/
						//SET value in sin specific pin using GPIOC_BRR
						GPIOC_BRR = (1<<(copy_u8Pin));
					}

		break;
		
		default : break;
	}
}

/*******************************************************************/
/* Descrption : this function is used to Return pin value		   */
/* Input      : Port Name , Pin Number 							   */	
/* Return	  : pin value[high/low]								   */
/*******************************************************************/
u8 GPIO_u8GetPinvalue(u8 Copy_u8Port , u8 copy_u8Pin)
{
	u8 LOC_u8Value=0;
	if(copy_u8Pin <16)
	{
		switch(Copy_u8Port)
		{
			case GPIOA : LOC_u8Value = GET_BIT(GPIOA_IDR , copy_u8Pin); break;
			case GPIOB : LOC_u8Value = GET_BIT(GPIOB_IDR , copy_u8Pin); break;
			case GPIOC : LOC_u8Value = GET_BIT(GPIOC_IDR , copy_u8Pin); break;
			default : 	/*NO Thing*/									break;
		}
	}
	else{}
	
	return LOC_u8Value;
}


/********************************************************************/
/* Descrption : this function is used to set port mode[input/output]*/
/* Input      : Port Name , Port Mode						  	    */	
/* Return	  : void											    */
/********************************************************************/
void GPIO_voidSetPortDirection(u8 Copy_u8Port ,u8 Copy_u8Mode)
{
	u8 LOC_u8Count=0;
	for(LOC_u8Count=PIN0 ; LOC_u8Count <=PIN15 ; LOC_u8Count++)
		GPIO_voidSetPinDirection(Copy_u8Port ,LOC_u8Count, Copy_u8Mode);
}


/*****************************************************************/
/* Descrption : this function is used to set por value[high/low] */
/* Input      : Port Name , Port value						 	 */	
/* Return	  : void											 */
/*****************************************************************/
void GPIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{

		 if(Copy_u8Value == GPIO_HIGH)
		  {
			 switch(Copy_u8Port)
			 {
				case GPIOA: SET_BYTE(GPIOA_ODR);	break;
				case GPIOB: SET_BYTE(GPIOB_ODR);	break;
				case GPIOC: SET_BYTE(GPIOC_ODR);	break;
				default:							break;
			 }
		  }
		 else if(Copy_u8Value == GPIO_LOW)
		  {
			 switch(Copy_u8Port)
			 {
					case GPIOA: CLEAR_BYTE(GPIOA_ODR);	break;
					case GPIOB: CLEAR_BYTE(GPIOB_ODR);	break;
					case GPIOC: CLEAR_BYTE(GPIOC_ODR);	break;
					default:							break;
			 }
		  }

}

/**************************************************************/
/* Descrption : this function is used to write value on port  */
/* Input      : Port Name , Port value						  */	
/* Return	  : void										  */
/**************************************************************/
void GPIO_voidWritePortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	 switch(Copy_u8Port)
	 {
			case GPIOA: GPIOA_ODR  =Copy_u8Value ;	break;
			case GPIOB: GPIOB_ODR  =Copy_u8Value ;	break;
			case GPIOC: GPIOC_ODR  =Copy_u8Value ;	break;
			default:							break;
	 }

}

