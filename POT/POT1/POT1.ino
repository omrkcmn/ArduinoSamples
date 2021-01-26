#include <EEPROM.h>
int btn,deger,sifre,i=0,a=1,durum=0;
void setup() {
  Serial.begin(9600);
  pinMode(4,INPUT);
}
void loop() {
  deger=analogRead(A0);
  deger=map(deger,0,1023,0,9);
  btn=digitalRead(4);
  if(btn==HIGH)
  {
  Serial.print("SIFRENIN ");
  Serial.print(a);
  Serial.print(". HANESINI GIRIN");
  Serial.println(deger);
  if(btn==LOW)
  {
  durum=1;
  }
  if(durum==1)
  {
    sifre=deger;
    EEPROM.write(i,sifre);
    i++;
    a++;
  }
 }
}
