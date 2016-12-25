#include "stm32f0xx.h"
#include "usart.h"
#include "led.h"
#include "global.h"
#include "key.h"

uint8_t bufferP;
uint8_t bufferN;
uint8_t dete;
int feature[FTNUM][SEGLEN];
uint8_t check[FTNUM];
int state;
int Bstate;
int seg[SEGLEN];


void SystemInit(void){}

void FTInit(){
  feature[0][0]=1;feature[0][1]=0;feature[0][2]=1;feature[0][3]=0;feature[0][4]=1;
  feature[1][0]=1;feature[1][1]=0;feature[1][2]=1;feature[1][3]=2;feature[1][4]=1;
}
	
void seg_Init()
{
	int i;
	for(i=0;i<SEGLEN;i++)
	{
		seg[i]=5;
	}
	FTInit();
}

uint8_t detect1(){
	int i;
  for(i=0;i<SEGLEN;i++){
    if(seg[i]!=feature[0][i]){
      return 0;
    }
  }
  return 1;
}

uint8_t detect2(){
	int i;
  for(i=0;i<SEGLEN;i++){
    if(seg[i]!=feature[1][i]){
      return 0;
    }
  }
  return 1;
}

void pullDown()
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitStruct.GPIO_Pin =DATA_P | DATA_N;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed =GPIO_Speed_Level_3;
  GPIO_Init(GPIOA, &GPIO_InitStruct);
	GPIO_ResetBits(GPIOA, DATA_P|DATA_N);
}

void detected()
{
	pullDown();
	while(1)
	{
		UART_send_byte(10);
		LED_Set();
		delay(10);
		LED_Reset();
		delay(10);
	}
}


void pushState(int s)
{
	int i=0;
	for(i=1;i<SEGLEN;i++){
    seg[i-1]=seg[i];
  }
  seg[SEGLEN-1]=s;
}

void showSeg()
{
	int j=0;
	int i=0;
	for(i=0;i<SEGLEN;i++)
	{
		UART_send_byte(seg[i]);
	}
	for(j=0;j<(9-SEGLEN);j++)
	{
		UART_send_byte(9);
	}
}

int main (void)
{
	LED_Init();
	USART_Configuration();
	KEY_Init();
	seg_Init();
	while(1)
	{
		bufferP=DP_Read();
		bufferN=DN_Read();
		Bstate=getState(bufferP,bufferN);
		if(state!=Bstate)
		{
			state=Bstate;
			LED_Change();
			pushState(state);
			showSeg();
			if((detect1()==1) || (detect2()==1))
			{
				detected();
			}
		}
	}
}
