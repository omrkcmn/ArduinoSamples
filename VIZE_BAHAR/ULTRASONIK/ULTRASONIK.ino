int t=2;
int e=3;
long olcum;
long cm;


void setup()
{
  
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(t,0);
  delayMicroseconds(5);
  digitalWrite(t,1);
  delayMicroseconds(10);
  digitalWrite(t,0);
  olcum=pulseIn(e,1);
  cm=(olcum/2)/29.1;
  Serial.println(cm);
  delay(500);

  if(cm>=0 && cm<=50)
  {
    tone(4,1);
    delay(10);
    noTone(4);
    delay(500);
  }
  else if(cm>=0 && cm<30)
  {
    tone(4,1);
    delay(10);
    noTone(4);
  }
}
int melodi(int dly)
{
  tone(3,440);
  delay(dly);
  noTone(3);
  delay(dly);
}

