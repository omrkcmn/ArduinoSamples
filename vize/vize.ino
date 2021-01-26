  int ledler[]={4,5};
  int led_sayisi=2;
  int buton_deger=0;
  int buton_basma=0;
void setup() 
{
  for(int i = 0; i < led_sayisi; i++)
  {
    pinMode(ledler[i],OUTPUT);
  }
  pinMode(2,INPUT);
  delay(100);
}

void loop()
{
  buton_deger=digitalRead(2);
  if(buton_deger==1)
  {
    for(int i = 0;i<led_sayisi;i++)
    {
      digitalWrite(ledler[i],HIGH);
      delay(50);
    }
  }
    else
  {
    for(int i = 0;i<led_sayisi;i++)
    {
      digitalWrite(ledler[i],LOW);
      delay(50);
    }
  }
}
