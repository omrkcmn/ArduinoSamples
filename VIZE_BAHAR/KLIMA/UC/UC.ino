/*SICAKLIK AYARLI SANAL KLIMA
*KLIMA DERECE BİLGİSİ GİRİLİR
*ODA SICAKLIĞI LM35 İLE ÖLÇÜLÜR
*BİLGİLER EEPROM'A YAZILIR Kİ VERİ KAYBI YAŞANMASIN
*UYGULAMADA EEPROM MANTIĞININ KAVRANMASI AMAÇ EDİNİLDİ.
*ÖMER KOCAMAN(OMRKCMN)
*/

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
int sicaklik;
int derece,derece2;
int val;
void setup() {
  lcd.begin(16,2);
  pinMode(12,OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("SICAKLIK");
  lcd.setCursor(0,1);
  lcd.print("AYARLA <A><B>");
  
}

void loop() {
  char key = keypad.getKey();
  
  derece=analogRead(A0);
  sicaklik=map(derece,0,1023,0,5000)/10;
  
  if(key)
  {
    if(key=='A')
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DERECE GIRIN:");
      if(key!='A' && key!='B' && key!='C' && key!='D')
      {
      derece2=derece2*10+(key-48);
      lcd.setCursor(13,0);
      lcd.print(derece2);
      }
      if(key=='D')
      {
        lcd.clear();
        EEPROM.write(0,derece2);
        lcd.setCursor(0,0);
        lcd.print("AYARLANDI");
        delay(1000);
        lcd.clear();
     }
     if(key=='B')
     {
      val=EEPROM.read(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("KLIMADERECESI:");
      lcd.setCursor(14,0);
      lcd.print(val);
      lcd.setCursor(0,1);
      lcd.print("ODA SICAKLIGI:");
      lcd.setCursor(14,1);
      lcd.print(sicaklik);
     }
    }
  }

