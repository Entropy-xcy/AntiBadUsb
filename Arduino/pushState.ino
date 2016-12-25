void pushState(int s){
  for(int i=1;i<SEGLEN;i++){
    seg[i-1]=seg[i];
  }
  seg[SEGLEN-1]=s;
}

void segInit(){
  for(int i=0;i<SEGLEN;i++){
    seg[i]=-2;
  }
  FTInit();
}

boolean ifComplete(){
  for(int i=0;i<SEGLEN;i++){
    if(seg[i]==-2){
      return false;
    }
  }
  return true;
}

void showSeg(){
  for(int i=0;i<SEGLEN;i++){
    Serial.print((int)seg[i]);
    Serial.print(" ");
  }
  Serial.println();
}

void FTInit(){
  feature[0][0]=1;feature[0][1]=0;feature[0][2]=1;feature[0][3]=0;feature[0][4]=1;
  feature[1][0]=1;feature[1][1]=0;feature[1][2]=1;feature[1][3]=2;feature[1][4]=1;
}

