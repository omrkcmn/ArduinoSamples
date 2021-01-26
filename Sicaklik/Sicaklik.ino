#include <math.h>
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);

}

void loop() {
 int deger;
 double sicaklik;
 deger=analogRead(A0);
 sicaklik=termistor(deger);
 Serial.print(sicaklik);
 if(sicaklik>20)
 {
  Serial.println(" Sicaklik Normal Hocam");
 }
 delay(200);
}

double termistor(int analogOkuma)
{
  double sicaklik;
  sicaklik=log(((10240000/analogOkuma)-10000));
  sicaklik=1/(0.001129148+(0.000234125+(0.0000000876741*sicaklik*sicaklik))*sicaklik);
  sicaklik=sicaklik-273.15;
  return sicaklik;
  delay(150);
}

