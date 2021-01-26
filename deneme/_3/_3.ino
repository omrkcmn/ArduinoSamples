int num1,num2,toplam;
void setup() {
  Serial.begin(9600);
  Serial.println("Iki Sayinin Toplami Icin deger Girip Enter'a Basin.");
}
void loop() {
  while(Serial.available()>0)
  {
    num1 = Serial.parseInt();
    num2=Serial.parseInt();
    Serial.print(num1);
    Serial.print(" + ");
    Serial.print(num2);
    Serial.print(" = ");
    toplam=num1+num2;
    Serial.println(toplam);
    delay(120);
  }
}
