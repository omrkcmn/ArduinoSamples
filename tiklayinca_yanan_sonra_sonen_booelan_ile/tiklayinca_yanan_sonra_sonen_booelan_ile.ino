boolean okunan = 1;
boolean led_durumu=HIGH;

void setup() 
{
pinMode(2,INPUT);
pinMode(5, OUTPUT);


Serial.begin(9600);
}
void loop() 
{
  okunan = digitalRead(2);
  
  if( okunan == HIGH)//Buttona basıldıysa 0 gelir ters mantık.
   {
  /*butona bastım if e girdi. basılı iken birşey yapılammasını while ile sağladık
  while bırakılınca çıkacak led_durumu değişkeni 1 se yanacak değilse sönecek. */
   while(digitalRead(2)==HIGH){}//Bırakıldımı diye kontrol ediyorz bırakılmışsa döngüden çıkıyor
   
   //değişken iken döngüsünde kontorl edilmezse sonsuz döngüye girer.  
   delay(50);
   led_durumu= !led_durumu;//1 ise 0 olarak çeviriyoruz.
   digitalWrite(5,led_durumu);
   }
}


//ark buton metali ayrılırken arada olan voltaj değerleridir.

 /* buttona basınca yanan bırakınca yanan tekrarlayınca tersi olanın uzun yolu 
 
 if(okunan == 0)
  {
    while(okunan == 0)
    {
       okunan = digitalRead(3);
    }
    delay(50);
    if(sayac % 2 == 0)//
    {
    digitalWrite(5,LOW);
    sayac += 1;
    delay(50);
    }
    
  else
{
  digitalWrite(5,HIGH);
  sayac += 1;
  delay(50);
}*/
