#include <math.h>
#include <LCD5110_Basic.h>

LCD5110 ekran(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t derece[];

void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  ekran.InitLCD();
  ekran.setContrast(70);
  pinMode(A0,INPUT);
  ekran.clrScr();
  ekran.drawBitmap(1,10,derece,84,48);
}

void loop() {
  int deger;
  double sicaklik;
  deger=analogRead(A0);
  sicaklik=termistor(deger);
  ekran.setFont(SmallFont);
  ekran.print("SICAKLIK",0,0);
  ekran.print("--------------",0,15);
  ekran.setFont(BigNumbers);
  ekran.printNumI(sicaklik,0,30);//56 sağa tam oturuyor
  
  
}


double termistor(int analogOkuma)
{
  double sicaklik;
  sicaklik=log(((10240000/analogOkuma)-10000));
  sicaklik=1/(0.001129148+(0.000234125+(0.0000000876741*sicaklik*sicaklik))*sicaklik);
  sicaklik=sicaklik-273.15;
  return sicaklik;
  delay(150);
}
