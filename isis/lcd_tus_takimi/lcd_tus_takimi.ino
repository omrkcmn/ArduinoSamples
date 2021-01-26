#include <LiquidCrystal.h>

#include <Keypad.h>

LiquidCrystal lcd(12,11,5,4,3,2);
const byte ROWS = 4;
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
  };
byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {8, 7, 6};
  
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 13; 

void setup(){
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("MERHABA");
  delay(1000);
  lcd.clear();
}
  
void loop(){
  char key = keypad.getKey();
  if (key) {
    lcd.setCursor(0,0);
    lcd.print("Veri Geliyor");
    lcd.setCursor(0,0);
    lcd.print(key);
    Serial.println(key);
  }
  else if(!key)

  {
     lcd.setCursor(0,0);
    lcd.print("Veri Yok Hocam");
  }
}
