      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(10,11,A2,A3,A4,A5);//8,9,4,5,6,7
      
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
      
      int okunan =0;
      int deger=0;
      void setup() 
      {
        lcd.begin(16,2);
        //pinMode(A0,INPUT);
      }
      
      void loop() 
      {
        deger=tus_oku();
        switch (deger)
        {
          case 0:
          lcd.print("sag");
          delay(250);
          lcd.clear();
          break;
           case 1:
          lcd.print("ust");
          delay(250);
          lcd.clear();
          break;
          case 2:
          lcd.print("alt");
          delay(250);
          lcd.clear();
          break;
          case 3:
          lcd.print("sol");
          delay(250);
          lcd.clear();
          break;
          case 4:
          lcd.print("secim");
          delay(250);
          lcd.clear();
          break;
          
          
        }
      }
      int tus_oku()
      {
        okunan=analogRead(0);
        if(okunan>1000)return yok;
        if(okunan<50)return sag;
        if(okunan<195)return ust;
        if(okunan<380)return alt;
        if(okunan<555)return sol;
        if(okunan<790)return secim;
        return yok;
      }

