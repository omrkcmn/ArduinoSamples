#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);


byte ses[]={31,31,31,31,31,31,31,31};

void setup() {
   lcd.begin(16,2);
   lcd.createChar(0,ses);
   lcd.setCursor(0,0);
   lcd.print("VOLUME:");
}

void loop() {
   int deger=analogRead(1);
   deger=map(deger,0,1023,0,16);
   lcd.setCursor(7,0);
   lcd.print(deger);
   if(deger<10)
   {
    lcd.setCursor(8,0);
    lcd.print(" ");
   }
   for(int i=0;i<deger;i++)
   {
    lcd.setCursor(i,1);
    lcd.write(byte(0));
   }
   
   lcd.setCursor(deger-1,1);

   if(deger>0)
   {
    lcd.write(byte(0));
   }
   lcd.print(" ");
}
