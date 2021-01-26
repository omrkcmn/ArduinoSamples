#include <EEPROM.h>
#include <LiquidCrystal.h>
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
char islem1,islem2;

void setup() {
  lcd.begin(16,2);
  lcd.print("HESAP MAKINESI");
  delay(750);
  lcd.clear();

}

void loop() {
  char key = keypad.getKey();

  if(key)
  {
    if(key!='1' || key!='2' || key!='3' || key!='4' || key!='5' || key!='6' || key!='7' || key!='8' || key!='9')
    {
    islem1=key;
    }
    if(key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*')
    {
      derece=derece*10+(key-48);
      lcd.setCursor(0,0);
      lcd.print(derece);
    }
    switch(islem1)
    {
      case 'D'://Toplama İşlemi
      {
        islem2='D';
        a=derece;
        derece=0;
        lcd.clear();
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
      case 'B'://Çarp
      {
        islem2='B';
        a=derece;
        derece=0;
        lcd.clear();
        break;
      }
      case 'C':
      {
        islem2='C';
        a=derece;
        derece=0;
        lcd.clear();
        break;
      }
    
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
        break;
      }
      case 'S':
      {
        lcd.clear();
        derece=0;
        sonuc=0;
        a=0;
        b=0;
        break;
      }
    }
  }
}
