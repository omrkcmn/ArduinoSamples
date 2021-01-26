/*BASİT BİR KLIMA SICAKLIK AYARLAMA SİSTEMİ.
LM35 SICAKLIK SENSÖRÜ, KEYPAD VE LCD SHIELD 
KULLANNILDI.
ÖMER KOCAMAN*/



#include <EEPROM.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

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

float hamveri,veri,volt,mvolt,sicak;
int sinirDeger,derece,i=0;
String durum;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("KLIMA SISTEMI");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("DEVAM <A>     ");
  lcd.setCursor(0,1);
  lcd.print("DERECE AYARLA<B>");
}

void loop() {
  
  char key = keypad.getKey();
  
  hamveri=analogRead(A0);
  veri=(hamveri/1023);
  volt=veri*5;
  mvolt=volt*1000;
  sicak=mvolt/10;

  if(key){
    if(key=='A'){
      lcd.clear();
      sinirDeger=EEPROM.read(0);
      lcd.setCursor(0,0);
      lcd.print(derece);
    }
    if(key=='B'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YENI DERECE:");
    durum="sifre";
    while(durum=="sifre"){
      char key = keypad.getKey();
      if(key){
        derece=derece*10+(key-48);
        
        lcd.setCursor(12,0);
        lcd.print(derece);
        if(key=='D'){
          EEPROM.write(0,derece);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("DERECE AYARLI");
          delay(700);
          durum="cikis";
        }
      }
    }
   }
  }

if(durum=="cikis"){
  lcd.setCursor(0,0);
  lcd.print("ODA SICAKLIGI:");
  lcd.setCursor(14,0);
  lcd.print(sicak);
  
  if(sicak<sinirDeger || sicak>sinirDeger )
  {
    lcd.setCursor(0,1);
    lcd.print("KLIMA CALISIYOR");
    
  }else if(sicak == sinirDeger){
    
    lcd.setCursor(0,1);
    lcd.print("ISI NORMAL");
  }
 }
}
