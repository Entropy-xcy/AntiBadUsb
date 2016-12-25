int getState(boolean P,boolean N){
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

