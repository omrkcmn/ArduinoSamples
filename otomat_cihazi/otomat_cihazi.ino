/*Otomat
*Otomat Cihazının Simülatörü*/
int sec=0,iptal=0,sayac=0;
int kirmizi,mavi,yesil;
void setup() {
  for(int i=8;i<=10;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  Serial.begin(9600);
  Serial.println("OTOMAT");
  Serial.print("1 tl");
  Serial.println("Secim Yapiniz");
  delay(120);
}

void loop() {
  sec=digitalRead(7);
  iptal=digitalRead(6);
  
    if(sayac==1)
    {
      analogWrite(9,yesil);
      delay(10000);
    }
  if(sec==HIGH)
  {
    Serial.println("Sutlu Kahve");
    kirmizi=0;yesil=255;mavi=0;
    delay(250);
    sayac++; 
  }

  if(iptal==HIGH)
  {
    Serial.println("Islemi Iptal Ettiniz Paraniz Iade Ediliyor");
    delay(250);
  }
}
