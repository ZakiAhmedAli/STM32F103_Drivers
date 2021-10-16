#include "RCC_interface.h"
#include "GPIO_init.h"
#include "MSTK_init.h"
#include "NVIC_interface.h"
#include "EXTI_init.h"

volatile u32 Global_u32Fram[50]		={0};
volatile u8  Global_u8EdgeCounter	=0;
volatile u8  Global_u8StartFlag		=0;
volatile u8  Global_u8Data			=0;



void IR_voidGetFrame(void)
{
	if(Global_u8StartFlag == 0)
	{
		MSTK_voidSetIntervalSingle(1000000 , voidTickaction);
		Global_u8StartFlag =1;
	}
	else
	{
		Global_u32Fram[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000 , voidTickaction);
		Global_u8EdgeCounter++;
	}

}


void IR_voidTakeAction(void)
{
		switch(Global_u8Data)
	{
		case 70: GPIO_voidSetPinvalue(GPIOA , PIN1 , GPIO_HIGH);	break;
		case 69: GPIO_voidSetPinvalue(GPIOA , PIN1 , GPIO_LOW);		break;
	}
}

void IR_voidCheckFram(void)
{
		u8 Counter=0;
	Global_u8Data=0;
	if(Global_u32Fram[0] >= 10000 && Global_u32Fram[0]<=14000)
	{
			for(Counter =0 ; Counter<8 ; Counter++)
			{
				if( (Global_u32Fram[Counter+17] >=2000) && (Global_u32Fram[Counter +17]<=2300) )
				{
					SET_BIT(Global_u8Data,Counter);
				}
				else
				{
					CLR_BIT(Global_u8Data,Counter);
				}
			}
			play();
	}
	else
	{/*invalid fram*/}

	Global_u8StartFlag	=0;
	Global_u32Fram[0]  	=0;
	Global_u8EdgeCounter=0;
}
