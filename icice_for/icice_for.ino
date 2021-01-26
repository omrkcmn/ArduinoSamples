void setup()
{
  Serial.begin(9600);
}

void loop()
{
    for(int bolum = 1; bolum <= 5;bolum++)
    {   
    for( int resim = 1; resim <= 10;resim++)
    {
      Serial.println(bolum );
      Serial.println(" . Bolum ");
      Serial.print(resim );
      Serial.print(" . Resim ");
      delay(500);
    }
    }
}
