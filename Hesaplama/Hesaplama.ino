int led = 13;
int toplam,cikarma;
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
  carpim = sayi1*sayi2;
  cikarma = sayi1 - sayi2;
  bolum = sayi2/sayi1;
  
  Serial.print("1. Sayi=");
  Serial.print(sayi1);
  Serial.print(" 2. Sayi=");
  Serial.println(sayi2);
  delay(1000);
  Serial.print(sayi1);
  Serial.print("+");
  Serial.print(sayi2);
  Serial.print("=");
  Serial.println(toplam);
  delay(1000);
  Serial.print(sayi1);
  Serial.print("-");
  Serial.print(sayi2);
  Serial.print("=");
  Serial.println(cikarma);
  delay(1000);
  Serial.print(sayi1);
  Serial.print("*");
  Serial.print(sayi2);
  Serial.print("=");
  Serial.println(carpim);
  delay(1000);
  Serial.print(sayi1);
  Serial.print("/");
  Serial.print(sayi2);
  Serial.print("=");
  Serial.println(bolum);
  delay(1000);
  Serial.println("=================");
}
