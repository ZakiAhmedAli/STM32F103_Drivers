#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"AFIO_init.h"
#include"AFIO_private.h"
#include"AFIO_config.h"


void MAFIO_voidSetEXTIConfiguration(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
	u8 LOC_u8RegIndex=0;
	/*
	if(Copy_u8Line <=3)
	{
		LOC_u8RegIndex=0;
	}
	else if(Copy_u8Line <=7)
	{
		LOC_u8RegIndex=1;
		Copy_u8Line -=4;
	}
	else if(Copy_u8Line <=11)
	{
		LOC_u8RegIndex =2;
		Copy_u8Line -=8;
	}
	else if(Copy_u8Line <=15)
	{
		LOC_u8RegIndex =3;
		Copy_u8Line -=12;
	}
	else{	}
	*/
	
	/* Get the register index */
	LOC_u8RegIndex = Copy_u8Line/4;
	
	 Copy_u8Line %=4;

	 /* Clear the four bits first */
	AFIO -> EXTICR[LOC_u8RegIndex] &= ~(0b1111<<(Copy_u8Line*4));
	/* Write into the four bits */
	AFIO -> EXTICR[LOC_u8RegIndex] |= ((Copy_u8PortMap)<<(Copy_u8Line*4));
}
