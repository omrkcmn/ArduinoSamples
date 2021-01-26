#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);

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

Servo motor1,motor2;
int derece;
String durum;
void setup() {
  motor1.attach(A0);
  motor2.attach(A1);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("MERHABA");
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("UST SERVO ICIN A");
  lcd.setCursor(0,1);
  lcd.print("ALT SERVO ICIN B");
}

void loop() {
 a:
 char key = keypad.getKey();

  if(key){
    if(key=='A'){
      durum="ust";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DERECE:");
      
      while(durum=="ust"){
        char key = keypad.getKey();
        if(key){
      if(key!='A'&&key!='B'&&key!='C'&&key!='D'&&key!='S'&&key!='*'){
      derece=derece*10+(key-48);
      lcd.setCursor(7,0);
      lcd.print(derece);
      }
      }
      if(key=='D'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("UST AYARLANDI");
        motor1.write(derece);
        derece=0;
        durum="cik";
      }
     }
   }
    if(key=='B'){
      durum="alt";
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("DERECE:");

      while(durum=="alt"){
        char key = keypad.getKey();
        if(key){
      if(key!='A'&&key!='B'&&key!='C'&&key!='D'&&key!='S'&&key!='*'){
      derece=derece*10+(key-48);
      lcd.setCursor(7,0);
      lcd.print(derece);
      }
    
      if(key=='D'){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("ALT AYARLANDI");
        motor2.write(derece);
        derece=0;
        durum="cik";
      }
    }
   }
  }

  if(key=='C'){
    durum="geri";
  }

  while(durum=="geri"){
    char key = keypad.getKey();
    
    lcd.setCursor(0,0);
    lcd.print("UST SERVO ICIN A");
    lcd.setCursor(0,1);
    lcd.print("ALT SERVO ICIN B");

    if(key){
      if(key=='A'){
        goto a;
        durum="cik";
      }
      if(key=='B'){
        goto a;
        durum="cik";
      }
    }
  }
 }
}
