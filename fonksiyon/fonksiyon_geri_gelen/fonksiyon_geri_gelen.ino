int sonuc;
void setup() {
pinMode(4,INPUT);
Serial.begin(9600);
}

void loop() {
  if(digitalRead(4)==HIGH)
  {
    while(digitalRead(4)==HIGH){}
    int rnd1=random(1,100);
    int rnd2=random(1,100);
    topla(rnd1,rnd2);
    delay(50);
    cikar(rnd1,rnd2);
    delay(50);
    Serial.print(rnd1);
    Serial.print("-");
    Serial.print(rnd2);
    Serial.print("=");
    Serial.println(sonuc);
  }
}
void topla(int s1,int s2)
{
  sonuc = s1+s2;
  Serial.print(s1);
  Serial.print("+");
  Serial.print(s2);
  Serial.print("=");
  Serial.println(sonuc);
}

int cikar(int s1,int s2)
{
  sonuc=s1-s2;
  return sonuc;
}

