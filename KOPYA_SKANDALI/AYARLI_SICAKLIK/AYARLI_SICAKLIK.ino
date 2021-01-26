#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Keypad.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);

/*=======KEYPAD AYARI=============*/
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
/*=======KEYPAD AYARI=============*/

int sicaklik,deger,s_deger,sinir=0,oku;
void setup() {
  pinMode(A0,INPUT);
  lcd.begin(16,2);
}

void loop() {
  deger=analogRead(A0);
  sicaklik=map(deger,0,1023,0,5000)/10;
  lcd.setCursor(0,0);
  lcd.print("SICAKLIK:");
  
  
  
  char key=keypad.getKey();
 if(key){
  
   if(key=='D')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("AYARLANDI");
      sinir=s_deger;
      EEPROM.write(0,sinir);
      delay(750);
      
    }
    
    if(key!='A'&& key!='B'&&key!='C'&&key!='D'&&key!='#'&& key!='S'){ 
      
    s_deger=s_deger*10+(key-48);
    
    }
     
    lcd.setCursor(0,1);
    lcd.print(s_deger);
 }
 sinir=EEPROM.read(0);
if(sinir>0){
 if(sicaklik>sinir)
 {
  lcd.setCursor(0,1);
  lcd.print("DEGER USTU");
 }
 else{
  lcd.setCursor(0,1);
  lcd.print("          ");
 }
}
 lcd.setCursor(9,0);
 lcd.print(sicaklik);

}


  
