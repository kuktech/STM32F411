#pragma once
#include "def.h"
#include "stm32f4xx_hal.h"

#define _USE_LOG_PRINT      1

#if _USE_LOG_PRINT
#define logPrintf(fmt, ...)     printf(fmt, #__VA_ARGS__)
#else
#define loglogPrintf(fmt, ...);
#endif

void bspInit();

void delay(uint32_t ms);
uint32_t millis();

void SystemClock_Config();
void Error_Handler();