boolean okunan = 1;

void setup() {
pinMode(4,INPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);


Serial.begin(9600);
}
void loop() 
{
  okunan = digitalRead(2);
  if( okunan == LOW)//Buttona basıldıysa 0 gelir ters mantık.
{
  
   while(okunan==LOW)//Bırakıldımı diye kontrol ediyorz bırakılmışsa döngüden çıkıyor
   {
     okunan = digitalRead(2);//değişken iken döngüsünde kontorl edilmezse sonsuz döngüye girer.  
   }
   delay(50);
   digitalWrite(5,LOW);
   digitalWrite(12,LOW);
 }
 delay(50);
 digitalWrite(5,HIGH);
 digitalWrite(2,HIGH);
}

//ark buton metali ayrılırken arada olan voltaj değerleridir.
