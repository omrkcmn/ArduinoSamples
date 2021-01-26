 #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
      int okunan =0;
      int deger=0;
      int a=0;
      int b=0;
void setup() {
      lcd.begin(16,2);
      pinMode(A0,INPUT);
      lcd.setCursor(0,0);
      lcd.print("**");
      lcd.setCursor(3,0);
      lcd.print("KCMN BASKET");
      lcd.setCursor(14,0);
      lcd.print("**");
      lcd.setCursor(0,1);
      lcd.print("*");
      lcd.setCursor(3,1);
      lcd.print("Hosgeldiniz");
      lcd.setCursor(15,1);
      lcd.print("**");
      delay(1000);
      lcd.clear();

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("A Takimi:");
  lcd.setCursor(0,1);
  lcd.print("B Takimi:");
  deger=buttonlar();
  if(deger==ust)
  {
    a=a+1;
    lcd.setCursor(9,0);
    lcd.print(a);
    delay(280);
  }
  if(deger==alt && a>=1)
  {
    if(a<10)//10 dan küçükse tek rakam yaz
    {
    a=a-1;
    lcd.setCursor(9,0);
    lcd.print(a);
    delay(250);
    }
    else//değilse sağdaki rakamı sil
    {
    a=a-1;
    lcd.setCursor(9,0);
    lcd.print(a);
    lcd.print(" ");
    delay(250);
    }
  }

  if(deger==sag)
  {
    b=b+1;
    lcd.setCursor(9,1);
    lcd.print(b);
    delay(250);
  }
  if(deger==sol && b>=1)
  {
    if(b<10)
    {
    b=b-1;
    lcd.setCursor(9,1);
    lcd.print(b);
    delay(250);
    }
    else
    {
    b=b-1;
    lcd.setCursor(9,1);
    lcd.print(b);
    lcd.print(" ");
    delay(250);
    }
  }
  if(deger==secim){lcd.clear();}
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

