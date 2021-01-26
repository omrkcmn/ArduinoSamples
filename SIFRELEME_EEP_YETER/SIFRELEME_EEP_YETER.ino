#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>
Servo motor;
LiquidCrystal lcd(10,13,A2,A3,A4,A5);


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
char sifre[4],val;
char pass[4],pass1[4];
int i=0,derece;

void setup(){
  lcd.setCursor(0,0);
  lcd.print("KILIT SISTEMI");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  pinMode(13,OUTPUT);
  
  lcd.print("YENI<#>DEGIS<*>");

  
}

void loop(){
  char tus = keypad.getKey();

  if(tus=='A')
  {
    tus=0;
    lcd.clear();
    delay(500);
    lcd.setCursor(0,0);
    lcd.print("Sifre Girin:");
    for(int j=0;j<4;j++)
EEPROM.write(j, j+49);
for(int j=0;j<4;j++)
pass[j]=EEPROM.read(j);
    goto a;
  }
  
  a:
  
  if(tus)
  {
    lcd.setCursor(12,0);
    derece=derece*10+(tus-48);
    sifre[i]=derece;
    lcd.print(derece);
    i++;
    if(tus=='D')
    {
      while(i<4)
      {
        if(tus)
        {
          pass1[i++]=tus;
          lcd.print(tus);
          Serial.print(tus);

          }
          tus=0;
          }
            delay(500);
        }
      }

    
    if(tus=='B')
    {
      for(int h=0;h<4;h++)
      {
       lcd.clear();
       val=EEPROM.read(h);
       lcd.setCursor(h,0);
       lcd.print("asfa");
       lcd.print(val);
       
      }
    }
}
/*while(j<4)
{
char key=butonlar.getKey();
if(key)
{
pass[j]=key;
lcd.print(key);
EEPROM.write(j,key);
j++;

}*/












