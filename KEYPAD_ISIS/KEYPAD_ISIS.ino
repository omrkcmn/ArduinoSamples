#include <Servo.h>

Servo myservo;  // create servo object to control a servo

  
int valB;
String valA;
void setup() {
  myservo.attach(13);
  Serial.begin(9600);
}

void loop() {
  /*val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); */       
  
    if(Serial.available()>0)
    {
      valA=Serial.parseInt();
      Serial.println(valA);
      delay(3000);

      valB=Serial.read();
      Serial.println("zaaaaa");
      delay(3000);
    }
    
    
}

