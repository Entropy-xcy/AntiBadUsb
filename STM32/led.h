#ifndef __LED_H
#define __LED_H

#include "stm32f0xx.h"
#include "global.h"

void LED_Init(void);
void LED_Set(void);
void LED_Reset(void);
void LED_Change(void);

#endif
