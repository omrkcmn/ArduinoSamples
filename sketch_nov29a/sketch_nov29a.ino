#define buton 2
#define buton2 3
int ledler[]={4,5,13};
int led_sayisi=3;
int buton_deger = 0;
int buton_deger2 = 0;


void setup() 
{
  for(int i = 0;i<led_sayisi;i++)
  {
    pinMode(ledler[i],OUTPUT);
  }
  pinMode(buton,INPUT);
  pinMode(buton2,INPUT);
  delay(100);
}


void loop() 
{
  buton_deger=digitalRead(buton);
  buton_deger2=digitalRead(buton2);
  if(buton_deger==1)
  {
    while(buton_deger==1){}
    //while(digitalRead(buton)==HIGH){}
    for(int i=0;i<=led_sayisi;i++)
    {
      
      digitalWrite(ledler[i],HIGH);
      delay(50);
      }
    }
  
  if(buton_deger2==1)
  {
    
    for(int i = 0;i<=led_sayisi;i++)
    {
     {
      digitalWrite(ledler[i],LOW);
      delay(50);
      }
    }
  }
}    

