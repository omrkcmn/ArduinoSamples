
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
}

void loop() {
  for(int saat = 0; saat<13;saat++)
  {
    lcd.setCursor(0,0);
    lcd.print(saat);
    lcd.setCursor(2,0);
    lcd.print(":");
    for(int dakika =0;dakika<60;dakika++)
    {
      lcd.setCursor(3,0);
      lcd.print(dakika);
      lcd.setCursor(5,0);
      lcd.print(":");
      for(int saniye=0;saniye<60;saniye++)
      {
        lcd.setCursor(6,0);
        lcd.print(saniye);
        
      }
    }
  }

}
