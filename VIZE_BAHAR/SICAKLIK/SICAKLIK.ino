#include <LiquidCrystal.h>

LiquidCrystal lcd(10,A1,A2,A3,A4,A5);
float sicaklik;
int veri,deger;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  deger=analogRead(A1);
  sicaklik=map(deger,0,1023,0,5000)/10;
  delay(600);
  Serial.println(sicaklik);
  lcd.setCursor(0,0);
  lcd.print(sicaklik);
}

