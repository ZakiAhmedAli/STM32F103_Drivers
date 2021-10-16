/********************************************************/
/*	Auther	    : zaki ahmed hamed						*/
/*  Date 	    : 16 September 2020						*/
/*  Description : SPI_config.h [SPI configuration file]	*/
/*  Version     : V01									*/
/********************************************************/


/**************************************************************************
* Description : Guard to Protect this file from include more than one time*
**************************************************************************/	
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/*please put in pair */
#define MSPI_SLAVE_PIN   		GPIOA,PIN0


/*	options : 1-IDLE_LOW
			  2-IDLE_HIGH
*/
#define CLOCK_POLARITY 			IDLE_HIGH

/*	options : 1-CPHA_LOW
			  2-CPHA_HIGH

*/
#define CLOCK_PHASE				CPHA_HIGH


/*	options	: 
			  1-MASTER
			  2-SLAVE
				
*/
#define MASTER_SLAVE_SELECT   	MASTER


/*	options : 1-FPCLK_DIV_2	
              2-FPCLK_DIV_4	
              3-FPCLK_DIV_8	
              4-FPCLK_DIV_16	
              5-FPCLK_DIV_32	
              6-FPCLK_DIV_64	
              7-FPCLK_DIV_128	
              8-FPCLK_DIV_256			  
*/

#define BAUD_ERATE		 		FPCLK_DIV_2

/*	options : 1-MSB_FIRST
			  2-LSB_FIRST
*/

#define DATA_ORDER				MSB_FIRST



/*	options : 1- _8BIT
			  2- _16BIT
*/
#define DATA_FORMAT				_8BIT

/* options : 1-SW_MANAGE_ENABLE
 	 	 	 2-SW_MANAGE_DISABLE*/
#define SW_SLAVE_MANAGE 		SW_MANAGE_ENABLE


#endif //SPI_CONFIG_H
