#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H



/****************************************************/
/* Description : private function used to send data */
/* Input	   : Data to send by SPI				*/
/* Return	   : void(NO Thing)						*/
/****************************************************/
static void voidWriteData(u8 Copy_u8Data);

/*******************************************************/
/* Description : private function used to send command */
/* Input	   : command to send by SPI				   */
/* Return	   : void(NO Thing)						   */
/*******************************************************/
static void voidWriteCommand(u8 Copy_u8CMD);


#endif
