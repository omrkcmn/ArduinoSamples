#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
Servo motor;
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 
int derece;
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Lutfen Sifre Girin:");
}

void loop(){
  char key = keypad.getKey();
  derece=Serial.read();
  if (key) {
    lcd.setCursor(0,0);
    lcd.write(key);
    delay(150); 
  }
}
