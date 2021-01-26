int led[]={4,5,13};
int sayi=3;
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
  }
   for(int i=0;i<sayi;i++)
      {
      while(digitalRead(2)==HIGH)
      {
      digitalWrite(led[i],HIGH); 
      }
   }

   if(digitalRead(3)==HIGH)
  {
    while(digitalRead(3)==HIGH){}
  }
   for(int i=0;i<sayi;i++)
      {
      while(digitalRead(3)==HIGH)
      {
      digitalWrite(led[i],HIGH); 
      }
   }
}
