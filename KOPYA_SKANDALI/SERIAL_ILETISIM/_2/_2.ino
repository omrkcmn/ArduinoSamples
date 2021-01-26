int sonuc,a,b;
char islem;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  while(a==0){
  Serial.println("ILK SAYI");
  if(Serial.available()>0){
    a=Serial.parseInt();
  }
 }
 while(b==0){
  Serial.println("IKINCI SAYI");
  if(Serial.available()>0){
    b=Serial.parseInt();
  }
 }
 while(islem==' ');{ 
  Serial.println("ISLEM SECIN");
  islem=Serial.read();

  if(islem=='+')
  {
    sonuc=a+b;
    Serial.print(a);
    Serial.print("+");
    Serial.print(b);
    Serial.print("=");
    Serial.println(sonuc);
    delay(1500);
  }
  else if(islem == '-')
  {
    sonuc=a-b;
    Serial.print(a);
    Serial.print("-");
    Serial.print(b);
    Serial.print("=");
    Serial.println(sonuc);
    delay(1500);
  }
 }
}
