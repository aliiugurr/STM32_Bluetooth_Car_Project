#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"
#include <GPIO.h>


void GPIO_Init(void)
{
	/*
	 * GPIOA Timer 3 PWM PA6 = Channel 1 PA7 Channel 3
	 * GPIOB Bluetooth UART communication for microcontroller B10 TX, B11 RX
	 * GPIOE Motor Control forward, back vs..
	 */
	//GPIO A, B, D, E, H Clock Enable
	RCC->AHB1ENR |= (1 << 0) | (1 << 1) | (1 << 3) | (1 << 4) | (1 << 7);

	//GPIOA PA6 and PA7 selected alternate function mode
	GPIOA->MODER |= (2 << 12) | (2 << 14);
	//GPIOB PB6 and PB7 selected alternate function mode
	GPIOB->MODER |= (2 << 20) | (2 << 22);
	//GPIOD PD12, PD13, PD14, PD15 selected output mode
	GPIOD->MODER |= (1 << 24) | (1 << 26) | (1 << 28) | (1 << 30);
	//GPIOE PE9, PE10, PE11 and PE12 selected General purpose output mode
	GPIOE->MODER |= (1 << 18) | (1 << 20) | (1 << 22) | (1 << 24);

	//GPIOE PE9, PE10, PE11 and PE12 selected Output push-pull
	GPIOE->OTYPER |= (0 << 9) | (0 << 10) | (0 << 11) | (0 << 12);
	//GPIOD PD12, PD13, PD14 and PD15 selected Output push-pull
	GPIOD->OTYPER |= (0 << 12) | (0 << 13) | (0 << 14) | (0 << 15);


	//GPIOE PE9, PE10, PE11 and PE12 selected high speed
	GPIOE->OSPEEDR |= (2 << 18) | (2 << 20) | (2 << 22) | (2 << 24);
	//GPIOD PD12, PD13, PD14 and PD15 selected low speed
	GPIOD->OSPEEDR |= (0 << 24) | (0 << 26) | (0 << 28) | (0 << 30);

	//GPIOE PE9, PE10, PE11 and PE12 selected no pull-up/down
	GPIOE->PUPDR |= (0 << 18) | (0 << 20) | (0 << 22) | (0 << 24);
	//GPIOD PD12, PD13, PD14 and PD15 selected no pull-up/down
	GPIOD->PUPDR |= (0 << 24) | (0 << 26) | (0 << 28) | (0 << 30);

	//GPIOA PA6 and PA7 selected AF2 in AFRL register (TIM3 Selected)
	GPIOA->AFR[0] = (2 << 24) | (2 << 28);
	//GPIOA PB10 and PB11 selected AF7 in AFRH register (UART3 Selected)
	GPIOB->AFR[1] = (7 << 8) | (7 << 12);
}
