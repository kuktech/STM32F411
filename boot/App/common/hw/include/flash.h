#pragma once
#include "hw_def.h"

#ifdef _USE_HW_FLASH

bool flashInit();
bool flashErase(uint32_t addr, uint32_t length);
bool flashWrite(uint32_t addr, uint8_t *p_data, uint32_t length);
bool flashRead(uint32_t addr, uint8_t *p_data, uint32_t legnth);
 
#endif