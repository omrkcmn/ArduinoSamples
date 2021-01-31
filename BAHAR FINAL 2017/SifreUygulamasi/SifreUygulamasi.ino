#include <Keypad.h>

#include <Servo.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);


const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Servo motor;
char girilenSifre[4],sistemSifre[4],sifre=11,i=0,sinir=4,j=0;
String durum;
void setup() {
  motor.attach(A1);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("YENI SIFRE<A>");
  lcd.setCursor(0,1);
  lcd.print("DEVAM<B>");
}

void loop() {
  char key = keypad.getKey();

  if(key)
  {
    if(key=='A')
    {
      durum="sifre";
    }  
  }

  while(durum=="sifre"){
        char key = keypad.getKey();
        if(key){
          if(key!='A'&&key!='B'&&key!='C'&&key!='D'&&key!='S'&& key!='*'){
        if(sinir<4){
        lcd.setCursor(sifre,0);
        lcd.print("*");
        girilenSifre[sinir]=key;
        sinir++;
        sifre++;
        }
      }
        if(key=='D')
        {
          lcd.clear();
          lcd.print("TAMAMLANDI");
          if(j<4)
          {
            EEPROM.write(j,girilenSifre[j]);
            j++;
          }
         }
        }
       }
}

