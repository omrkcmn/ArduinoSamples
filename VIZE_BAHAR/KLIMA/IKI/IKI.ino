#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Keypad.h>

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

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int derece,deger,i=0;
float sicaklik;
char val;

void setup() {
  lcd.begin(16,0);
}

void loop() {
  deger=analogRead(A0);
  sicaklik=map(deger,0,1023,0,5000)/10;
  char key = keypad.getKey();

        lcd.setCursor(0,0);
        lcd.print("Oda Sicakligi:");
        lcd.setCursor(14,0);
        lcd.print(sicaklik);
        lcd.setCursor(0,1);
        lcd.print("Anan OC");
}




