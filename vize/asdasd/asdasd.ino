int sayac;
void setup() {
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(digitalRead(2)==HIGH)
  {
    delay(250);
    Serial.println(sayac);
    sayac++;
    if(sayac==1)
    {
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
    }
    else if(sayac==2)
    {
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
    }
  }
}
