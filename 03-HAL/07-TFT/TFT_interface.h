#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

// ST7735 ROUTINES
#define SWRESET 	0x01 // software reset
#define SLPOUT  	0x11 // sleep out
#define DISPOFF 	0x28 // display off
#define DISPON  	0x29 // display on
#define CASET   	0x2A // column address set
#define RASET 		0x2B // row address set
#define RAMWR 		0x2C // RAM write
#define MADCTL  	0x36 // axis control
#define COLORMOD  	0x3A // color mode
// 1.8" TFT display constants
#define XSIZE		128
#define YSIZE		160
#define XMAX 		XSIZE-1
#define YMAX 		YSIZE-1


// Color consants
#define BLACK		0x0000
#define BLUE 		0x001F
#define RED  		0xF800
#define GREEN		0x0400
#define LIME 		0x07E0
#define CYAN 		0x07FF
#define MAGENTA 	0xF81F
#define YELLOW 		0xFFE0
#define WHITE 		0xFFFF
/**********************************************************/
/*	Description : this function is used to initialize TFT */
/*	Input       : void									  */
/*	Return      : void									  */
/**********************************************************/
void HTFT_voidInit(void);

/****************************************************************/
/*	Description : this function is used to Display image on TFT */
/*	Input       : pointer to draw image on TFT				    */
/*	Return      : void									        */
/****************************************************************/
void HTFT_voidDisplayImage(const u16 *Coyp_Image);

/****************************************************************/
/*	Description : this function is used to Full TFT color 	    */
/*	Input       : variable to fill color on TFT				    */
/*	Return      : void									        */
/****************************************************************/
void HTFT_voidFillColor( u16 Coyp_Image);

/********************************************************************/
/*	Function Name: HTFT_voidDrawRectangle							*/
/*	Description  : this function is used to Draw rectangle 	    	*/
/*	Input        : u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Coyp_u16Color	*/
/*	Return       : void									        	*/
/********************************************************************/
void HTFT_voidDrawRectangle( u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Coyp_u16Color);

/****************************************************************************/
/*	Function Name: HTFT_voidWriteChar										*/
/*	Description  : this function is used to Draw charracters on TFT 	    */
/*	Input        : u8* copy_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color	*/
/*	Return       : void									        			*/
/****************************************************************************/
void HTFT_voidWriteChar(u8* copy_u8Char , u8 Xaxis , u8 Yaxis , u16 Copy_u8Color);





#endif
