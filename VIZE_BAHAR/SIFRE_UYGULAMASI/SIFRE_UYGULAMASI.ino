/*ŞİFRELİ KAPI KİLİT UYGULAMASI
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

byte yildiz[]={0,0,10,4,14,4,10,0};
char val;//Şifreyi Görebilmek için yazdım
char val2;//Aynı şekilde
int sifre[4];//Şifre uzunluğu
int i=11,j=0,l=11,derece;//satır,şifre konumu değişkenleri
void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,yildiz);
  lcd.setCursor(0,0);
  lcd.print("Yeni Sifre<A><B>");
}

void loop() {
  char key = keypad.getKey();
  if(key)
  {
    if(key=='A');
    {
      if(l==11)
      {
        lcd.clear();
        lcd.print("YENI SIFRE:");
      }
      
    if(key!='A' && key!= 'B' && key!='C' && key!='D')
    {
    
    
    lcd.setCursor(l,0);
    lcd.write(byte(0));
    sifre[j]=key;
    j++;//şifre değeri için kod
    l++;//SSATIR
    if(j==4)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ISLEM TAMAM");
      int z=0;
      for(;z<4;z++)
      {
        EEPROM.write(z,sifre[z]);
      }
    }
   }
  }//A'YA BASILINCA OLACAKLAR
  
   if(key=='B')
   {
    
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SIFRENIZ");
      {
        for(int g=0;g<4;g++)
      {
      val2=EEPROM.read(g);
      lcd.setCursor(g,1);
      lcd.print(val2);
      }
    }
   }
  }
 } 
