void detected(){
  pinMode(DATA_P,OUTPUT);
  pinMode(DATA_N,OUTPUT);
  digitalWrite(DATA_P,LOW);
  digitalWrite(DATA_N,LOW);
  while(1){
    Serial.println("Detected!!");
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100);
  }
}

boolean detect1(){
  for(int i=0;i<SEGLEN;i++){
    if(seg[i]!=feature[0][i]){
      return false;
    }
  }
  return true;
}

boolean detect2(){
  for(int i=0;i<SEGLEN;i++){
    if(seg[i]!=feature[1][i]){
      return false;
    }
  }
  return true;
}
