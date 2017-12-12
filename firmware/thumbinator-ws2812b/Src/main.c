/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"

/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdint.h>

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

static void next_led(void) {
  static int i = 0;
  i = (i + 1) % 16;
  HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, (i & 1) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, (i & 2) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, (i & 4) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

const uint8_t pixels_test[] = {
/*
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
*/
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
	0b10101010,
/*
	255, 255, 255,
	127, 127,   0,
	  0, 127, 127,
	  0,   0, 127,
	127,   0,   0,
*/
};


uint8_t pixels[3 * 144 * 2];

#define ARRAY_SIZE(x) sizeof(x)/sizeof((x)[0])

#define GPIO_SET(GPIOx, GPIO_Pin) do {			\
			GPIOx->BSRR = (uint32_t)GPIO_Pin;	\
		} while (0)

#define GPIO_RESET(GPIOx, GPIO_Pin) do {		\
			GPIOx->BRR = (uint32_t)GPIO_Pin;	\
		} while (0)


#pragma GCC optimize ("-O3")
static void ws2812b_write(uint8_t *p_buf, size_t num_elements, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t *end = p_buf + num_elements;
	uint8_t p = *p_buf++;
	uint8_t bitMask = 0x80;

	//GPIO_SET(GPIOx, GPIO_Pin);

	for (;;) {
		GPIO_SET(GPIOx, GPIO_Pin);
		if (p & bitMask) {
			__asm("nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop;");
			GPIO_RESET(GPIOx, GPIO_Pin);
			__asm("nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop;");
		} else {
			__asm("nop; nop; nop; nop; nop; nop; nop; nop;"
				  "nop; nop; nop; nop; nop;");
			GPIO_RESET(GPIOx, GPIO_Pin);
			__asm("nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop; nop; nop; nop; nop; nop; nop;"
					"nop; nop;");
		}

		if(bitMask >>= 1) {
			__asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
		} else {
			if (p_buf >= end) break;
			p = *p_buf++;
			bitMask = 0x80;
		}
	}

	HAL_Delay(1);
}

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  static uint32_t t = 0;
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
    //next_led();

	//HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin));

	ws2812b_write(pixels, sizeof(pixels), CONN_12_GPIO_Port, CONN_12_Pin);

	for (int i = 0; i < sizeof(pixels); i += 3) {
#if 0
		pixels[i + 0] = (i + t) % 30;
		pixels[i + 1] = 0;
		pixels[i + 2] = 0;
#elif 1
		pixels[i + 0] = 1;
		pixels[i + 1] = 1;
		pixels[i + 2] = 1;
#else

#endif
	}
	t += 1;

    //HAL_Delay(250);

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_0_Pin|LED_1_Pin|LED_2_Pin|LED_3_Pin
                          |CONN_11_Pin|CONN_10_Pin|CONN_9_Pin|CONN_8_Pin
                          |CONN_7_Pin|CONN_6_Pin|CONN_5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CONN_12_GPIO_Port, CONN_12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : BUTTON_0_Pin */
  GPIO_InitStruct.Pin = BUTTON_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BUTTON_0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_0_Pin LED_1_Pin LED_2_Pin LED_3_Pin
                           CONN_11_Pin CONN_10_Pin CONN_9_Pin CONN_8_Pin
                           CONN_7_Pin CONN_6_Pin CONN_5_Pin */
  GPIO_InitStruct.Pin = LED_0_Pin|LED_1_Pin|LED_2_Pin|LED_3_Pin
                          |CONN_11_Pin|CONN_10_Pin|CONN_9_Pin|CONN_8_Pin
                          |CONN_7_Pin|CONN_6_Pin|CONN_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : CONN_12_Pin */
  GPIO_InitStruct.Pin = CONN_12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(CONN_12_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */

/**
  * @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
