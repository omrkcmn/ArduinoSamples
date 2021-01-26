#define buton 2
#define buton2 3
int ledler[]={3,4,5,6,7,8};
int led_sayisi=6;
int buton_deger = 0;
int buton_deger2 = 0;
int buton_basilma=0;

void setup() 
{
  for(int i = 0;i<led_sayisi;i++)
  {
    pinMode(ledler[i],OUTPUT);
  }
  pinMode(buton,INPUT);
  delay(100);
}


void loop() 
{
  buton_deger=digitalRead(buton);
  if(buton_deger==1)
  {
    while(buton_deger==1){}
    //while(digitalRead(buton)==HIGH){}
    for(int i=0;i<led_sayisi;i++)
    {
      while(buton_deger==1){
      digitalWrite(ledler[i],HIGH);
      delay(50);
      }
    }
  }
  else
  {
    for(int i = 0;i<led_sayisi;i++)
    {
      while(buton_deger2==1){
      digitalWrite(ledler[i],LOW);
      delay(50);
      }
    }
  }  
}    
