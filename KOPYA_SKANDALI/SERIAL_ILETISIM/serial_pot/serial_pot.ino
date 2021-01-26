/*POT DEĞERİNİ SERİ EKRANDAN
GİRİP ONA GÖRE POT'UN DEĞER 
GÖSTEREBİLMESİNİ SAĞLAYAN PROGRAM
OMRKCMN*/
int deger,g_deger=1023,olcum;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  deger=analogRead(A0);
  olcum=map(deger,0,1023,0,g_deger);
  if(Serial.available()>0){
    if(Serial.available()!=0)
  g_deger=Serial.parseInt();
  }
  Serial.println(olcum);
  delay(600);
}
