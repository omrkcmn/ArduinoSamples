      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      
      byte silah[]={0,16,24,28,28,24,16,0};
      byte mermi[]={0,0,0,0,21,0,0,0};
      byte temiz[]={0,0,0,0,0,0,0,0};
      void setup() 
      {
        lcd.begin(16,2);
        lcd.createChar(0,silah);
        lcd.createChar(1,mermi);
        lcd.createChar(2,temiz);
      }
      
      void loop() 
      {
      lcd.setCursor(0,0);
      lcd.write(byte(0));
      lcd.setCursor(3,0);
      lcd.print("Omer Kaptan");
      
      for(int i=1;i<16;i++)
      {  
       lcd.setCursor(i,0);
       lcd.write(byte(1));
       delay(50); 

       lcd.setCursor(i,0);
       lcd.write(byte(2));
       delay(50);
      }
      delay(3000);
  }
