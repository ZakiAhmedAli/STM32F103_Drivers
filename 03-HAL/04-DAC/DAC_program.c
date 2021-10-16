#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_init.h"
#include "MSTK_init.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


#include "file1.h"

volatile u16 Song_Counter = 0;

void DAC_voidCALL_BACK(void)
{
	GPIO_voidWritePortValue(DAC_PORT , song_raw[Song_Counter]);
	Song_Counter++;
	
	if(Song_Counter == Song_Length)
	{
		Song_Counter = 0;
	}
}

void MDAC_VidInit( void )
{
	for(u8 counter =PIN0 ; counter <=PIN7 ; counter++)
	{
		/* IO Pins Initialization */
		GPIO_voidSetPinDirection(DAC_PORT,counter,OUTPUT_SPEED_2MHZ_PP);
	}			

		/* SysTick Init */
	MSTK_voidInit(_AHB_DIV8); /* Enable SysTick AHB/8 = 1MHZ */

}




void MDAC_VidPlay( void )
{
	MSTK_voidSetIntervalPeriodic(125 ,DAC_voidCALL_BACK);
}
