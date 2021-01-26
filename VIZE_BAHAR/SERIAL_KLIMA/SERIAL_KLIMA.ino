
char secim;
int derece=0;
void setup() {
  Serial.begin(9600);
  Serial.write("DERECE GIR<D> ANA MENU<A>");
}

void loop() {
  secim=Serial.read();
  if(secim='D')
  {
  Serial.println("DERECE GIRIN:");
  //derece=Serial.read(); 
  Serial.println(derece);
  delay(1000);
  }
}
