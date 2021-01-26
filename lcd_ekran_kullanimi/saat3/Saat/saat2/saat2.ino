#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int deger= 0;
int okunan = 0;
int ay=0;
int saat=0;
int dakika=0;
int gun=0;
int sure=250;

void setup() {
 lcd.begin(16,2);
 lcd.setCursor(2,0);
 lcd.print("Tarih-Saat");
 delay(1500);

}

void loop() {
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("Saat Girin:");
    if(deger==ust){saat++;}
    if(deger==alt){ if(deger>0){saat=saat-1;}}
    
    lcd.setCursor(11,0);
    lcd.print(saat);
    delay(250);
  }while(deger!=secim);
  deger=6;

  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("Dakika Girin:");
    if(deger==ust){dakika++;}
    if(deger==alt && deger>=1){dakika--;}
    lcd.setCursor(13,0);
    lcd.print(dakika);
   delay(250);
  }while(deger!=secim);
  deger=6;
  lcd.clear();
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("Gun Girin:");
    if(deger==ust){gun++;}
    if(deger==alt && deger>=1){gun--;}
    lcd.setCursor(10,0);
    lcd.print(gun);
    delay(250);
    
  }while(deger!=secim);
  deger=8;
  lcd.clear();
  do
  {
    deger=tus_oku();
    lcd.setCursor(0,0);
    lcd.print("Ay Girin:");
    if(deger==ust){ay++;}
    if(deger==alt && deger>=1){ay--;}
    lcd.setCursor(9,0);
    lcd.print(ay);
    delay(250);
  }while(deger!=secim);
deger=6;

lcd.clear();
lcd.setCursor(3,1);
lcd.print(gun);
lcd.setCursor(5,1);
lcd.print(".");
lcd.setCursor(6,1);
lcd.print(ay);
lcd.setCursor(8,1);
lcd.print(".");
lcd.setCursor(9,1);
lcd.print("2016");

for(int i=saat;i<60;i++)
{
  lcd.setCursor(0,0);
  lcd.print(i);
  lcd.setCursor(2,0);
  lcd.print(":");
  for(int dak=dakika;dak<60;dak++)
  {
    lcd.setCursor(3,0);
    lcd.print(dak);
    lcd.setCursor(5,0);
    lcd.print(":");
    for(int j=0;j<60;j++)
    {
      lcd.setCursor(6,0);
      lcd.print(j);
      delay(1000);
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
  if(okunan<790) return secim;
  return yok;
}

