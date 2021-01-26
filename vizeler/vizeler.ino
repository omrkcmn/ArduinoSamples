boolean okunan = 1;
boolean ledDurumu = 1;
void setup() {
  pinMode(2,INPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2)==HIGH)
  {
    while(digitalRead(2)==HIGH)
    {}
    ledDurumu=!ledDurumu;
    digitalWrite(5,ledDurumu);
  }
}
