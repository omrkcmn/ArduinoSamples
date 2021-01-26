int sinir;
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
void loop() {
  int isik = analogRead(A1);
  Serial.println(isik);
  if(Serial.available()>0)
  {
    sinir=Serial.parseInt();
  }
  if(isik<sinir)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  delay(150);
}
