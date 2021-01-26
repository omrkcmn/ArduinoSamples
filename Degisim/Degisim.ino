float a = 5.5;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
 a = int(a);
 Serial.print(a);
 while(1);
}
