/********************************************************/
/*	Auther	    : zaki ahmed							*/
/*  Date 	    : 09 August 2020						*/
/*  Version     : V01									*/
/********************************************************/


/**********************************************************************************
*     Description : Guard to Protect this file from include more than one time    *
**********************************************************************************/	


#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(REG , BIT_NO)	 (REG)|=(1<<(BIT_NO))
#define CLR_BIT(REG , BIT_NO)    (REG)&=~(1<<(BIT_NO))
#define TOGGLE_BIT(REG , BIT_NO) (REG) ^=(1<<(BIT_NO))
#define GET_BIT(REG , BIT_NO)    ((REG>>BIT_NO)&0X01)

#define SET_BYTE(Byte) 			(Byte |=(0xFFFFFFFF))
#define CLEAR_BYTE(Byte) 		(Byte &=(0x00000000))
#define SET_NIBBLE_HIGH(Byte) 	(Byte |=(0xFFFF0000))
#define SET_NIBBLE_LOW(Byte) 	(Byte |=(0x0000FFFF))
#define CLEAR_NIBBLE_HIGH(Byte) (Byte &=(0xFFFF0000))
#define CLEAR_NIBBLE_LOW(Byte) 	(Byte &=(0xFFFF0000))




#endif
