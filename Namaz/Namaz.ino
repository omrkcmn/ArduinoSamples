#include <LCD5110_Basic.h>

LCD5110 ekran(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t cami[];

void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  ekran.InitLCD();
  ekran.setContrast(70);

  
  ekran.drawBitmap(0,0,cami,84,48);
  delay(1500);
  ekran.clrScr();
  
}

void loop() {
  ekran.setFont(SmallFont);
  //ekran.print("Namaz Vakti",0,0);
  ekran.print("Vakit: OGLE",10,0);
  ekran.print("------------------------",0,15);
  ekran.setFont(BigNumbers);
  ekran.printNumI(13.21,0,25);
}

