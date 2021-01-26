#include <math.h>
int sinir;
void setup() {
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
 int deger;
 float sicaklik;
 deger=analogRead(A2);
 sicaklik=termistor(deger);
 Serial.print(sicaklik);
 if(Serial.available()>0)
 {
  if(Serial.read()!=0){
  sinir=Serial.parseInt();}
 }
 Serial.println(sicaklik);
 if(sicaklik>sinir)
 {
  Serial.println("ASFA");
 }
 delay(200);
}

float termistor(int analogOkuma)
{
  float sicaklik;
  sicaklik=log(((10240000/analogOkuma)-10000));
  //sicaklik=1/(0.001129148+(0.000234125+(0.0000000876741*sicaklik*sicaklik))*sicaklik);
  sicaklik=sicaklik-273.15;
  return sicaklik;
  delay(150);
}

