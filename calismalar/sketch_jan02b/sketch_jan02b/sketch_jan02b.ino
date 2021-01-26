#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int sayi=0;
int tahmin =0;
int deger=0;
int okunan=0;
#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5


void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SAYI TAHMIN OYUNU");
  delay(1000);
  lcd.clear();
}

void loop() {
  
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("SAYI GIR:");
    if(deger==ust && sayi<15){sayi++;}
    if(deger==alt && sayi>=1){sayi--;}
    if(sayi<10)
    {
    lcd.setCursor(10,0);
    lcd.print(" ");
    }
    lcd.setCursor(9,0);
    lcd.print(sayi);
    delay(45);
  }while(deger!=secim);
   deger=6;
   lcd.clear();
   if(tahmin==sayi)
   {
    lcd.setCursor(0,0);
    lcd.print("BILDIN!");
    tahmin=random(0,15);
    delay(1000);lcd.clear();
   }
   else if(sayi<tahmin)
   {
    lcd.setCursor(0,0);
    lcd.print("DAHA BUYUK DEGER");
    delay(1000);lcd.clear();
   }
   else if(sayi>tahmin)
   {
    lcd.setCursor(0,0);
    lcd.print("DAHA KUCUK DEGER");delay(1000);lcd.clear();
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
