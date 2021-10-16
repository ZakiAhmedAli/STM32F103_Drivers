/*************************************************************************************/
/* Description : ESP_program.c file this file contain ESP8266 function implementation*/
/* Auher	   : Zaki Ahmed Hamed										 			 */
/* Data		   : 30 Sep 2020											 			 */
/* version	   : V01													             */
/*************************************************************************************/

/* included library*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*include MCAL*/

#include "UART_interface.h"
/**/
#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"
#include <stdio.h>
#include <string.h>

u8 Global_u8Action;


void ESP_voidInit(void)
{
	u8 LOC_u8Result=0;
	while(LOC_u8Result ==0)
	{
		/*stop echo*/
		MUART_voidTransmit(UART_ONE, (u8 *)"ATE0\r\n");
		LOC_u8Result = ESP_u8ValidateCmd();
	}
	LOC_u8Result =0;

	while(LOC_u8Result ==0)
	{
		/*set station mode*/
		MUART_voidTransmit(UART_ONE ,(u8 *)"AT+CWMODE=1\r\n");
		/* Check if CMD was sent correctly */
		LOC_u8Result = ESP_u8ValidateCmd();
	}
}

void ESP_voidConnectWifi(u8 *Copy_u8WifiName, u8 *Copy_u8Pass)
{
	u8 LOC_8uResult = 0;

	while(LOC_8uResult ==0)
	{
		/*Connect to WiFi*/
		MUART_voidTransmit(UART_ONE ,(u8 *)"AT+CWJAP_CUR=\"");
		MUART_voidTransmit(UART_ONE ,Copy_u8WifiName);
		MUART_voidTransmit(UART_ONE ,(u8 *)"\",\"");
		MUART_voidTransmit(UART_ONE ,Copy_u8Pass);
		MUART_voidTransmit(UART_ONE ,(u8 *)"\"\r\n");
		/*receive response*/
		LOC_8uResult = ESP_u8ValidateCmd();
	}
}

void ESP_voidConnectTOServer(u8 *Copy_u8StrIP, u8 *Copy_u8Port)
{
	u8 LOC_8uResult=0;
	while(LOC_8uResult == 0)
	{
		/*1-send mode*/
		MUART_voidTransmit(UART_ONE ,(u8 *)"AT+CIPSTART=\"TCP\",\"");
		MUART_voidTransmit(UART_ONE ,Copy_u8StrIP);
		MUART_voidTransmit(UART_ONE ,(u8 *)"\",");
		MUART_voidTransmit(UART_ONE ,Copy_u8Port);
		MUART_voidTransmit(UART_ONE ,(u8 *)"\r\n");
		/*receive response*/
		LOC_8uResult = ESP_u8ValidateCmd();
	}

}

u8 ESP_voidSendToServer(u8 Copy_u8URLLength, u8 *Copy_u8URL)
{
	u8 LOC_8uResult=0;
	
	u8 Data_String1[15] ={0};
	u8 Data_String2[46] ={0};
	sprintf(Data_String1,"%s%d%s","AT+CIPSEND=",Copy_u8URLLength,"\r\n");

	while(LOC_8uResult == 0)
	{
		MUART_voidTransmit(UART_ONE , Data_String1);
		//receive response
		LOC_8uResult = ESP_u8ValidateCmd();
	}

	LOC_8uResult=0;
	sprintf(Data_String2,"%s%s%s","GET http://",Copy_u8URL,"/status.txt\r\n");
	while(LOC_8uResult == 0)
	{
		MUART_voidTransmit(UART_ONE ,Data_String2);

		//receive response
		LOC_8uResult = ESP_u8ValidateCmd();
	}

	/*while(LOC_8uResult == 0)
	{
		MUART_voidTransmit(UART_ONE ,"AT+CIPSEND=");
		MUART_voidTransmit(UART_ONE ,Copy_u8URLLength);
		MUART_voidTransmit(UART_ONE ,"\r\n");

		//receive response
		LOC_8uResult = ESP_u8ValidateCmd();
	}

	LOC_8uResult=0;
	while(LOC_8uResult == 0)
	{
		MUART_voidTransmit(UART_ONE ,"GET http://");
		MUART_voidTransmit(UART_ONE ,Copy_u8URL);
		MUART_voidTransmit(UART_ONE ,"/status.txt\r\n");

		//receive response
		LOC_8uResult = ESP_u8ValidateCmd();
	}*/

	return  Global_u8Action;
}

static u8 ESP_u8ValidateCmd(void)
{
	u8 LOC_u8Response[100]={0};
	u8 Counter	= 0;
	u8 Result 	= 0;
	u8 Dummy	= 0;

	while( Counter <= 100)
	{
		Dummy = MUART_u8Receive(UART_ONE);
		LOC_u8Response[Counter] = Dummy;
		Counter++;
	}

	for(u8 i=0;i<70;i++)
	{
		if(LOC_u8Response[i]==':')
		{
			Global_u8Action = LOC_u8Response[i+1];
		}
	}

	for(u8 i =0 ; i<100 ; i++)
	{
		//check if OK
		if(LOC_u8Response[i] =='O' && LOC_u8Response[i+1] =='K')
		{
			Result = 1;
			break;
		}
	}
	return Result;
}

