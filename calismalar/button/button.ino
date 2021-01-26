int giris;
void setup() {
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(3,LOW);
  
}

void loop() {
  int pot=analogRead(0);
  pot=map(pot,0,1023,0,4);
  for(int i=0;i<pot;i++)
  {
    digitalWrite(i+1,HIGH);
    digitalWrite(i+2,LOW);
  }
}
