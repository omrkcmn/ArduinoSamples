#include <LiquidCrystal.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
float hamveri,veri,volt,mvolt,sicak;
int sinir;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  hamveri=analogRead(A0);
  veri=(hamveri/1023);
  volt=veri*5;
  mvolt=volt*1000;
  sicak=mvolt/10;
  lcd.setCursor(0,0);
  lcd.print("SICAKLIK:");
  lcd.setCursor(9,0);
  lcd.print(sicak);
  
  if(Serial.available()>0)
  {
    sinir=Serial.parseInt();
  }
  
  if(sicak>sinir)
  {
    lcd.setCursor(0,1);
    lcd.print("SICLIK SINIR USTU");
  }
  if(sicak<sinir)
  {
    lcd.setCursor(0,1);
    lcd.print("SICLIK NORMAL");
  }
}



