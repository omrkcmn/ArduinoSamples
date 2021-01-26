#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

Servo motor;
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2}; 
byte colPins[COLS] = {6, 7, 8, 9};
int derece,derec,i=0,oku;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  motor.attach(A1);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  /*lcd.print("DERECE GIRIN");
  delay(2000);*/
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if(key)
  {
    if(key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*')
    {
    derec=derec*10+(key-48);
    if(derec<175)
    {
    lcd.setCursor(i,0);
    lcd.print(key);
    i++;
    }
    else if(derec>175){}
    }
    if(key=='D')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("AYARLANDI");
      EEPROM.write(0,derec);
      motor.write(derec);
    }
    if(key=='A')
    {
      oku=EEPROM.read(0);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(oku);
    }
  }
}
