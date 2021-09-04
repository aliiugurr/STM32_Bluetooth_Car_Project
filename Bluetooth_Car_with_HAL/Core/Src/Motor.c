#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include <Motor.h>



extern TIM_HandleTypeDef htim3;

extern UART_HandleTypeDef huart3;


void stop()
{
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	  __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
}

void forward(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
   	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
}

void back(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
}

void left()
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}
void right()
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}

void forwardLeft(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}

void forwardRight(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}

void backLeft(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}

void backRight(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Forward, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin_Backward, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, Speed);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 65);
}
void light(char c)
{
	switch(c)
	{
		case 'W':
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 'w':
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
			break;
		case 'U':
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 'u':
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
			break;
	}
}

