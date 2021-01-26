boolean okunan = 1;
int sure=200;
void setup()
{
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}
void loop()
{
  digitalWrite(3,HIGH);
  delay(sure);
  digitalWrite(4,HIGH);
  delay(sure);
  digitalWrite(5,HIGH);
  delay(sure);
  digitalWrite(6,HIGH);
  delay(sure);
  digitalWrite(7,HIGH);
  delay(sure);
  digitalWrite(8,HIGH);
}
