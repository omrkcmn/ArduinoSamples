int deger=0;
float voltaj=0;
void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  deger=analogRead(A0);
  Serial.println(deger);
  if(deger<90)
  {
    renk(255,125,120);
    delay(10);
  }
  if(deger>100)
  {
    renk(0,0,0);
    delay(10);
  }
  
}

void renk(int kirmizi,int yesil,int mavi)
{
  kirmizi = 255-kirmizi;
  yesil = 255-yesil;
  mavi=255-mavi;
  analogWrite(9,kirmizi);
  analogWrite(10,yesil);
  analogWrite(11,mavi);
}

