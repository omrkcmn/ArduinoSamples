#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int deger=0;
int okunan=0;
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
byte yol[]={0,0,0,0,21,0,0,0};
byte adam[]={0,14,14,4,7,4,10,17};
byte temiz[]={0,0,0,0,0,0,0,0};
int a=0;
int b=0;

void setup() {
  lcd.begin(16,2);
  }

void loop() {
lcd.setCursor(0,1);
lcd.print("27.12.2016 Sali");
for(int saat=0;saat<25;saat++)
{
if(saat==24)
{
  saat=0;
  lcd.setCursor(1,0);
  lcd.print(" ");  
}
lcd.setCursor(0,0);
lcd.print(saat);
lcd.setCursor(2,0);
lcd.print(":");

for(int dakika=0;dakika<61;dakika++)
{
if(dakika == 60)
{
 
  lcd.setCursor(4,0);
  lcd.print(" ");
}

lcd.setCursor(3,0);
lcd.print(dakika);
lcd.setCursor(5,0);delay(5);


lcd.print(":");
for(int saniye=0;saniye<61;saniye++)
{
  if(saniye==60)
  {
    lcd.setCursor(7,0);
    lcd.print(" ");
   
  }
  lcd.setCursor(6,0);
  lcd.print(saniye);
  delay(70);
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
        if(okunan<790)return secim;
        return yok;
      }
