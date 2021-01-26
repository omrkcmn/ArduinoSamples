#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);

Servo motor;
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
int derece,i=0;
void setup() {
  lcd.begin(16,2);
  motor.attach(A1);
}

void loop() {
  char key = keypad.getKey();

  if(key)
  {
    if(key!='A' && key!='B' && key!='C' && key!='D')
    {
      lcd.setCursor(0,0);
      lcd.print(key);
      derece=derece*10+(key-48);
      lcd.setCursor(0,1);
      lcd.print(derece);
      if(derece>170)
      {
        lcd.clear();
        derece=0;
      }
    }
    if(key=='D' && key>=0 && key<=170)
    {
      lcd.clear();
      motor.write(derece);
      delay(15);
      lcd.setCursor(0,1);
      lcd.print(derece);
      derece=0;
    }
  }
  

}
