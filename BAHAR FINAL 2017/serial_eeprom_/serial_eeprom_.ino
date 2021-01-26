#include <EEPROM.h>

/*BİR BAŞKA SORULABİLECEK SORU SENARYOSU. SERİ MONİTÖRDEN GİRİLEN DEĞERİ
*SINIR UZAKLIK OLARAK BELİRLEYİP
*ONA GÖRE İŞLEMLER YAPAN PROGRAM.ultrasonik sensör ile...
*/
#define echoPin 6
#define trigPin 7
int ledler[]={2,3,4,5};
long sure,mesafe;
int sinirDeger;

void setup() {
  for(int i=2;i<4;i++){/*for döngüsü içinde ledleri tanımladım kolaylık
    *olsun diye. 0,1,2,3 yani 2. 3. 4. ... ledler çıkış olarak ayarlandı.
    */
    pinMode(ledler[i],OUTPUT);
  }
  pinMode(trigPin,OUTPUT);//Bu pinler önemli
  pinMode(echoPin,INPUT);//sensör üstünde yazıyor pin isimleri
  Serial.begin(9600);

  sinirDeger=EEPROM.read(0);//EEPROM okuyorum. 0. konumda hangi değer varsa o 
  //sinirDeger e atanıyor. Yoksa girmek lazım.
}

void loop() {
  /*BUNLAR EZBERLENMELİ GİBİ BİRŞEY....*/
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
   sure=pulseIn(echoPin,HIGH);
   mesafe=(sure/2)/29.1;//BU FORMÜLÜ HOCA VERİR.
   Serial.println(mesafe);
   delay(120);

   if(Serial.available()>0){//Eğer serialden veri girildiyse...
    sinirDeger=Serial.parseInt();
    EEPROM.write(0,sinirDeger);
   }

   if(mesafe>sinirDeger && sinirDeger>0){
    digitalWrite(ledler[3],HIGH);
    
    Serial.println("DEGER USTU");
   }
   else{
    digitalWrite(ledler[3],LOW);
   }
}
