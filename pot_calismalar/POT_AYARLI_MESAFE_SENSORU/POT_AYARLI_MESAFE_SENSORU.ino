/*POT İLE MESAFE SENSÖRÜ SINIR AYARLAMA
POT İLE MESAFE SENSÖRÜNÜN UZAKLIK SINIRI
BELİRLENİP ONA GÖRE YAKINLAŞTIKÇA RGB LED'İN(HAFİF
UZAKLIK MAVİ ORTA UZAKLIK TURUNCU TEHLİKELİ UZAKLIK
İSE KIRMIZI OLARAK GÖSTERİLECEK) 
UYARI VERMESİNİ SAĞLAYAN UYGULAMA.
OMRKCMN*/
#define trigPin 11
#define echoPin 12

int pot,deger,sinirDeger;
long sure,mesafe;
void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
  /*=============Mesafe Ölçüm====================*/
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure = pulseIn(echoPin,HIGH);
  mesafe = (sure/2)/29.1;
 /*=============Mesafe Ölçüm====================*/
 deger=analogRead(A0);
 pot=map(deger,0,1023,0,400);
 sinirDeger=pot;
 Serial.println(pot);
 if(mesafe>sinirDeger)
 {
  Serial.println("SINIR DEGER ASILDI");
 }
}
