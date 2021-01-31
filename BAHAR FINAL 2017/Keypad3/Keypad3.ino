
#include <Servo.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Keypad.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);
Servo motor;


/*=======KEYPAD AYARI=============*/
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
/*=======KEYPAD AYARI=============*/
char kaliciSifre[4],girilenSifre[4];
int i=0;
char okunan[4];
bool durum;
void setup() {
  lcd.begin(16,2);
  lcd.print("HOSGELDINIZ");
  delay(150);
  lcd.clear();
  lcd.print("YENI SIFRE<A><B>");

}

void loop() {
  char key = keypad.getKey();
  if(key){
    if(key=='A'){
      durum=0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("YENI SIFRE");
      }
      while(durum==0){
        char key = keypad.getKey();
        if(key){
        if(i<4){
      if(key!='A'&& key!='B'&& key!='C'&& key!='D'){
        kaliciSifre[i]=key;
        lcd.setCursor(i,1);
        lcd.print("*");
        i++;
      }
    }
  }
 }
    
   
    if(key=='D'){
      for(int i=0;i<4;i++){
        EEPROM.write(i,kaliciSifre[i]);
      }
      lcd.clear();
      lcd.print("ok");
    }
  }

}
