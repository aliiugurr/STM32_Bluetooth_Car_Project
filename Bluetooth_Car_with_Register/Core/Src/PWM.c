#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"
#include <PWM.h>

extern uint16_t speed_value;

void TIM3_Init()
{
	//TIM3 Clock Enable
	RCC->APB1ENR |= (1 << 1);

	TIM3->CR1 &= ~(1 << 4); // DIR = 0 Counter used as upcounter
	TIM3->CR1 |= (0 << 5); // CMS = 00 Center-aligned mode selected Edge-aligned mode
	TIM3->CR1 |= (0 << 8); // CKD = 00 Clock division selected division 1

	//Channel 1 configuration
	TIM3->CCMR1 |= (0 << 0); //CC1S = 00 CC1 channel is configured as output.
	TIM3->CCMR1 |= (6 << 4); //OC1M = 110 PWM Mode 1 Selected
	//Channel 2 configuration
	TIM3->CCMR1 |= (0 << 8); //CC2S = 00 CC2 channel is configured as output
	TIM3->CCMR1 |= (6 << 12); //OC2M = 110 PWM Mode 1 selected

	TIM3->CCER |= (1 << 0); //Channel 1 output enable
	TIM3->CCER |= (1 << 4); //Channel 2 output enable

	TIM3->PSC = 83; // Prescaler value
	TIM3->ARR = 99; // Counter value, Frequency = 10KHz

	TIM3->CR1 |= (1 << 0); // Timer Enable
}
void stop()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset
	TIM3->CCR1 = 0;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset
	TIM3->CCR2 = 0;
}
void forward()
{
	GPIOE->BSRR |= (1 << 9); // Pin 9 set
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset
	TIM3->CCR2 = 0;
}
void back()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 10); // Pin 10 set
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset
	TIM3->CCR2 = 0;
}
void left()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset
	TIM3->CCR1 = 0;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset		turn right
	GPIOE->BSRR |= (1 << 12); //Pin 12 set			turn left
	TIM3->CCR2 = 50;
}
void right()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset
	TIM3->CCR1 = 0;
	GPIOE->BSRR |= (1 << 11); //Pin 11 set			turn right
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset		turn left
	TIM3->CCR2 = 50;
}
void forward_left()
{
	GPIOE->BSRR |= (1 << 9); // Pin 9 set			motor forward
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset		motor back
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset		turn right
	GPIOE->BSRR |= (1 << 12); //Pin 12 set			turn left
	TIM3->CCR2 = 50;
}
void forward_right()
{
	GPIOE->BSRR |= (1 << 9); // Pin 9 set			motor forward
	GPIOE->BSRR |= (1 << 26); // Pin 10 reset		motor back
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 11); //Pin 11 set			turn right
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset		turn left
	TIM3->CCR2 = 50;
}
void back_left()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 10); // Pin 10 set
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 27); //Pin 11 reset		turn right
	GPIOE->BSRR |= (1 << 12); //Pin 12 set			turn left
	TIM3->CCR2 = 50;
}
void back_right()
{
	GPIOE->BSRR |= (1 << 25); // Pin 9 reset
	GPIOE->BSRR |= (1 << 10); // Pin 10 set
	TIM3->CCR1 = speed_value;
	GPIOE->BSRR |= (1 << 11); //Pin 11 set			turn right
	GPIOE->BSRR |= (1 << 28); //Pin 12 reset		turn left
	TIM3->CCR2 = 50;
}
void light_on()
{
	GPIOD->BSRR |= (1 << 12) | (1 << 13) | (1 << 14) | (1 << 15);

}
void light_off()
{
	GPIOD->BSRR |= (1 << 28) | (1 << 29) | (1 << 30) | (1 << 31);
}
