//define ile leed çıkış adını veririrz define d1 1 d2 2 vs vs
int sure=100;
void setup() {

  pinMode(5  , OUTPUT);
  pinMode(3  , OUTPUT);
  pinMode(2  , OUTPUT);
   pinMode(6  , OUTPUT);
   ////////////NEGATİF MANTIK OLDUĞU İÇİN TÜM PİNLERİ HIGH İLE SÖNDÜRÜYORUM
  digitalWrite(5, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
   digitalWrite(6  , HIGH);
   /////////////
}


void loop() {
  /*digitalWrite(6, HIGH);//Söner 
  delay(sure);  
  digitalWrite(5, HIGH);
  delay(sure);  
  digitalWrite(3, HIGH);
  delay(sure); 
  //digitalWrite(2, HIGH); 
  //delay(sure);*/ 
  digitalWrite(2,LOW);//yanar
  delay(sure); 
 digitalWrite(2,HIGH);
delay(sure); 
  digitalWrite(3,LOW);
  delay(sure);  
  digitalWrite(3,HIGH);
  delay(sure);
  digitalWrite(5,LOW);
  delay(sure); 
  digitalWrite(5,HIGH);
  delay(sure);
  digitalWrite(6, LOW); 
  delay(sure); 
  digitalWrite(6,HIGH);
  delay(sure);  
  

  digitalWrite(5,LOW);
  delay(sure);  
  digitalWrite(5,HIGH);
  delay(sure);
  digitalWrite(3,LOW);
  delay(sure); 
  digitalWrite(3,HIGH);
  delay(sure);
  digitalWrite(2, LOW); 
  delay(sure); 
  digitalWrite(2,HIGH);
  delay(sure);
}
