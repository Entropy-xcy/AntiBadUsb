#include "led.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitStruct.GPIO_Pin =LED;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed =GPIO_Speed_Level_3;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_SetBits(GPIOA, LED);
}

void LED_Set(void)
{
	GPIO_SetBits(GPIOA, LED);
}

void LED_Reset(void)
{
	GPIO_ResetBits(GPIOA, LED);
}

void LED_Change(void)
{
	uint8_t state=GPIO_ReadInputDataBit(GPIOA,DATA_N);
	if(state==0)
	{
		LED_Set();
	}
	else
	{
		LED_Reset();
	}
}
