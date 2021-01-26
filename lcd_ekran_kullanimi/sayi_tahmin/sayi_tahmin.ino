#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
int tut=0;
int deger=9;
int okunan=0;
int sayi = random(0,10);

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SAYI TAHMIN");
  
  delay(1000);
}

void loop() {
  
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("SAYI TUTUN:");
    if(deger==ust){tut=tut+1;}
    else if(deger==alt && deger>=0){tut=tut-1;}
    if(tut<10)
    {
      lcd.setCursor(12,0);
      lcd.print(" ");
    }
    lcd.setCursor(11,0);
    lcd.print(tut);
    delay(160);
  }while(deger!=secim);
deger=6;

if(tut==sayi)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bildin!");
  sayi=random(0,10);
  delay(1000);
  lcd.clear();
}
else if(tut<sayi)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DAHA BUYUK");
  delay(1000);
}
else if(tut>sayi)
 {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DAHA KUCUK");
  delay(1000);
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
