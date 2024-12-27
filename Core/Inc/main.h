/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SWITCH1_Pin GPIO_PIN_2
#define SWITCH1_GPIO_Port GPIOE
#define SWITCH1_EXTI_IRQn EXTI2_IRQn
#define SWITCH2_Pin GPIO_PIN_3
#define SWITCH2_GPIO_Port GPIOE
#define SWITCH2_EXTI_IRQn EXTI3_IRQn
#define SWITCH3_Pin GPIO_PIN_4
#define SWITCH3_GPIO_Port GPIOE
#define SWITCH3_EXTI_IRQn EXTI4_IRQn
#define SWITCH4_Pin GPIO_PIN_5
#define SWITCH4_GPIO_Port GPIOE
#define SWITCH4_EXTI_IRQn EXTI9_5_IRQn
#define SWITCH5_Pin GPIO_PIN_6
#define SWITCH5_GPIO_Port GPIOE
#define SWITCH5_EXTI_IRQn EXTI9_5_IRQn
#define DIR3_Pin GPIO_PIN_7
#define DIR3_GPIO_Port GPIOC
#define STEP3_Pin GPIO_PIN_8
#define STEP3_GPIO_Port GPIOC
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOC
#define DIR2_Pin GPIO_PIN_9
#define DIR2_GPIO_Port GPIOA
#define STEP2_Pin GPIO_PIN_10
#define STEP2_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_11
#define EN2_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define DIR1_Pin GPIO_PIN_2
#define DIR1_GPIO_Port GPIOD
#define STEP1_Pin GPIO_PIN_3
#define STEP1_GPIO_Port GPIOD
#define EN1_Pin GPIO_PIN_4
#define EN1_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
