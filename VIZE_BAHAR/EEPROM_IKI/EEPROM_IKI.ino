#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
int syi;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  randomSeed(analogRead(0));
  lcd.setCursor(0,0);
  
}
void loop() {
  for(int i=0;i<4;i++)
  {
    syi=random(10);
    EEPROM.write(i,syi);
  }
  for(int i=0;i<4;i++)
  {
    syi=EEPROM.read(i);
    lcd.setCursor(i,0);
    lcd.print(syi);
  }
  
}
