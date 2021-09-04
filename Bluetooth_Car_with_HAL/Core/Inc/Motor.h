#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f407xx.h"

void stop();
void forward(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void back(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void left();
void right();
void forwardLeft(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void forwardRight(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void backLeft(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void backRight(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_Forward, uint16_t GPIO_Pin_Backward, uint8_t Speed);
void light(char c);

#endif /* INC_MOTOR_H_ */
