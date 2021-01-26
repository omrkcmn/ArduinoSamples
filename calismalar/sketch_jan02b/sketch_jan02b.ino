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
int pot=0;

void setup() {
   lcd.begin(16,2);
  }  
  void loop()
  {
    do
    {
      deger=tus_oku();
      pot=analogRead(1);
      pot=map(pot,0,1023,0,653);
      lcd.setCursor(0,0);
      lcd.print("SIFRE:");
      lcd.setCursor(6,0);
      lcd.print(pot);
      if(pot<100)
      {
        lcd.setCursor(8,0);
        lcd.print(" ");
      }
      if(pot<10)
      {
        lcd.setCursor(7,0);
        lcd.print("  ");
      }
      delay(50);
    }while(deger!=secim);
    deger=6;
    
    if(pot==427)
    {
      lcd.setCursor(0,0);
      lcd.print("ISLEM BASARILI");
      delay(2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print("HATALI SIFRE");
      delay(2000);
      lcd.clear(); 
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
