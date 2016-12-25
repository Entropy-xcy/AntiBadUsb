#ifndef __KEY_H
#define	__KEY_H

#include "stm32f0xx.h"
#include "global.h"

void KEY_Init(void);
uint8_t DP_Read(void);
uint8_t DN_Read(void);
#endif
