int ledler[]={4,5,6,13};

int okunan=0;

void setup() {
  pinMode(2,INPUT);
  for(int i=0;i<15;i++)
  {
    pinMode(ledler[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  okunan = digitalRead(2);

  if(okunan==HIGH)
  {
    while(okunan==HIGH){}
    for(int i=0;i<15;i++)
    {
      digitalWrite(ledler[i],HIGH);
    }
  }
}
