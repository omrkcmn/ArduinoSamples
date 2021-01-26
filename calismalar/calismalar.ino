void setup() {
 for(int i=0;i<6;i++)
 {
  pinMode(i,OUTPUT);
 } 
 pinMode(A1,INPUT);
}

void loop() {
  for(int i=0;i<6;i++)
  {
    digitalWrite(i,HIGH);
  }

}
