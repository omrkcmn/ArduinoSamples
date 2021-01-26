#include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      
void setup() {
  lcd.begin(16,2);
}

void loop() {
  int deger=analogRead(1);
  deger = map(deger,0,1023,0,255);
  lcd.setCursor(0,0);
  lcd.print(deger);

  if(deger<100)
  {
    lcd.setCursor(2,0);
    lcd.print(" ");
  }
  if(deger<10)
  {
    lcd.setCursor(1,0);lcd.print(" ");
    lcd.setCursor(2,0);lcd.print(" ");
  }
}
