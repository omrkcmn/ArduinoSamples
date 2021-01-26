int a,b,sonuc,asfa;
int derece;

void setup() {
  Serial.begin(9600);
}
void loop() {
  
  if(Serial.available()>0)
  {
    asfa=Serial.parseInt();//Serialden girilen değer tam sayı yapılıyor. 
    //Formüle gerek yok.
    //derece=derece*10+(asfa-48);//Formüllü tamsayı yapmak.
  }
  
  if(asfa>0)
  {
  a=asfa;
  b=asfa;
  sonuc=a+b;
  Serial.print(a);
  Serial.print("+");
  Serial.print(b);
  Serial.print("=");
  Serial.println(sonuc);
  }
  asfa=0;
}
