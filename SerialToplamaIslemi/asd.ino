int led = 13;
int toplam;
int carpim;
float bolum;
int sayi1,sayi2;
void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  randomSeed(analogRead(0));
}
void loop()
{
  sayi1 = random(1,100);
  delay(1000);
  sayi2=random(1,100);
  delay(1000);
  toplam=sayi1+sayi2;
  Serial.println(sayi1,sayi2);
  delay(1000);
  
  
}
