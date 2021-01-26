///Tip Dönüşüm Örneği\\\
//Integer üzerine yazıldı hata verir\\\\

int a = 800;
byte b;
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  b = byte(a);
  Serial.println(b);
}
/*Byte sınırı 0'dan 255. 256 taşa taşa 3 defa 
taştıktan sonra 32'de kalıyor. byte 32'yi
okur.*/
