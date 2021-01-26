 #include <LiquidCrystal.h>
      
      LiquidCrystal lcd(8,9,4,5,6,7);
      
      #define sag 0
      #define ust 1
      #define alt 2
      #define sol 3
      #define secim 4
      #define yok 5
      int okunan =0;
      int deger=6;
      
      int c=0;
      int sure=200;

      float a=0;
      float b=0;
      float toplam=0;
      float fark=0;
      float bol=0;
      float carpim=0;

void setup() {
     lcd.begin(16,2);
     lcd.setCursor(0,0);
     lcd.print("Hesaplamaca");
     delay(1000);
     pinMode(10,OUTPUT);//lcd ışığı için
     digitalWrite(10,HIGH);
     }

void loop() {
  //İlk Sayı Ekranı

  do
  {
    deger=tus_oku();
    delay(sure);
    lcd.setCursor(0,0);
    lcd.print("ILK SAYIYI GIRIN");
    lcd.setCursor(0,1);
    if(a<10)
    {
      lcd.print("A=");
    }
    else{
      lcd.print("A=");
    }

    if(deger==ust){a=a+1;}
    if(deger==alt && deger>=1){a=a-1;}
    lcd.setCursor(3,1);
    lcd.print(a);
  }while(deger!=secim);
  deger=6;

//İkinci Sayıyı Girdiğimiz Ekran
  do{
    deger=tus_oku();
    delay(sure);
    lcd.setCursor(0,0);
    lcd.print("IKINCI SAYIYI GR");
    lcd.setCursor(0,1);
    if(a<10){lcd.print("B=");}
    else{lcd.print("B=");}

    if(deger==ust){b=b+1;}
    if(deger==alt && deger>=1){b=b+1;}
    lcd.setCursor(3,1);
    lcd.print(b);
    
  }while(deger!=secim);
  c=0;//işlem
  deger=6;

  //İşlem Seçimi

  do{
    deger=tus_oku();
    delay(sure);
    lcd.setCursor(0,0);
    lcd.print("ISLEM SECINIZ");
    lcd.setCursor(0,1);

    if(c==0){lcd.print("TOPLAMA");}
    if(c==1){lcd.print("CIKARMA");}
    if(c==2){lcd.print("CARPMA");}
    if(c==3){lcd.print("BOLME");}

    if(deger==ust && c<=2){c=c+1;}
    if(deger==alt && c>=1){c=c-1;}
    
    
  }while(deger!=secim);
  deger=6;


  //ekrana yazdırma

  do
  {
    deger=tus_oku();
    delay(sure);

    if(c==0)
    {
      lcd.setCursor(0,0);
      lcd.print("TOPLAMA SONUCU");
      lcd.setCursor(0,1);
      lcd.print("A+B=");
      toplam=a+b;
      lcd.print(toplam);
      lcd.print("   ");
    }
    if(c==1)
    {
      lcd.setCursor(0,0);
      lcd.print("CIKARMA SONUCU");
      lcd.setCursor(0,1);
      lcd.print("A-B=");
      lcd.setCursor(0,1);
      fark=a-b;
      lcd.print(fark);
      lcd.print("   ");
    }
    if(c==2)
    {
      lcd.setCursor(0,0);
      lcd.print("CARPMA ISLEMININ SONUCU");
      lcd.setCursor(0,1);
      lcd.print("A*B=");
      carpim=a*b;
      lcd.print(carpim);
      lcd.print("   ");
    }
    if(c==3)
    {
      lcd.setCursor(0,0);
      lcd.print("BOLME SONUCU");
      lcd.setCursor(0,1);
      lcd.print("A/B=");
      bol=a/b;
      lcd.print(bol);
      lcd.print("   ");
    }
  }while(deger!=secim);

  deger=6;
  a=0;b=0;c=0;lcd.clear();
  digitalWrite(10,LOW);
  delay(700);
  digitalWrite(10,HIGH);
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

