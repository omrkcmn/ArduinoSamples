      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);
      
      
      byte temiz[]={0,0,0,0,0,0,0,0};
      void setup() 
      {
        lcd.begin(16,2);
       
      }
      
      void loop() 
      {
        lcd.setCursor(0,0);
        lcd.print(" OMER KOCAMAN");
        lcd.scrollDisplayLeft();
        delay(100);
        /*for(int i=0;i<16;i++)
        {
        
        lcd.setCursor(i,0);
        lcd.print(" OMER KOCAMAN");
        delay(100);
        }*/
      }
