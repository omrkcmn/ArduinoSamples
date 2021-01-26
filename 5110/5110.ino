#include <LCD5110_Basic.h>

LCD5110 ekran(8,9,10,11,12);

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];
extern uint8_t hava[];

int deger;

void setup()
{
  pinMode(A0,INPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  ekran.InitLCD();
  ekran.setContrast(70);
  
  ekran.setFont(SmallFont);
  ekran.print("HAVA DURUMU",0,0);
  ekran.drawBitmap(0,0,hava,84,48);
  delay(2500);
  ekran.clrScr();
}

void loop()
{
  
  double sicaklik;
  deger = analogRead(A0);
  sicaklik = termistor(deger);
  //ekran.clrScr();
  ekran.setFont(SmallFont);
  ekran.print("SICAKLIK",0,0);

  ekran.setFont(BigNumbers);
  ekran.printNumI(sicaklik,70,20);
  delay(250); 
}

double termistor(int veri){
  double sicaklik;
  sicaklik =log(((10240000 / veri)-1000));
  sicaklik = 1/(0.001129148 + (0.000234125+(0.0000000876741*sicaklik*sicaklik))*sicaklik);
  sicaklik = sicaklik - 273.15;
  return sicaklik; 
}

