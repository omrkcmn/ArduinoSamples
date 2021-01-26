void setup() {
for(int i=0;i<4;i++)
{
  pinMode(i,OUTPUT);
}
}

void loop() {
  int deger=analogRead(1);
  deger = map(deger,0,1023,0,3);
  for(int i=0;i<deger;i++)
  {
    digitalWrite(i,HIGH);
    for(int j=0;j<deger;j++)
    {
      digitalWrite(i,LOW);
    }
  }
}
