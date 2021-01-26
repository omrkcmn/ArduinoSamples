#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);

#include <Keypad.h>
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

int derece;
int adres;
int i=0;
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  motor.attach(A1);
  Serial.println("Derece Girin:");
}

void loop(){
  char key = keypad.getKey();

  if (key) {
    if(key!='A' && key !='B' && key != 'C' && key!='D')
    {  
    lcd.setCursor(i,0);
    lcd.print(key);
    derece=derece*10+(key-48);
    lcd.setCursor(0,1);
    lcd.print(derece);
    if(derece>=90)
    {
      lcd.clear();
      derece=0;
    }
    }
    
    if(key=='D' && key>=0 && key<=90)
    {
      lcd.clear();
      derece=map(derece,0,1023,0,90);
      delay(15);
      motor.write(derece);
      delay(15);
      lcd.setCursor(0,1);
      lcd.print(derece);
      derece=0;
    }
  }
}

