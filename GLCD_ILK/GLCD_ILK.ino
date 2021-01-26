 #include <LCD5110_Basic.h> // LCD kütüphanesini taslağımıza dahil ediyoruz.
     
    LCD5110 myGLCD(8,9,10,11,12); //LCD pinlerinin hangi Arduino pinlerine bağlı olduğunu belirtiyoruz.
    extern uint8_t SmallFont[]; // Küçük harflerle yazı yazmamızı sağlayan SmallFont'u tanıtıyoruz.
    extern uint8_t MediumNumbers[]; // Ortanca boy sayıları yazmamızı sağlayan MediumNumbers'ı tanıtıyoruz.
    extern uint8_t BigNumbers[]; // Büyük sayıları yazmamızı sağlayan BigNumbers'ı tanıtıyoruz.
    int isik = 0; //Işık direncinin gönderdiği sayısal değeri saklayacağımız değişkenimiz.
     
    void setup()
    {
    //pinMode(A0, INPUT); //Işık direncinin gönderdiği sinyalleri aldığımız pini giriş olarak ayarlıyoruz.
    pinMode(7, OUTPUT); //LCD ekranın arkaplan aydınlatmasına giden pini çıkış olarak ayarlıyoruz.
    digitalWrite(7,HIGH); //Ekrana ışık veriyoruz.
    myGLCD.InitLCD(); //Ekranı başlatıyoruz.
    myGLCD.setContrast(70); //Kontrast'ı ayarlıyoruz, "60" iyi bir değer.
    }
     
   void loop()
{
  myGLCD.setFont(SmallFont);
  myGLCD.print("Hava Durumu", CENTER, 16);//Konumu
  delay(3000);
  myGLCD.clrScr();
   myGLCD.setFont(SmallFont);
  myGLCD.print("Asfa", CENTER, 16);//Konumu
  delay(5000);
}
