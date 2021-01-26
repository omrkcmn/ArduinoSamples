void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);  

}

void loop() {
  
  if(Serial.available())
  {
    char a = Serial.read();
   
    {
      if(a=='1')
      {
        digitalWrite(4,LOW);
        digitalWrite(3,HIGH);
      }
      else if(a==' ' || a=='0'){
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
      }
    }
  }
  
}
