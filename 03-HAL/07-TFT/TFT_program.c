#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"GPIO_init.h"
#include"MSTK_init.h"
#include "SPI_init.h"

#include"TFT_interface.h"
#include"TFT_private.h"
#include"TFT_config.h"



void HTFT_voidInit(void)
{
		/*Reset pulse*/
		/* make Reset pin HIGH*/
		GPIO_voidSetPinvalue(TFT_RST_PIN, GPIO_HIGH);
		/*wait 100 microsecond*/
		MSTK_voidSetBusyWait(100);
		/* make Reset pin LOW*/
		GPIO_voidSetPinvalue(TFT_RST_PIN, GPIO_LOW);
		/*wait 1 microsecond*/
		MSTK_voidSetBusyWait(1);

		/* make Reset pin HIGH*/
		GPIO_voidSetPinvalue(TFT_RST_PIN, GPIO_HIGH);
		/*wait 100 microsecond*/
		MSTK_voidSetBusyWait(100);

		/* make Reset pin LOW*/
		GPIO_voidSetPinvalue(TFT_RST_PIN, GPIO_LOW);
		/*wait 100 microsecond*/
		MSTK_voidSetBusyWait(100);

		/* make Reset pin HIGH*/
		GPIO_voidSetPinvalue(TFT_RST_PIN, GPIO_HIGH);
		/*wait 120 MS*/
		MSTK_voidSetBusyWait(120000);

		/*sleep out command */
		voidWriteCommand(SLPOUT);
		/*wait 150 MS*/
		MSTK_voidSetBusyWait(150000);

		/*color mode command*/
		voidWriteCommand(COLORMOD);
		
		/*command color mode parameter, mode 5 = 16bit pixels (RGB565)*/
		voidWriteData	(0x05);

		/* display on command*/
		voidWriteCommand(DISPON);
		
		/* Remap TFT addresses ( x = 0 , y = 0 Start From The Left Top Of The TFT ) */
				
		voidWriteCommand(MADCTL);
		
		voidWriteData	(0xC0);


}

void HTFT_voidDisplayImage(const u16 *Coyp_Image)
{
	u16 Counter;
	u8 data;
	/*set x address*/
	voidWriteCommand(0x2A);
	/*write start parameter in 2byte 0,0*/
	voidWriteData(0);
	voidWriteData(0);
	/*write end parameter in 2byte 0,127*/
	voidWriteData(0);
	voidWriteData(127);


	//set y address
	voidWriteCommand(0x2B);
	/*write start parameter in 2byte 0,0*/
	voidWriteData(0);
	voidWriteData(0);
	/*write end parameter in 2byte 0,159*/
	voidWriteData(0);
	voidWriteData(159);

	//RAM write command
	voidWriteCommand(0x2C);

	for(Counter =0 ; Counter <20480 ; Counter++)
	{
		/*write high byte*/
		data = Coyp_Image[Counter] >>8;
		voidWriteData(data);

		/*write low byte*/
		data = Coyp_Image[Counter] & 0x00ff;
		voidWriteData(data);
	}
}

/*0x0000[black] : 0xFFFF[white]*/
void HTFT_voidFillColor( u16 CopY_u16Color)
{
	u8 LOC_u8CountX ;
	u8 LOC_u8CountY ;
	u8 LOC_u8Data	;
	
	for( LOC_u8CountY = 0 ; LOC_u8CountY < YSIZE ; LOC_u8CountY++ )
	{
			
		voidWriteCommand( CASET	 	  );/*set x address*/
		voidWriteData	( 0		 	  );/*write start parameter in 2byte 0,0*/
		voidWriteData	( 0		 	  );
		voidWriteCommand( RASET	 	  );// set row range (y0,y1)
		voidWriteData	( 0		 	  );/*write end parameter in 2byte 0,159*/
		voidWriteData	( LOC_u8CountY);
		voidWriteCommand( RAMWR		  );		/*RAM write command*/

		
		for ( LOC_u8CountX = 0 ; LOC_u8CountX < XSIZE ; LOC_u8CountX++ )
		{
			/*write high byte*/
			LOC_u8Data = CopY_u16Color >>8;
			voidWriteData(LOC_u8Data);

			/*write low byte*/
			LOC_u8Data = CopY_u16Color & 0x00ff;
			voidWriteData(LOC_u8Data);
		}
	}
		
}
			

void HTFT_voidDrawRectangle( u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Coyp_u16Color)
{
	u16 Counter;
	u8 data;
	u16 size=(x2-x1+1) * (y2 -y1+1);
	/*set x address*/
	voidWriteCommand(0x2A);
	/*write start parameter in 2byte 0,0*/
	voidWriteData(0);
	voidWriteData(x1);
	/*write end parameter in 2byte 0,127*/
	voidWriteData(0);
	voidWriteData(x2);


	//set y address
	voidWriteCommand(0x2B);
	/*write start parameter in 2byte 0,0*/
	voidWriteData(0);
	voidWriteData(y1);
	/*write end parameter in 2byte 0,159*/
	voidWriteData(0);
	voidWriteData(y2);

	/*RAM write command*/
	voidWriteCommand(0x2C);

	for(Counter =0 ; Counter <size ; Counter++)
	{
		/*write high byte*/
		data = Coyp_u16Color >>8;
		voidWriteData(data);

		/*write low byte*/
		data = Coyp_u16Color & 0x00ff;
		voidWriteData(data);
	}
}

void HTFT_voidWriteChar(u8* copy_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color)
{
	u8  LOC_u8Mask = 0x80 ;
	u8  LOC_u8DataMasked  ;
	u16 LOC_u8Pixel       ;

	// Set The Position Of 5x7 Character
	for( u8 LOC_u8Iterator1 = 0 ; LOC_u8Iterator1 < TFT_CHAR_WIDTH ; LOC_u8Iterator1++ )
	{

		for( u8 LOC_u8Iterator2 = 0 ; LOC_u8Iterator2 < TFT_CHAR_HIGHT ; LOC_u8Iterator2++ )
		{
			// set column range (x0,x1)
			voidWriteCommand(CASET);

			voidWriteData(LOC_u8Iterator1 + Xaxis);
			voidWriteData(LOC_u8Iterator1 + Xaxis);

			// set row range (y0,y1)
			voidWriteCommand(RASET);

			voidWriteData(LOC_u8Iterator2 + Yaxis);
			voidWriteData(LOC_u8Iterator2 + Yaxis);

			//RAM write command
			voidWriteCommand(RAMWR);

			LOC_u8DataMasked = copy_u8Char[ LOC_u8Iterator1 ] & (LOC_u8Mask) ;

			if( LOC_u8DataMasked == 0  ) { LOC_u8Pixel = 0x0000       ; }
			else                         { LOC_u8Pixel = Copy_u8Color ; }

			voidWriteData(LOC_u8Pixel >> 8);
			voidWriteData(LOC_u8Pixel & 0xFF);

			LOC_u8Mask >>= 1 ;
		}

		LOC_u8Mask = 0x80 ;
	}


}


static void voidWriteCommand(u8 Copy_u8CMD)
{
	u8 LOC_u8Var;
	/*set A0 pin low*/
	GPIO_voidSetPinvalue(TFT_A0_PIN, GPIO_LOW);
	/* send command over SPI*/
	MSPI_voidSendRecieveSynch(0 ,Copy_u8CMD , &LOC_u8Var);
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 LOC_u8Var=0;
		/*set A0 pin high*/
	GPIO_voidSetPinvalue(TFT_A0_PIN, GPIO_HIGH);
	/* send data over SPI*/
	MSPI_voidSendRecieveSynch(0 ,Copy_u8Data , &LOC_u8Var);

}
