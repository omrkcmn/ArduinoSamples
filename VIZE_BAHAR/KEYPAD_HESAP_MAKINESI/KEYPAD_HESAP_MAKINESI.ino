/*KEYPAD İLE HESAP MAKİNESİ 
ÇALIŞMASI.
KODLAR KESİNLİKLE KENDİ ÇALIŞMA 
ALANIMA GÖRE YAZILMIŞTIR. ÇALIŞMA
ALANI FARKLILIĞI SEBEBİYLE 
HATALAR ALABİLİR, YAZILIMINIZ 
ÇALIŞMAYABİLİR.
ÖMER KOCAMAN(OMRKCMN)*/


#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'S','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int a,b,sonuc,derece;
char islem,islem2;
void setup() {
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("HESAP MAKINESI");
 delay(1000);
 lcd.clear();
}

void loop() {
  char tus = keypad.getKey();

  if(tus)
  {
    if(tus!='1' || tus!='2' || tus!='3' || tus!='4' || tus!='5' || tus!='6' || tus!='7' || tus!='8' || tus!='9')
    {
    islem=tus;
    }
    
    if(tus!='A' && tus!='B' && tus!='C' && tus!='D' && tus!='#' && tus!='S')
    {
    derece=derece*10+(tus-48);
    lcd.setCursor(0,0);
    lcd.print(derece);
    }

    switch(islem)
    {
      case 'D'://Toplama İşlemi
      {
        islem2='D';
        a=derece;
        derece=0;
        lcd.clear();
        islem=0;
        break;
      }
      
      case 'A'://Bölme
      {
        islem2='A';
        a=derece;
        derece=0;
        lcd.clear();
        break;
      }

      case 'B'://Çarpma
      {
        islem2='B';
        a=derece;
        lcd.clear();
        derece=0;
        break;
      }

      case 'C'://Çıkarma
      {
        islem2='C';
        a=derece;
        lcd.clear();
        derece=0;
        break;
      }

      /*İŞLEM SONUCUNU YAZDIRMA*/
      case '#':
      {
        if(islem2=='D')//Toplama
        {
          b=derece;
          sonuc=a+b;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(sonuc);
        }
        else if(islem2=='A')//Bölme
        {
          b=derece;
          sonuc=a/b;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(sonuc);
        }
        else if(islem2=='B')//Çarpma
        {
          b=derece;
          sonuc=a*b;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(sonuc);//Fonksiyon kullanılabilir....
        }
        
        else if(islem2=='C')//Çıkarma
        {
          b=derece;
          sonuc=a-b;
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print(sonuc);
        }
      }
     /* case 'S':
      {
      lcd.setCursor(0,0);
      lcd.print("asfa");
      }*//*SIFIRLMA İŞLEMİ. (OLMADI NEDENSE)*/
    }
  }
}
