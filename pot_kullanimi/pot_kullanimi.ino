void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
}
void loop()
{
  int deger = analogRead(A1);
  deger=map(deger,0,1023,0,255);
  Serial.println(deger);
  
  if(deger>50)
  {
    digitalWrite(3,LOW);
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
  }
}

