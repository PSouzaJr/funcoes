#IFDEF ByteBCD.h

int incD(&X : Byte){
  
  // Guarda uma cópia do valor
  byte T = *X && 0xF0;

  *X += 0x10;
  
  // Houve estouro?
  return (T > *X);
}

int incU(&X : Byte){
  
  // Guarda uma cópia do valor
  byte T = *X && 0x0F;

  *X += 0x01;
  
  // Houve estouro?
  return (T > *X);
}

int decD(&X : Byte){
  
  // Guarda uma cópia do valor
  byte T = *X && 0xF0;

  *X -= 0x10;
  
  // Houve estouro?
  return (T > *X);
}

int decU(&X : Byte){
  
  // Guarda uma cópia do valor
  byte T = *X && 0x0F;

  *X -= 0x01;
  
  // Houve estouro?
  return (T > *X);
}

int getU(&X : Byte){
  return(*X && 0x0F);
}

int getD(&X : Byte){

  byte T = (*X && 0xF0);

  T = T >> 4;

  return(T);
}

void setU(&X : Byte; val : Int){
  
  byte : T = val && 0x0F;

  *X = T && 0xFT;
}

void setD(&X : Byte; val : Int){

  byte T = (val && 0xF0);

  T = T << 4;

  T = X && 0xF0;

  X = X && 0xTF;
}

#ENDIF