#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte a[]={0,0,4,4,27,4,4,0};
byte b[]={0,0,17,10,0,10,17,0};
byte c[]={0,0,0,0,0,0,0,0};
int deger=8;
int okunan=0;
int pot = 100000;
int islem=0;


#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5


void setup() {
  lcd.begin(16,2);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
   do
   {
    deger=tus_oku();
    pot=analogRead(A1);
    pot = map(pot,0,1023,0,255);
    Serial.println(pot);
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
      lcd.print(" ");
    }
    
  }while(deger!=secim);
  deger=9;

  
  if(pot==125)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ISLEM BASARILI");
    delay(1000);
    lcd.clear();
    do
    {
    deger=tus_oku();
    lcd.setCursor(0,0);
    if(islem==0){lcd.print("DOSYA SISTEMI");}
    if(islem==1){lcd.clear();lcd.print("ARSIV");}
    
    if(deger==ust && islem<=2){islem++;}
    if(deger==alt && islem>=1){islem--;}
    if(deger==sag){lcd.setCursor(0,0);lcd.print("CIKIS YAPILDI");delay(1000);break;}
    
  }while(deger!=secim);
  deger=9;
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("HATALI SIFRE");
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
