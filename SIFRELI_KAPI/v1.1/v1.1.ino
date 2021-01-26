#include <EEPROM.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
#include <Keypad.h>
String asama="giris";
byte sinir=6,j=0;
int i=6;

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2};
byte colPins[COLS] = {6,7,8,9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String kisi[5]={"omer"};
int secilenKisi;
int p=0;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("Sifreli");
  lcd.setCursor(0,1);
  lcd.print("**Kapi Sistemi**");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("MENUYE GIRIS<D>");
  lcd.setCursor(0,1);
  lcd.print("MENUDEN CIKIS<C>");
  delay(220);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if(key){
  if(key=='D'){ 
    kAta();
  }
  
 }
}

void kAta()
{
  int durum=0,durum1=0;
  
    
  while(durum1==0){
  char key2=keypad.getKey();
  lcd.print(key2);
  lcd.setCursor(0,0);lcd.print("ATAMA YAPILACAK");
  lcd.setCursor(0,1);lcd.print("KISI SEC(1-5)");
  
  if(key2){
   //if(key2!='A' && key2!='B' &&  key2!='C' &&  key2!='D'){
    if(durum==0)
    {  
      durum=1;
      lcd.clear();
    }
  if(key2=='1'){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(kisi[0]);
    secilenKisi=1;
    p=1;
    }
  if(key2=='2'){secilenKisi=2;p=2;}
  if(key2=='3'){secilenKisi=3;p=3;}
  if(key2=='4'){secilenKisi=4;p=4;}
  if(key2=='5'){secilenKisi=5;p=5;}
   //}
  if(key2=='D'){
    durum1=1;
    lcd.setCursor(0,1);
    lcd.print("KISI SECILDI");
    lcd.print(kisi[p]); 
   }
  }
 }
}

