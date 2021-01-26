int buzzer = 4;
int counttone = 9;
int tones[]={100,150,200,250,300,350,400,450,500};
void setup() {
  pinMode(buzzer,OUTPUT);

}

void loop() {
  
    tone(buzzer,0.1);
    delay(1000);
    noTone(buzzer);

}
