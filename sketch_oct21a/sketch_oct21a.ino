void setup()
{
  pinMode(12,OUTPUT);
  pinMode(6,OUTPUT);
}
void loop()
{
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
}
