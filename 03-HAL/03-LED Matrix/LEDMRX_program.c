
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_init.h"
#include "MSTK_init.h"
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"



void HLEDMRX_voidInit(void)
{
	for(u8 i=0 ; i<=7 ; i++)
	{
		GPIO_voidSetPinDirection(LEDMRX_ROW_PIN ,i	  , OUTPUT_SPEED_2MHZ_PP);
		GPIO_voidSetPinDirection(LEDMRX_COL_PIN ,(i+8), OUTPUT_SPEED_2MHZ_PP);
	}
}


void LDM_VidEnable ( u8 * arr )
{

	for( u8 i = 0 ; i < 8 ; i ++ )
	{
		GPIO_voidWritePortValue( LEDMRX_ROW_PIN , arr[i] );
		GPIO_voidSetPinvalue ( LEDMRX_COL_PIN , (i+PIN8) , GPIO_LOW );
		/*wait 2500 micro second*/
		MSTK_voidSetBusyWait(2500);
		GPIO_voidSetPinvalue ( LEDMRX_COL_PIN , (i+PIN8) , GPIO_HIGH );

	}

}
