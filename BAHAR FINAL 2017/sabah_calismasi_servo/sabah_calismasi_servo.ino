#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);/*UNUTMAMAK LAZIM BU(8,9,4,5,6,7) ŞEKLİNDE. */

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
Servo bir,iki;
bool durum;
int derece;
char sifre[4];
int sinir=4;
int eeprom=4;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("SIFRELI KAPI");
  lcd.setCursor(0,0);
  lcd.print("YENI SIFRE<A>");
  bir.attach(A0);
}

void loop() {
  char key = keypad.getKey();

  if(key)
  {
    if(key=='A'){
    durum=0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YENI SIFRE:");
    }  
    while(durum==0){
      char key = keypad.getKey();
      if(key){
      if(key!='A'&&key!='B'&&key!='C'&&key!='D'&&key!='S'&&key!='*'){
        while(sinir<4){
          char key = keypad.getKey();
          if(key){
        sifre[sinir]=key;
        lcd.setCursor(sinir,1);
        lcd.print("*");
        sinir++;
        }
        }
   }
  }
    
  }
  }
}
