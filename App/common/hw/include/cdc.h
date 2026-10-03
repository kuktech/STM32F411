#pragma once
#include "hw_def.h"

#ifdef _USE_HW_CDC

bool cdcInit();
uint32_t cdcAvailable();
uint8_t cdcRead();
void cdcDataIn(uint8_t rx_data);
uint32_t cdcWrite(uint8_t *p_data, uint32_t length);
uint32_t cdcGetBaud();

#endif