///Boolean DEğişkenini tanıma. Az kodla çok iş

boolean yak = false;//Sıfır'da yazılabilir
void setup()
{
  pinMode(13,OUTPUT);
}
void loop()
{
  digitalWrite(13,yak);
  delay(1000);
  yak = !yak;
}
