#pragma once
#include "hw_def.h"

#ifdef _USE_HW_RTC

bool rtcInit();

uint32_t rtcBackupRegRead(uint32_t index);
void rtcBackupRegWrite(uint32_t index, uint32_t data);


#endif