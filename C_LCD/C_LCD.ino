#include <LCD5110_Basic.h>
LCD5110 ekran(8,9,10,11,12);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t derece[];


void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  ekran.InitLCD();
  ekran.setContrast(70);
  ekran.clrScr();
}

void loop() {
  String yazi;
  yazi = "Merhaba";
  ekran.setFont(SmallFont);
  ekran.print(yazi,0,0);

}
