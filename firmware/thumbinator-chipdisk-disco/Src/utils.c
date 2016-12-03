#include "main.h"
#include "stm32f0xx_hal.h"
#include <stdio.h>      /* vsprintf */
#include <stdarg.h>     /* va_list, va_start, va_end */

extern UART_HandleTypeDef huart1;

void uart_printf(const char* format, ...) {
    va_list arglist;
    va_start(arglist, format);
    char data[128];
    int len = vsprintf(data, format, arglist);
    va_end(arglist);
    HAL_UART_Transmit(&huart1, (uint8_t*) data, len, 10);
}
