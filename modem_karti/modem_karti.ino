#include <SoftwareSerial.h>
 SoftwareSerial port(10,11);
void setup() { 
  Serial.begin(9600);
  port.begin(4800);
  port.println("OMRKCMN");

}

void loop() {
  while(port.available()){
    Serial.write(port.read());
    delay(10);
  }
  port.println("kcmn");
  delay(100);
}
