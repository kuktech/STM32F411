#pragma once
#include "hw_def.h"

#ifdef _USE_HW_RESET

bool resetInit();

uint32_t resetGetCount();
#endif