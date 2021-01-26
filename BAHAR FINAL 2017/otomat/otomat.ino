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


Servo motor;

float hamveri,veri,volt,mvolt,sicak;
int sinir;
String durum;
void setup() {
  lcd.begin(16,2);
  motor.attach(A1);
  lcd.setCursor(0,0);
  lcd.print("KCMN OTOMAT");
  
  delay(700);
  lcd.clear();
  
}

void loop() {
  
  
    hamveri=analogRead(A0);
    veri=(hamveri/1023);
    volt=veri*5;
    mvolt=volt*1000;
    sicak=mvolt/10;

    if(sicak>10){
      lcd.setCursor(0,0);
      lcd.print("50 krs");
      durum="secim";
      while(durum=="secim"){
        char key = keypad.getKey();

         if(key){
          if(key=='1'){
              lcd.setCursor(0,0);
              lcd.print("SU (50 KRS)");
              motor.write(180);
          }
        }
      } 
    }
}
