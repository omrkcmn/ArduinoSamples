#include <Servo.h>
/*Sınavda sorulabilecek Servo Motor 
uygulamaları.*/
Servo bir,iki;
int derece1,derece2;
void setup() {
  bir.attach(A0);
  iki.attach(A2);
}

void loop() {
  derece1=analogRead(A1);
  derece1=map(derece1,0,1023,10,170);
  bir.write(derece1);
  derece2=analogRead(A3);
  derece2=map(derece2,0,1023,10,170);
  iki.write(derece2);
}
