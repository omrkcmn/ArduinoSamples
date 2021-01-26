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
byte rowPins[ROWS] = {5,4,3,2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int sifre[4];
char val;
int i=0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Welcome!");
  delay(1000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("New Pass? <Y><N>");
  char key = keypad.getKey();
  
  if(key)
  {
    /*YENİ ŞİFRE BELİRLEME KISMI*/
    if(key=='A')
    {
    
    lcd.setCursor(0,0);
    lcd.print("Pass:");
    lcd.setCursor(i,1);
    lcd.print(key);
    sifre[i]=key;
    EEPROM.write(i,sifre[i]);
    i++;
  if(key=='D')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Done!");
    delay(600);
    for(int j=0;j<4;j++)
    {
      val=EEPROM.read(j);
      lcd.setCursor(j,1);
      lcd.print(val);
    }
  }
 }

 
 /*YENİ ŞİFRE BELİRLEME KISMI*/

 
  }
}




