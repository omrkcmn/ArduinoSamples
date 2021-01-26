//for (için) döngüsü for (int x = 0; x<10 (iks küçüktür 10 için) ; x++) {} Şeklinde kullanılır. Çıkrken artma değeri çalışır
//pwm analog çıkış gibi kullanılır.
//analogWrite komutu

void setup()
{
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(4,HIGH);
  pinMode(6,INPUT);
}
void loop()
{
  int x = 1;
  for(int i = 0; i>-1;i=i+x)
  {
    analogWrite(3,i);
    if(i == 255)
    {
    x=-1;
    }
    delay(10);
  }
}

