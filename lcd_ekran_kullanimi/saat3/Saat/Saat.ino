#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int okunan=0;
int deger=7;

int saat=0;
int dakika=0;
int saniye=0;
int gun=0;
int tarih=2000;

int sure=120;

void setup() {
  lcd.begin(16,2);
  pinMode(A1,INPUT);
  
  lcd.setCursor(0,0);
  lcd.print("TARIH SAAT");
  delay(500);
}

void loop() {
  do
  {
    deger=tus_oku();
    delay(sure);

    lcd.setCursor(0,0);
    lcd.print("SAAT GIRIN:");
    
    if(deger==ust){saat=saat+1;}
    if(deger==alt && deger>0){saat--;}
    lcd.setCursor(11,0);
    lcd.print(saat);
    delay(sure);
    
  }while(deger!=secim);

  deger=7;

  do
  {
     deger=tus_oku();
     delay(sure);

     lcd.setCursor(0,0);
     lcd.print("DAKIKA GIRIN:");
     if(deger==ust){dakika++;}
     if(deger==alt && deger>0){dakika--;}

     lcd.setCursor(13,0);
     lcd.print(dakika);
     delay(sure);
     
  }while(deger!=secim);
  deger=7;

  do
  {
    lcd.clear();
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("GUN GIRIN:");
    if(deger==ust){gun++;}
    if(deger==alt){gun--;}
    lcd.setCursor(10,0);
    lcd.print(gun);
    delay(sure);
    
  }while(deger!=secim);
  deger=7;
  lcd.clear();
  /*do
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TARIH:");
    if(deger==ust){tarih++;}
    if(deger==alt&&deger>1){tarih--;}
    lcd.setCursor(6,0);
    lcd.print(tarih);
    delay(sure);

  }while(deger!=secim);*/

  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print(gun);
  lcd.setCursor(6,1);
  lcd.print("12");
  lcd.setCursor(9,1);
  lcd.print("2017");
  
  for(int i=saat;i<60;i++)
  {
    lcd.setCursor(0,0);
    lcd.print(i);
    lcd.setCursor(2,0);
    lcd.print(":");
    
    for(int j=dakika;j<60;j++)
    {
      lcd.setCursor(3,0);
      lcd.print(j);
      lcd.setCursor(5,0);
      lcd.print(":");
      for(int g=saniye;g<60;g++)
      {
        lcd.setCursor(6,0);
        lcd.print(g);
        delay(1000);
        if(saniye<10)
        {
          lcd.setCursor(7,0);
          lcd.print(" ");
          if(saniye<10)
        {
          lcd.setCursor(7,0);
          lcd.print(" ");
        }
       }
      }
    }
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
