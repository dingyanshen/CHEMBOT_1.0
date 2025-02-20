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
#include "crc.h"
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
    if (RxBuffer[0] == RecCount && check_crc(RxBuffer, RecCount))
    {
      switch (RxBuffer[1])
      {
      case 0x01:
        if (RxBuffer[2] == 0x01)
        {
          reset(&a, &b, &z);
        }
        else if (RxBuffer[2] == 0x02)
        {
        }
        else if (RxBuffer[2] == 0x03)
        {
        }
        else if (RxBuffer[2] == 0x04)
        {
        }
        uint8_t Data1[3] = {0x05, 0x01, 0x01};
        HAL_UART_Transmit_DMA(&huart1, add_crc(Data1), Data1[0]);
        break;
      case 0x02:;
        double speed = RxBuffer[3] * 256 + RxBuffer[4];
        if (RxBuffer[2] == 0x01)
        {
          if (speed < MIN_WIDTHSTEPPER)
            speed = MIN_WIDTHSTEPPER;
          if (speed > MAX_WIDTHSTEPPER)
            speed = MAX_WIDTHSTEPPER;
          z.speed = speed;
        }
        else if (RxBuffer[2] == 0x02)
        {
          if (speed < MIN_WIDTHSTEPPER)
            speed = MIN_WIDTHSTEPPER;
          if (speed > MAX_WIDTHSTEPPER)
            speed = MAX_WIDTHSTEPPER;
          a.speed = speed;
        }
        else if (RxBuffer[2] == 0x03)
        {
          if (speed < MIN_WIDTHSTEPPER)
            speed = MIN_WIDTHSTEPPER;
          if (speed > MAX_WIDTHSTEPPER)
            speed = MAX_WIDTHSTEPPER;
          b.speed = speed;
        }
        else if (RxBuffer[2] == 0x11)
        {
          if (speed < MIN_WIDTHPUMP)
            speed = MIN_WIDTHPUMP;
          if (speed > MAX_WIDTHPUMP)
            speed = MAX_WIDTHPUMP;
          pump7.speed = speed;
        }
        else if (RxBuffer[2] == 0x12)
        {
          if (speed < MIN_WIDTHPUMP)
            speed = MIN_WIDTHPUMP;
          if (speed > MAX_WIDTHPUMP)
            speed = MAX_WIDTHPUMP;
          pump8.speed = speed;
        }
        else if (RxBuffer[2] == 0x13)
        {
        }
        else if (RxBuffer[2] == 0x14)
        {
        }
        else if (RxBuffer[2] == 0x15)
        {
        }
        uint8_t Data2[3] = {0x05, 0x02, 0x01};
        HAL_UART_Transmit_DMA(&huart1, add_crc(Data2), Data2[0]);
        break;
      case 0x03:
        if (RxBuffer[2] == 0x01)
        {
          if (RxBuffer[3] == 0x01)
          {
            relay_attract();
          }
          else if (RxBuffer[3] == 0x02)
          {
            relay_release();
          }
        }
        else if (RxBuffer[2] == 0x02)
        {
        }
        uint8_t Data3[3] = {0x05, 0x03, 0x01};
        HAL_UART_Transmit_DMA(&huart1, add_crc(Data3), Data3[0]);
        break;
      case 0x04:;
        double r, t, h;
        r = RxBuffer[2];
        t = RxBuffer[3] - 90;
        h = RxBuffer[4];
        moveto(r, t, h, &a, &b, &z);
        uint8_t Data4[3] = {0x05, 0x04, 0x01};
        HAL_UART_Transmit_DMA(&huart1, add_crc(Data4), Data4[0]);
        break;
      case 0x05:
        if (RxBuffer[3] == 0x01)
        {
        }
        else if (RxBuffer[3] == 0x02)
        {
        }
        else if (RxBuffer[3] == 0x03)
        {
          double volume = RxBuffer[4] * 256 + RxBuffer[5];
          if (RxBuffer[2] == 0x11)
          {
            pump(volume, &pump7);
          }
          else if (RxBuffer[2] == 0x12)
          {
            pump(volume, &pump8);
          }
          else if (RxBuffer[2] == 0x13)
          {
          }
          else if (RxBuffer[2] == 0x14)
          {
          }
          else if (RxBuffer[2] == 0x15)
          {
          }
        }
        uint8_t Data5[3] = {0x05, 0x05, 0x01};
        HAL_UART_Transmit_DMA(&huart1, add_crc(Data5), Data5[0]);
        break;
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
