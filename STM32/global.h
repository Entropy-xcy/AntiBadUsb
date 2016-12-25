#ifndef __GLOBAL_H
#define	__GLOBAL_H

#include "stm32f0xx.h"
#define DATA_P GPIO_Pin_1
#define DATA_N GPIO_Pin_0
#define LED GPIO_Pin_4
#define SEGLEN 5
#define FTNUM 2

void delay(int time);
int getState(uint8_t P,uint8_t N);

#endif
