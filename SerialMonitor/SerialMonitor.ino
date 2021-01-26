///Seri monitörde merhaba dünya yazımı. İşlem arduino ile gerçekleşip windows formunda görüntülenecek.
int a;
void setup()
{
  Serial.begin(9600);//Bitrate oranını verir. gidecek veri yani
  pinMode(13,OUTPUT);
}
void loop()
{
  /*a++;
  Serial.println(a);*/
  digitalWrite(13,HIGH);
  Serial.println("LED Yandi");
  delay(1000);
  digitalWrite(13,LOW);
  Serial.println("LED Sondu");
  delay(1000);
}
