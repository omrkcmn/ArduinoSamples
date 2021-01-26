
int buttonState = 0;
void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);

}

void loop() {  
  int oku = Serial.read();   
  buttonState=digitalRead(4);
  if(buttonState==HIGH)
  {
    Serial.println("1");
  }
  delay(120);
}
