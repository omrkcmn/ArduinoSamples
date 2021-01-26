#include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      byte kalp[]={0,21,21,14,14,21,21,0};
      
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,kalp);
  lcd.setCursor(0,0);
  lcd.print("Ses:");
}

void loop() {
  int deger=analogRead(1);
  deger = map(deger,0,1023,0,16);
  lcd.setCursor(4,0);
  lcd.print(deger);
  for(int i=0;i<deger;i++)
  {
    lcd.setCursor(i,1);
    lcd.write(byte(0));
  }
  if(deger<10)
  {
    lcd.setCursor(5,0);
    lcd.print(" ");
  }
  lcd.setCursor(deger-1,1);
  if(deger>0)
  {
    lcd.write(byte(0));
  }
  lcd.print(" ");
}
