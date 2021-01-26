/*SERİ EKRAN ALIŞVERİŞLİ HESAP MAKİNESİ*/
int sayi1,sayi2;
char islem;
String durum;
int durums=1;
void setup() {
  Serial.begin(9600);//Seri bağlantımı açtım
}

void loop() {

 /*ilk sayı girilme ekranı*/
  
  do{
    if(durums==1){
    durums=2;
    Serial.println("ILK SAYI:");
    
    }
    if(Serial.available()>0){  
        sayi1=Serial.parseInt();
        durum="cik";
        
    }
    if(sayi1>0 && durum!="cik"){
    Serial.println(sayi1);
    }
  }while(durum!="cik");



  do{
    if(durums==2){
    Serial.println("Ikinci Sayi:");
    durums=3;
    }
    if(Serial.available()>0){
      sayi2=Serial.parseInt();
      durum="cik2";
      
    }
    if(sayi2>0 && durum!="cik2")
    {
      Serial.println(sayi2);
    }
  }while(durum!="cik2");
  durum="cik";


  





  
}
