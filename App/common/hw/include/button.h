#pragma once
#include "hw_def.h"
#ifdef _USE_HW_BUTTON

#define BUTTON_MAX_CH   HW_BUTTON_MAX_CH

bool buttonInit();
bool buttonGetPressed(uint8_t ch);

#endif

