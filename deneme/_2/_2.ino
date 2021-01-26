#include <Servo.h>

Servo motor;
long num;
void setup() {
  motor.attach(4);
}

void loop() {
   motor.write(120);
   delay(1500);
   motor.write(100);
   delay(1200);
   motor.write(90);
   delay(1000);
}
