#include <EEPROM.h>

int deger,sicaklik,z=0,der[4];
char val;
void setup() {
  Serial.begin(9600);
  Serial.print("Derece Girin:");
  
}

void loop() {
  
  for(int i=0;i<4;i++)
  {
    val = EEPROM.read(i);
    Serial.print(val);
  }
}
