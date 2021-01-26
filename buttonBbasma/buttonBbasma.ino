boolean okunan = 1;

void setup() {
pinMode(3,INPUT);
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);
digitalWrite(5,HIGH);
digitalWrite(2,HIGH);

Serial.begin(9600);
}
void loop() 
{
  okunan = digitalRead(3);
  if( okunan == 1)//Buttona basıldıysa 0 gelir ters mantık.
{
  
   while(okunan==1)//Bırakıldımı diye kontrol ediyorz bırakılmışsa döngüden çıkıyor
   {
     okunan = digitalRead(3);//değişken iken döngüsünde kontorl edilmezse sonsuz döngüye girer.  
   }
   delay(50);
   digitalWrite(5,LOW);
   digitalWrite(2,LOW);
   Serial.println("BUTTONA BASILDI");
 }
 delay(50);
 digitalWrite(5,HIGH);
 digitalWrite(2,HIGH);
}

//ark buton metali ayrılırken arada olan voltaj değerleridir.
