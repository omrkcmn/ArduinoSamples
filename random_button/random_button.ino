  //Switch Case Kullanımı
  int sayi2 = 500;
  void setup()
  {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  }
  void loop()
  {
  if(digitalRead(8)==HIGH){
    while(digitalRead(8)==HIGH){}
    digitalWrite(3,HIGH);
    int sayi=random(1,8);
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
    case 6:
    Serial.print(sayi);
    Serial.println(" Cumartesi");
    delay(sayi2);
    break;
    case 7:
    Serial.print(sayi);
    Serial.println(" Pazar");
    delay(sayi2);
    break;
  }
  
  }
digitalWrite(3,LOW);
  }
