#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
byte imza[]={0,0,27,0,0,14,0,0};
byte o[]={10,0,14,17,17,17,14,0};
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,imza);
  lcd.createChar(1,o);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(byte(1));
}
