#include <EEPROM.h>

char sifre;
char selection;
char value;
void setup(){
  Serial.begin(9600);
  Serial.println("Welcome!");
  Serial.println("Input new Pass? <y><n>");
}

void loop(){
  selection=Serial.read();
  if(selection=='y')
  {
  Serial.println("Sifre Girin:");
  sifre=Serial.read();//4 uzunluklu sifre değişkeni. 

  for(int i=0;i<4;i++)
  {
    EEPROM.write(i,sifre);
  }
  }
  else if(selection=='n')
  {
    for(int i=0;i<4;i++)
    {
      //Serial.println("N Tusuna Bastin");
      value = EEPROM.read(i);
      Serial.print(value);
    }
  }
  delay(100);
}
