/*Serial Port'a veri gönderip alma işlemi. Veri tipi dönüşümü
olmadan ascii karşılığını verir.*/

int led = 13;
int sure;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
void loop()
{
  if(Serial.available())
  {
    sure = (int)Serial.read();
    Serial.println(sure);
}
digitalWrite(led,HIGH);
delay(sure);
digitalWrite(led,LOW);
delay(sure);
}
