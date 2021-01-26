      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);
      void setup() 
      {
        lcd.begin(16,2);
        pinMode(A0,INPUT);
      }
      
      void loop() 
      {
        for(int i=0;i<13;i++)
        {
          lcd.setCursor(0,0);
          lcd.print(i);
          lcd.setCursor(2,0);
          lcd.print(":");
          for(int dakika=0;dakika<60;dakika++)
          {
          lcd.setCursor(3,0);
          lcd.print(dakika);
          lcd.setCursor(5,0);
          lcd.print(":");
            for(int j=0;j<=60;j++)
          {
            lcd.setCursor(6,0);
            lcd.print(j);
            
          }
          }
          
        }
      }
