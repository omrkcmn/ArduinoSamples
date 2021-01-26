#define trig 11
#define echo 12
long sure,mesafe,sinirDeger;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  sure=pulseIn(echo,HIGH);
  mesafe=(sure/2)/29.1;
  Serial.println(mesafe);
  delay(50);
  if(Serial.available()>0)
  {
  sinirDeger=analogRead(A0);
  }
  if(mesafe<sinirDeger)
  {
    Serial.println("SINIR DEGERDESIN");
  }
}
