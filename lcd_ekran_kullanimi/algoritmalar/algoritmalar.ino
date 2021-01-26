      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);
      
      byte acikAgiz[]={0,0,14,20,24,28,14,0};
      byte kapaliAgiz[]={0,0,14,27,31,31,14,0};
      byte temiz[]={0,0,0,0,0,0,0,0};
      byte o[]={10,0,14,17,17,17,14,0};
      byte x[]={0,0,17,10,4,10,17,0};
      byte arti[]={0,4,4,31,4,4,0,0};
      void setup() 
      {
        lcd.createChar(4,x);
        lcd.createChar(5,arti);
        
      }
      
      void loop() 
      {
        for(int i=0;i<16;i++)
        {
        lcd.setCursor(i,0);
        lcd.write(byte(5));
        delay(50);

        lcd.setCursor(i+1,0);
        lcd.write(byte(4));
        delay(50);

        //Temizleyip başa sarıyor
        lcd.setCursor(i,0);
        lcd.write(byte(2));
        delay(50);
        }
      }
