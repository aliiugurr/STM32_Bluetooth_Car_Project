#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include <UART.h>
#include <PWM.h>

#define MAX_SPEED		100

uint16_t speed_value;
uint16_t speed_level;

void UART_Init()
{
	RCC->APB1ENR |= (1 << 18); 		//USART3 Clock Enable

	USART3->CR1 |= (1 << 2); 		//RE=1 Receiver Enable
	USART3->CR1 |= (1 << 3); 		//TE=1 Transmitter Enable
	USART3->CR1 |= (1 << 5) | (1 << 7); 	// RXNEIE and TXEIE Enabled
	USART3->CR1 &= ~(1 << 10); 		// Parity control disable
	USART3->CR1 &= ~(1 << 12); 		// 1 Start bit, 8 Data bits, n Stop bit selected

	USART3->CR2 &= ~(1 << 12); 		// STOP bit selected 1 Stop bit

	USART3->BRR = 0x1117; 			// BaudRate 9600

	USART3->CR1 |= (1 << 13); 		//USART Enabled

	NVIC_EnableIRQ(USART3_IRQn);		//ENABLE interrupt for USART3 on NVIC side
}
uint8_t UART_GetChar(void)
{
	uint8_t data;

	while(!(USART3->SR & (1 << 5))); 	// Wait for RXNE to SET..
						// This indicates that the data has been Received
	data = USART3->DR; 			// Read the data
	return data;
}
void UART_SendChar(char c)
{
	while(!(USART3->SR & (1 << 7))); 	// Wait for TXE bit set...
						// This indicates that the data has been transmitted
	USART3->DR = c; 			// Load the data

}
void USART3_IRQHandler(void)
 {
	uint32_t incoming_data = UART_GetChar();	//for testing

	switch(incoming_data)
	{
		case '0': case '1': case '2': case '3':
			UART_SendChar(incoming_data);	//for testing
			speed_value = MAX_SPEED * 0;
			break;
		case '4': case '5': case '6':
			UART_SendChar(incoming_data);
			speed_value = MAX_SPEED - 50;
			break;
		case '7': case '8': case '9':
			UART_SendChar(incoming_data);
			speed_value = MAX_SPEED - 30;
			break;
		case 'q':
			UART_SendChar(incoming_data);
			speed_value = MAX_SPEED;
			break;
		case 'S':
			UART_SendChar(incoming_data);
			stop();
			break;
		case 'F':
			UART_SendChar(incoming_data);
			forward();
			break;
		case 'B':
			UART_SendChar(incoming_data);
			back();
			break;
		case 'L':
			UART_SendChar(incoming_data);
			left();
			break;
		case 'R':
			UART_SendChar(incoming_data);
			right();
			break;
		case 'G':
			UART_SendChar(incoming_data);
			forward_left();
			break;
		case 'I':
			UART_SendChar(incoming_data);
			forward_right();
			break;
		case 'H':
			UART_SendChar(incoming_data);
			back_left();
			break;
		case 'J':
			UART_SendChar(incoming_data);
			back_right();
			break;
		case 'W':
			UART_SendChar(incoming_data);
			light_on();
			break;
		case 'w':
			UART_SendChar(incoming_data);
			light_off();
	}

}
