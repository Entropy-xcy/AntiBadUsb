#include "key.h"

void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitStruct.GPIO_Pin = DATA_N | DATA_P;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_Level_2;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_SetBits(GPIOA, DATA_N | DATA_P);
}

uint8_t DP_Read(void)
{
	return GPIO_ReadInputDataBit(GPIOA,DATA_P);
}

uint8_t DN_Read(void)
{
	return GPIO_ReadInputDataBit(GPIOA,DATA_N);
}
