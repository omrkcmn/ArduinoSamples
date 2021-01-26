#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

Servo motor1,motor2;

LiquidCrystal lcd(10,11,A2,A3,A4,A5);


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


int deger,deger2,secim=0,i=0,derece;
void setup() {
    motor1.attach(A1);
    lcd.begin(16,2);
    
}

void loop() {
  
    char key = keypad.getKey();
    lcd.setCursor(0,0);
    lcd.setCursor(0,1);
    
     if(key){
        if(key!='A' && key!='B' && key!='C' && key!='D' && key!='#' && key!='*')
        {
          derece=derece*10+(key-48);
          lcd.setCursor(0,0);
          lcd.print(derece);
        }
        if(key=='D')
        {
          lcd.setCursor(0,1);
          lcd.print("DERECE:");
          lcd.setCursor(7,1);
          lcd.print(derece);
          motor1.write(derece);
          secim=1;
        }
        if(key=='A'){
          derece=0;
          motor1.write(10);
          lcd.clear();
        }
        delay(120);
    }
}

