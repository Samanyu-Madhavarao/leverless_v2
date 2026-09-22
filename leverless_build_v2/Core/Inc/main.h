/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#define SELECT_Pin GPIO_PIN_4
#define SELECT_GPIO_Port GPIOA
#define START_Pin GPIO_PIN_5
#define START_GPIO_Port GPIOA
#define LEFT_Pin GPIO_PIN_6
#define LEFT_GPIO_Port GPIOA
#define DOWN_Pin GPIO_PIN_7
#define DOWN_GPIO_Port GPIOA
#define RIGHT_Pin GPIO_PIN_4
#define RIGHT_GPIO_Port GPIOC
#define UP_Pin GPIO_PIN_5
#define UP_GPIO_Port GPIOC
#define B01_Pin GPIO_PIN_12
#define B01_GPIO_Port GPIOB
#define B05_Pin GPIO_PIN_13
#define B05_GPIO_Port GPIOB
#define B09_Pin GPIO_PIN_14
#define B09_GPIO_Port GPIOB
#define B02_Pin GPIO_PIN_15
#define B02_GPIO_Port GPIOB
#define B06_Pin GPIO_PIN_6
#define B06_GPIO_Port GPIOC
#define B03_Pin GPIO_PIN_7
#define B03_GPIO_Port GPIOC
#define B07_Pin GPIO_PIN_8
#define B07_GPIO_Port GPIOC
#define B04_Pin GPIO_PIN_9
#define B04_GPIO_Port GPIOC
#define B08_Pin GPIO_PIN_8
#define B08_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
