#include <EEPROM.h>
int syi,eesize=1024;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  for(int i=0;i<eesize;i++)
  {
    syi=random(255);
    EEPROM.write(i,syi);
  }

  for(int i=0;i<eesize;i++)
  {
    syi=EEPROM.read(i);
    Serial.println(syi);
  }

}
