#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

byte ses[]={31,31,31,31,31,31,31,31};

void setup() {
  lcd.begin(16,2);
  
  Serial.begin(9600);
}

void loop() {
  int deger=analogRead(1);
  deger=map(deger,0,1023,0,5);
  Serial.println(deger);
  for(int i=0;i<=deger;i++)
  {
    digitalWrite(i+1,HIGH);
    digitalWrite(i+2,LOW);
  }
}
