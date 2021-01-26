#include <Servo.h>

Servo motor;
long num;


void setup() {
  motor.attach(5);
  Serial.begin(9600);
  Serial.println("Pozisyon Gir:");
}

void loop() {
  while(Serial.available()>0)
  {
    num = Serial.parseInt();
    Serial.print(num);
    Serial.println(" derece");
    Serial.print("Pozisyon Girin:");
  }
  motor.write(num);
  delay(15);

}
