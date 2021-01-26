      #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);

      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5

      int okunan = 0;
      int deger = 0;
      


      void setup() 
      {
        lcd.begin(16,2);
        pinMode(A0,INPUT);
      }
      
      void loop() 
      {
         int  s1,s2,sonuc;
        deger=tus_oku();
        if(deger==0)
        {
          s1=random(1,50);
          lcd.setCursor(0,0);
          lcd.print(s1);
          delay(200);
        }
        else if(deger == 1)
        {
          s2=random(1,50);
          lcd.setCursor(3,0);
          lcd.print(s2);
          delay(200);
        }          
        else if(deger==2)
        {
          sonuc=s1+s2;
          lcd.setCursor(6,0);
          lcd.print(sonuc);
          delay(200);
        }
      }

      int tus_oku()
      {
        okunan = analogRead(0);
        if(okunan>1000) return yok;
        if(okunan<50) return sag;
        if(okunan<195) return ust;
        if(okunan<380)return alt;
        if(okunan<555)return sol;
        if(okunan<790)return secim;
        return yok;
      }

