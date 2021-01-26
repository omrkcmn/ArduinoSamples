//int float değişimi. Float ile int çarğpım sonucu float çıkar.
//
int gelen;
int giden;
int deger;
void setup() 
{
  Serial.begin(9600);
  //randomSeed(analogRead(0));
}
void loop() 
{
 gelen=random(1,100);
 deger = hesap(gelen);
 delay(500);
 Serial.println(gelen);
 Serial.println(deger);
 Serial.println("================");
}

int hesap(int gelen)//Bu fonksiyona gelen versini gönderip hesaba sokarız.
//burada işelm görüp sonu değerini döndürür. Bu fonksiyonla işlem yapılır.
//Static olarak belirlendiği için değer sıfırlanmaz sürekli 
//Aynı hesap devam eder.
{
  static int sonuc;
  sonuc = sonuc + gelen;
  return sonuc;
}
