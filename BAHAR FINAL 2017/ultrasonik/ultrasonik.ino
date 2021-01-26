#define trigPin 7
#define echoPin 6
void setup ()
{
  Serial.begin(9600);
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

    Serial.println(mesafe);
    
if(mesafe>230 || mesafe <0)
{
  Serial.println("uzak");
}
  
  
  if(mesafe<100)
  {
   
  }

   if(mesafe<10)
  {
   
  }
}

