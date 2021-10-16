#ifndef UART_CONFIG_H
#define UART_CONFIG_H


/*	Options : _1STOP_BIT
			  _0.5STOP_BIT
			  _1.5STOP_BIT
			  _2STOP_BIT
*/
#define STOP_BIT	_1STOP_BIT


/* Options : _8BIT_DATA
			 _16BIT_DATA
			 */
#define WORD_LENGTH		_8BIT_DATA

/* Options :

			//Clock: 1 MHz 
			#define UART_BAUDRATE_1200_CLK_1M       0X0341
			#define UART_BAUDRATE_2400_CLK_1M       0X01A0
			#define UART_BAUDRATE_4800_CLK_1M       0X00D0
			#define UART_BAUDRATE_9600_CLK_1M       0X0068
			#define UART_BAUDRATE_19200_CLK_1M      0X0034
			//Clock: 8 MHz 
			#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
			#define UART_BAUDRATE_2400_CLK_8M       0X0D05
			#define UART_BAUDRATE_4800_CLK_8M       0X0683
			#define UART_BAUDRATE_9600_CLK_8M       0X0341
			#define UART_BAUDRATE_19200_CLK_8M      0X01A1

*/

#define BAUDE_RATE		UART_BAUDRATE_9600_CLK_8M

#endif //UART_CONFIG_H
