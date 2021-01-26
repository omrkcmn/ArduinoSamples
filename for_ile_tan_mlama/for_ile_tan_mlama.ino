boolean okunan = 1;
#define button 2

void setup() {
  for(int i = 2; i <=4;i++)
  {
    pinMode(i,OUTPUT);
    pinMode(i+4,INPUT);
  }

 
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);


Serial.begin(9600);
}
void loop() 
{
  
  while(digitalRead(6) == LOW)
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH); 
  }
   digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH); 
   
   
     while(digitalRead(7) == LOW)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH); 
  }
   digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH); 
   
   
     while(digitalRead(8) == LOW)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW); 
  }
   digitalWrite(2,HIGH);
   digitalWrite(3,HIGH);
   digitalWrite(4,HIGH); 
}
