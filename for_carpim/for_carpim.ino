int carpim;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  for(int i = 0; i<=10;i++)
  {
    Serial.print("=======");
    Serial.print(i);
    Serial.println("'ler===========");
    for(int j = 0; j<=10; j++)
    {
      carpim = i*j;
      Serial.print(i);
      Serial.print("x");
      Serial.print(j);
      Serial.print("=");
      Serial.println(carpim);
      delay(500);
    }
  }
}
