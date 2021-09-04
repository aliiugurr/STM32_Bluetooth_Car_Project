/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include <Motor.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define forwardPin		(uint16_t)GPIO_PIN_9
#define backwardPin		(uint16_t)GPIO_PIN_10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
char rx_buffer[50];
uint8_t speed_value;
//char state[1];
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart3;
/* USER CODE BEGIN EV */
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */

  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */
  if (HAL_UART_Receive_IT(&huart3, (uint8_t*) rx_buffer, 50) != HAL_OK)
    {
	  int i = 0;
	  int j = 0;

  	  for( j = 0; j < 50; j++)
  	  {
  		  if (rx_buffer[j] == 'S')
  		  {
  			  stop();
  			  for( i = 0; i < 50; i++) //Clear the rx_buffer for new incoming data
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == '0' || rx_buffer[j] == '1' || rx_buffer[j] == '2' )
  		  {
  			  speed_value = 0;
  			  for ( i = 0; i < 50; i++) //Clear the rx_buffer for new incoming data
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == '3' || rx_buffer[j] == '4' || rx_buffer[j] == '5' || rx_buffer[j] == '6' )
  		  {
  			  speed_value = 60;
  			  for ( i = 0; i < 50; i++) //Clear the rx_buffer for new incoming data
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == '7' || rx_buffer[j] == '8' || rx_buffer[j] == '9' || rx_buffer[j] == 'q' )
  		  {
  			  speed_value = 100;
  			  for ( i = 0; i < 50; i++) //Clear the rx_buffer for new incoming data
  			  {
  				  rx_buffer[i] = 0;		// or user can use memset() function ( etc. memset(rx_buffer,0,50) )
  			  }
  		  }
  		  else if (rx_buffer[j] == 'F')
  		  {
  			  forward(GPIOE, forwardPin, backwardPin, speed_value);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'B')
  		  {
  			  back(GPIOE, forwardPin, backwardPin, speed_value);
  			  
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;		
  			  }
  		  }
  		  else if (rx_buffer[j] == 'L')
  		  {
  			  left();
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'R')
  		  {
  			  right();
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'G')
  		  {
  			  forwardLeft(GPIOE, forwardPin, backwardPin, speed_value);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'I')
  		  {
  			  forwardRight(GPIOE, forwardPin, backwardPin, speed_value);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'H')
  		  {
  			  backLeft(GPIOE, forwardPin, backwardPin, speed_value);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if (rx_buffer[j] == 'J')
  		  {
  			  backRight(GPIOE, forwardPin, backwardPin, speed_value);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == 'W')// front light on
  		  {
  			  light(rx_buffer[j]);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == 'w')//front light off
  		  {
  			  light(rx_buffer[j]);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == 'U')//back light on
  		  {
  			  light(rx_buffer[j]);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  		  else if(rx_buffer[j] == 'u')//back light off
  		  {
  			light(rx_buffer[j]);
  			  for( i = 0; i < 50; i++)
  			  {
  				  rx_buffer[i] = 0;
  			  }
  		  }
  	  }
    }

  /* USER CODE END USART3_IRQn 1 */
}

/* USER CODE BEGIN 1 */
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
