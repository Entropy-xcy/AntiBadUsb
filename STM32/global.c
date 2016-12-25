#include "global.h"

void delay(int time) 
{     
   int i=0;   
   while(time--) 
   {
      i=12000;
      while(i--){}
   } 
}

int getState(uint8_t P,uint8_t N)
{
	int Bstate;
	if(P==0 && N==0){
    Bstate=0;
    }
   if(P==1 && N==0){
    Bstate=1;
   }
   if(P==0 && N==1){
    Bstate=-1;
   }
   if(P==1 && N==1){
    Bstate=2;
   }
   return Bstate;
}
