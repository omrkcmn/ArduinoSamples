#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

#define trigPin 3
#define echoPin 2
void setup ()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}
void loop()
{
  long sure,mesafe;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   sure=pulseIn(echoPin,HIGH);
 mesafe=(sure/2)/29.1;
if(mesafe>230 || mesafe <0)
{
  lcd.setCursor(0,0);
  lcd.print("Menzil Disi!");
}
  lcd.setCursor(0,0);
  lcd.print(mesafe);
  
  if(mesafe<100)
  {
    lcd.setCursor(2,0);
    lcd.print(" ");
  }

   if(mesafe<10)
  {
    lcd.setCursor(1,0);
    lcd.print(" ");
  }
}

