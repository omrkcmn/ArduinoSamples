int led[]={4,5,13};
int sayi=3;
int sayac=0;
void setup() {
  for(int i=0;i<sayi;i++)
  {
    pinMode(led[i],OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop() {
  if(digitalRead(2)==HIGH)
  {
    while(digitalRead(2)==HIGH){}
    delay(250);
    sayac++;
    if(sayac>0 && sayac<9)
    {
      if(sayac<sayi)
      {
    digitalWrite(led[sayac],HIGH);
    }
    }
  }
}
