      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      
      byte acikAgiz[]={0,0,14,20,24,28,14,0};
      byte kapaliAgiz[]={0,0,14,27,31,31,14,0};
      byte temiz[]={0,0,0,0,0,0,0,0};
      byte o[]={10,0,14,17,17,17,14,0};
      void setup() 
      {
        lcd.begin(16,2);
        lcd.createChar(0,acikAgiz);
        lcd.createChar(1,kapaliAgiz),
        lcd.createChar(2,temiz);
        
      }
      
      void loop() 
      {
      lcd.setCursor(1,0);
      lcd.print("Omer Kocaman");
      
      for(int i=0;i<16;i++)
     
      {
        lcd.setCursor(i,0);
        lcd.write(byte(1));
        delay(100);
      
        lcd.setCursor(i,0);
        lcd.write(byte(2));
        delay(100);
      
        lcd.setCursor(i,0);
        lcd.write(byte(3));
        delay(100);
      }
  }
