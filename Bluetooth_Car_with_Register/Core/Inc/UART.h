#ifndef INC_UART_H_
#define INC_UART_H_

void UART_Init();
uint8_t UART_GetChar(void);
void UART_SendChar(char c);

#endif /* INC_UART_H_ */
