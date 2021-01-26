 #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(12,11,5,4,3,2);
      
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
      int okunan =0;
      int deger=0;
      
      int c=0;
      int sure=110;

      float a=0;
      float b=0;
      float toplam=0;
      float fark=0;
      float bol=0;
      float carpim=0;

void setup() {
      lcd.begin(16,2);
      lcd.setCursor(4,0);
      lcd.print("Hesap Makinesi");
      pinMode(A0,INPUT);
      pinMode(10,OUTPUT);
}

void loop() {
 deger=buttonlar();

 do
 {
  lcd.setCursor(0,0);
  lcd.print("Sayi Giriniz");
 }while(deger!=sag);
deger=6;
 do
 {
  lcd.setCursor(0,0);
  lcd.print("Sayi ");
 }while(deger!=secim);
}

int buttonlar()
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

