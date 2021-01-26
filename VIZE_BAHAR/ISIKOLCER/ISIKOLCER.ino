int derece;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  derece=analogRead(A0);
  Serial.println(derece);
}
