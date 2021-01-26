int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;
int deger;
void setup()
{
  pinMode(kirmiziPin,OUTPUT);
  pinMode(yesilPin,OUTPUT);
  pinMode(maviPin,OUTPUT);
  
 
}
void loop()
{
  deger=analogRead(A0);
  
  if(deger>100)
  {
    renkAyar(0,0,0);
  }
  else if(deger<50)
  {
    renkAyar(0,120,255);
  }
}
void renkAyar(int kirmizi,int yesil,int mavi)
{
  kirmizi=255-kirmizi;
  yesil = 255-yesil;
  mavi = 255-mavi;
  analogWrite(kirmiziPin,kirmizi);
  analogWrite(yesilPin,yesil);
  analogWrite(maviPin,mavi);
}
