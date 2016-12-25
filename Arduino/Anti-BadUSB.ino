/*
 * This program is designed to check if the device connected to the 
 * USB port is a Bad USB, the result will be pulled out from the 
 * Serial
 */

#define DATA_P 3
#define DATA_N 4
#define LED 13
#define SEGLEN 5
#define FTNUM 2
boolean bufferP=0;
boolean bufferN=0;
boolean dete=false;
int feature[FTNUM][SEGLEN];
boolean check[FTNUM];
/*
 * The representation of states:
 * 0:P--0;N--0;
 * 1:P--1;N--0;
 * -1:P--0;N--1;
 * 2:P--1;N--1;
 * -2:Undetermined
 */
 
int state;
int Bstate;
int seg[SEGLEN];


void setup(){
  pinMode(DATA_P,INPUT);
  pinMode(DATA_N,INPUT);
  pinMode(LED,OUTPUT);
  segInit();
  digitalWrite(LED,LOW);
  Serial.begin(9600);
}

void loop(){
  bufferP=digitalRead(DATA_P);
  bufferN=digitalRead(DATA_N);
  Bstate=getState(bufferP,bufferN);
  if(state!=Bstate){
    state=Bstate;
    pushState(state);
    showSeg();
    dete=detect1()||detect2();
    if(dete){
      detected();
    }
  }
}
