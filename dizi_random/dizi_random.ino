//Sqitch Case Kullanımı
int sayi2 = 500;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int sayi=random(1,6);
  switch(sayi)
  {
    case 1:
    Serial.print(sayi);
    Serial.println(" Pazartesi");
    delay(sayi2);
    break;
    case 2:
    Serial.print(sayi);
    Serial.println(" Sali");
    delay(sayi2);
    break;
    case 3:
    Serial.print(sayi);
    Serial.println(" Carsamba");
    delay(sayi2);
    break;
    case 4:
    Serial.print(sayi);
    Serial.println(" Persembe");
    delay(sayi2);
    break;
    case 5:
    Serial.print(sayi);
    Serial.println(" Cuma");
    delay(sayi2);
    break;
  }
}
