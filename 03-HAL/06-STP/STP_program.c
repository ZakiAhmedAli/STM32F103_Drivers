#include"STD_TYPES"
#include"BIT_MATH"
#include"RCC_interface.h"
#include"GPIO_init.h"
#include"MSTK_init.h"









void HSTP_voidSendSyncronous(u8 Copy_u8DataToSend)
{
	s8 LOC_u8Counter=0;
	u8 LOC_u8Bit=0;
	
	/*send bit by bit starting from MSB */
	for(LOC_u8Counter=7 ; LOC_u8Counter>=0 ; LOC_u8Counter--)
	{
		LOC_u8Bit = GET_BIT(Copy_u8DataToSend, LOC_u8Counter);
		
		/*send pulse to serial clock*/
		GPIO_voidSetPinValue(HSTP_SERIAL_DATA , PIN0 , GPIO_HIGH);
	
			/*send pulse to shift clock*/
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK , PIN1 , GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		
		GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK , PIN1 , GPIO_LOW);
		MSTK_voidSetBusyWait(1);
		
	}

	
	GPIO_voidSetPinValue(HSTP_STORE_CLOCK , PIN2 , GPIO_LOW);

}
