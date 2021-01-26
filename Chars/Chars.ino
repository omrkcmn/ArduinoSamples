//Sabitler
#define pinoo 13//Hafızada yer tutmaz
//const int sayi = 1;
volatile int state = LOW;//Bununla tanımlanırsa RAM'de yer tutmaz.
void setup()
{
  Serial.begin(9600);
  pinMode(pinoo,OUTPUT);
}
void loop()
{
  digitalWrite(pinoo,state);
  delay(500);
  state = !state;
  Serial.print('O');
  delay(500);
  Serial.print('M');
  delay(500);
  Serial.print('E');
  delay(500);
  Serial.print('R');
  delay(500);
  Serial.println(" KOCAMAN");
  delay(1000);
}
