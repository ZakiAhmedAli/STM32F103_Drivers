/*************************************************************************/
/* Description : ESP_interface.h file contain public Functions and macros*/
/* Auher	   : Zaki Ahmed Hamed										 */
/* Data		   : 30 Sep 2020											 */
/* version	   : V01													 */
/*************************************************************************/



/***********************************************************************/
/* Description : Guard to protect file to include more than one time   */
/***********************************************************************/
#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H



/****************************************************/
/* Function Name 		: ESP_voidInit				*/
/* Function Description : used to intialize ESP8266 */
/* Return	   			: void	 				    */
/* Input	   			: void	 				    */
/****************************************************/
void ESP_voidInit(void);

/****************************************************************/
/* Function Name 		: ESP_voidConnectWifi					*/
/* Function Description : used to connect to WiFi   			*/
/* Return	   			: void	 				    			*/
/* Input	   			: u8 *Copy_u8WifiName, u8 *Copy_u8Pass	*/
/****************************************************************/
void ESP_voidConnectWifi(u8 *Copy_u8WifiName, u8 *Copy_u8Pass);

/********************************************************************/
/* Function Name 		: ESP_voidConnectTOServer					*/
/* Function Description : used to connect to Server Send http Request*/
/* Return	   			: void	 				    				*/
/* Input	   			: u8* Copy_u8StrIP, u8* Copy_u8Port			*/
/********************************************************************/
void ESP_voidConnectTOServer(u8* Copy_u8StrIP, u8* Copy_u8Port);



/*************************************************************/
/* Function Name 		: ESP_voidSendToServer				 */
/* Function Description : Receive http Request  			 */
/* Return	   			: u8	 				    		 */
/* Input	   			: u8 Copy_u8URLLength,u8 * Copy_u8URL*/
/*************************************************************/
u8 ESP_voidSendToServer(u8 Copy_u8URLLength,u8 * Copy_u8URL);



#endif //end of guard	
