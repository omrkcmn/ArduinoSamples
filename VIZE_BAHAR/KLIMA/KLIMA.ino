#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(10,A1,A2,A3,A4,A5);
float sicaklik;
int derece,derece2;
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

byte derec[]={7,5,7,0,0,0,0,0};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int i=13;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.println("Derece Girin:");
  lcd.createChar(0,derec);
}
void loop() {

  char key = keypad.getKey();
  derece2=analogRead(A0);
  sicaklik=map(derece2,0,1023,0,5000)/10;
  lcd.setCursor(0,1);
  lcd.print(sicaklik);
  lcd.setCursor(5,1);
  lcd.print("C");
  lcd.setCursor(6,1);
  lcd.write(byte(0));
  if(key)
  {
      //lcd.setCursor(i,0);
      //lcd.print(key);
      derece=key*i;
      lcd.setCursor(13,0);
      lcd.print(derece);
      i = i + 10;
    if(key=='D')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DERECE AYARLANDI");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(derece);
    }
  }
}



/*lcd girilen değeri onluk tabana çevirme*/
