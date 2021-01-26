#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

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

int sifreSinir=4,i=0;
String durum;
char sifre[4],girilenSifre[4];
int derece;
void setup() {
  lcd.begin(16,2);
  
  lcd.setCursor(0,0);
  lcd.print("YENI SIFRE<A>");
  
  lcd.setCursor(0,1);
  lcd.print("DEVAM<B>");
}

void loop() {
   char key = keypad.getKey();

   if(key){
    if(key=='A'){
      lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("YENI SIFRE:");
     durum="sifre"; 
    }

    while(durum=="sifre"){
      char key = keypad.getKey();
      if(key){
        if(key!= 'A' && key!='B' &&  key!='C' &&  key!='D' && key!='S' && key!='#')
        {
          if(i<sifreSinir){
          lcd.setCursor(i,1);
          
          sifre[i]=key;
          lcd.print("*");
          i++;

          if(i==4){
            delay(500);
            lcd.clear();
            lcd.print("KAYDEDILDI");
            durum="devam";
            for(int i=0;i<4;i++){
              EEPROM.write(i,sifre[i]);
            }
          }
         }
       }
      }
      
    }

    if(key=='B'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SIFRE:");
      durum="devam";
      i=0;
      for(int y=0;y<4;y++){
        sifre[y]==EEPROM.read(y);
      }
    }

    while(durum=="devam"){
      char key = keypad.getKey();
      if(key){
     if(key!= 'A' && key!='B' &&  key!='C' &&  key!='D' && key!='S' && key!='#')
      {
        if(i<sifreSinir){
          lcd.setCursor(i,1);
          lcd.print("*");
          girilenSifre[i]=key;
          i++;
          if(i==4)
          {
            delay(500);
            lcd.clear();
            if(girilenSifre[0] == sifre[0] && girilenSifre[1] == sifre[1] &&
            girilenSifre[2] == sifre[2] &&
            girilenSifre[3] == sifre[3]){
            lcd.setCursor(0,0);
            lcd.print("BILGILER DORGI");
            durum="cikis";
            }    
          }
        }
      }
    }
  }
 }
}
