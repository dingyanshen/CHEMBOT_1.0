/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f4xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stepper.h"
#include "relay.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define RxBuffer_Len 100
#define TxBuffer_Len 100
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
extern uint8_t RxBuffer[RxBuffer_Len];
extern uint8_t TxBuffer[TxBuffer_Len];
extern stepper z, a, b, pump7, pump8;
uint8_t RecCount;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart1;
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
 * @brief This function handles USART1 global interrupt.
 */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE) != RESET)
  {
    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    HAL_UART_DMAStop(&huart1);
    RecCount = RxBuffer_Len - __HAL_DMA_GET_COUNTER(huart1.hdmarx);

    if (RecCount == 3)
    {
      if (RxBuffer[0] == 'R')
        if (RxBuffer[1] == 'S')
          if (RxBuffer[2] == 'T')
          {
            reset(&a, &b, &z);
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"RST", 3);
          }

      if (RxBuffer[0] == 'A')
        if (RxBuffer[1] == 'T')
          if (RxBuffer[2] == 'T')
          {
            relay_attract();
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"ATT", 3);
          }

      if (RxBuffer[0] == 'R')
        if (RxBuffer[1] == 'L')
          if (RxBuffer[2] == 'S')
          {
            relay_release();
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"RLS", 3);
          }
    }

    if (RecCount == 15)
    {
      if (RxBuffer[0] == 'M')
        if (RxBuffer[1] == 'O')
          if (RxBuffer[2] == 'V')
          {
            double r, t, h;
            r = (RxBuffer[4] - 48) * 100 + (RxBuffer[5] - 48) * 10 + (RxBuffer[6] - 48);
            t = (RxBuffer[8] - 48) * 100 + (RxBuffer[9] - 48) * 10 + (RxBuffer[10] - 48) - 90;
            h = (RxBuffer[12] - 48) * 100 + (RxBuffer[13] - 48) * 10 + (RxBuffer[14] - 48);
            moveto(r, t, h, &a, &b, &z);
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"MOV", 3);
          }
    }

    if (RecCount == 10)
    {
      if (RxBuffer[0] == 'S')
        if (RxBuffer[1] == 'P')
          if (RxBuffer[2] == 'D')
          {
            double speed = (RxBuffer[6] - 48) * 1000 + (RxBuffer[7] - 48) * 100 + (RxBuffer[8] - 48) * 10 + (RxBuffer[9] - 48);
            if (speed < MIN_WIDTHSTEPPER)
              speed = MIN_WIDTHSTEPPER;
            if (speed > MAX_WIDTHSTEPPER)
              speed = MAX_WIDTHSTEPPER;
            if (RxBuffer[4] == 'A')
            {
              a.speed = speed;
              HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"SPD", 3);
            }
            if (RxBuffer[4] == 'B')
            {
              b.speed = speed;
              HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"SPD", 3);
            }
            if (RxBuffer[4] == 'Z')
            {
              z.speed = speed;
              HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"SPD", 3);
            }
          }
    }

    if (RecCount == 17)
    {
      if (RxBuffer[0] == 'P')
        if (RxBuffer[1] == 'M')
          if (RxBuffer[2] == 'P')
          {
            double volume, velocity;
            if (RxBuffer[4] == '7')
            {
              volume = (RxBuffer[6] - 48) * 100000 + (RxBuffer[7] - 48) * 10000 + (RxBuffer[8] - 48) * 1000 + (RxBuffer[9] - 48) * 100 + (RxBuffer[10] - 48) * 10 + (RxBuffer[11] - 48);
              velocity = (RxBuffer[13] - 48) * 1000 + (RxBuffer[14] - 48) * 100 + (RxBuffer[15] - 48) * 10 + (RxBuffer[16] - 48);
              pump(volume, velocity, &pump7);
              HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"PMP", 3);
            }
            if (RxBuffer[4] == '8')
            {
              volume = (RxBuffer[6] - 48) * 100000 + (RxBuffer[7] - 48) * 10000 + (RxBuffer[8] - 48) * 1000 + (RxBuffer[9] - 48) * 100 + (RxBuffer[10] - 48) * 10 + (RxBuffer[11] - 48);
              velocity = (RxBuffer[13] - 48) * 1000 + (RxBuffer[14] - 48) * 100 + (RxBuffer[15] - 48) * 10 + (RxBuffer[16] - 48);
              pump(volume, velocity, &pump8);
              HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"PMP", 3);
            }
          }
    }

    HAL_UART_Receive_DMA(&huart1, (uint8_t *)RxBuffer, RxBuffer_Len);
  }
  /* USER CODE END USART1_IRQn 1 */
}

/**
 * @brief This function handles DMA2 stream2 global interrupt.
 */
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
 * @brief This function handles DMA2 stream7 global interrupt.
 */
void DMA2_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream7_IRQn 0 */

  /* USER CODE END DMA2_Stream7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  /* USER CODE BEGIN DMA2_Stream7_IRQn 1 */

  /* USER CODE END DMA2_Stream7_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
