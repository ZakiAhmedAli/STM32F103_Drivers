#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"SSD_init.h"


void SSD_voidInit(void)
{
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN0, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN1, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN2, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN3, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN4, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN5, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN6, OUTPUT_SPEED_10MHZ_PP);
	GPIO_voidSetPinDirection(SSD_DATA_PORT , PIN7, OUTPUT_SPEED_10MHZ_PP);
}



void SSD_voidWrite(u8 Copy_u8Value)
{
	u8 LOC_SEG_MAP[SIZE]={0x3F,0x06,0x5D,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
	GPIO_voidSetPortValue(SSD_DATA_PORT,LOC_SEG_MAP[Copy_u8Value]);
}                         
                         
                          
                          
                          
                          
  