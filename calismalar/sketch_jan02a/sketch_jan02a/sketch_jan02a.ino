#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5
int deger=0;
int okunan=0;

int saat=0;
int dakika=0;
int gun=0;
int ay=0;
int sure=170;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SAAT TARIH ALARM");
  delay(1000);
 lcd.clear();
}

void loop() {
  saat:
  lcd.clear();
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("SAAT:");
    if(deger==ust && saat<23){saat++;}
    if(deger==alt && saat>=1){saat--;}
    if(saat<10)
    {
      lcd.setCursor(6,0);
      lcd.print(" ");
    }
    lcd.setCursor(5,0);
    lcd.print(saat);
    delay(sure);
  }while(deger!=secim);
  deger=6;
  
  dakika:
  lcd.clear();
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("DAKIKA:");
    if(deger==ust && dakika<60){dakika++;}
    if(deger==alt && dakika>=1){dakika--;}
    if(dakika<10);
    {
      lcd.setCursor(8,0);
      lcd.print(" ");
    }
    lcd.setCursor(7,0);
    lcd.print(dakika);
    if(deger==sol){goto saat;}
    delay(sure);
  }while(deger!=secim);
  deger=6;

  gun:
  lcd.clear();
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("GUN GIRIN:");
    if(deger==ust && gun<32){gun++;}
    if(deger==alt && gun>=1){gun--;}
     if(gun<10);
    {
      lcd.setCursor(11,0);
      lcd.print(" ");
    }
    lcd.setCursor(10,0);
    lcd.print(gun);
    if(deger==sol){goto dakika;}
    delay(sure);
  }while(deger!=secim);
  deger=6;
  lcd.clear();
  
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("AY GIRIN:");
    if(deger==ust && ay<=12){ay++;}
    if(deger==alt && ay>=1){ay--;}
     if(ay<10);
    {
      lcd.setCursor(10,0);
      lcd.print(" ");
    }
    lcd.setCursor(9,0);
    lcd.print(ay);
    if(deger==sol){goto gun;}
    delay(sure);
  }while(deger!=secim);
  deger=6;

  lcd.clear();

  lcd.setCursor(0,1);
  lcd.print(gun);
  delay(sure);

 lcd.setCursor(2,1);
 lcd.print(".");
 delay(sure);

 lcd.setCursor(3,1);
 lcd.print(ay);
 delay(sure);

 lcd.setCursor(5,1);
 lcd.print(".");
 delay(sure);

 lcd.setCursor(6,1);
 lcd.print("2017");
 delay(sure);

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
     for(int s=0;s<60;s++)
     {
      lcd.setCursor(6,0);
      lcd.print(s);
      delay(1000);
      if(deger==sol)
      {
        goto saat;
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
