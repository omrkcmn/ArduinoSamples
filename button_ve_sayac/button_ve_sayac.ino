int sayac = 0;

void setup() {
  pinMode(6,INPUT); 
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  Serial.begin(9600);
}
void loop ()
{
  digitalRead(6);
  while(digitalRead(6) == LOW)
  {  
   sayac++;
   if(sayac<=10)
   {
     Serial.println(sayac);
     Serial.println("Sayac 10'dan Kucuk");
     delay(200);
   }
   else if (sayac < 20)
   {
     Serial.println(sayac);
     Serial.println("Sayac Orta Degerde");
     delay(200);
   }
   else
   {
     Serial.println(sayac);
     Serial.println("Sayac Degeri Ust Seviyede");
     delay(200);
   }
 }
 
 
   
}
