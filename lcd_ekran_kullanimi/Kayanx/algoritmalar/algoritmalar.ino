      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);
      int sonuc;
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
        int sayi = random(1,50);
        int sayi2=random(1,50);
        int sonuc = sayi+sayi2;
        
        
        delay(500);
        
        lcd.setCursor(0,0);
        lcd.print(sayi);
        
        lcd.setCursor(2,0);
        lcd.print("+");
        delay(100);

        
        lcd.setCursor(4,0);
        lcd.print(sayi2);

        lcd.setCursor(6,0);
        lcd.print("=");
        delay(100);

        
        lcd.setCursor(8,1);
        lcd.print(sonuc);
        delay(4000);
      }
