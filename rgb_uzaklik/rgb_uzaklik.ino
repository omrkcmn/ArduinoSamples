#define trigPin 7
#define echoPin 6
int red = 8;
int green = 10;
int blue = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop()
{
  long sure,mesafe;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  sure=pulseIn(echoPin,HIGH);
  mesafe = (sure/2)/29.1;
  Serial.print(mesafe);
  Serial.println(" Cm");
  if(mesafe > 230 || mesafe < 0)
  {
    Serial.println("Menzil Disi!");
    renkAyar(0,0,0);
  }
  if(mesafe>=10 && mesafe <=15)
  {
   renkAyar(0,90,155);
  }
}

void renkAyar(int kirmizi,int yesil,int mavi)
{
  kirmizi=255-kirmizi;
  yesil = 255-yesil;
  mavi = 255-mavi;
  analogWrite(red,kirmizi);
  analogWrite(green,yesil);
  analogWrite(blue,mavi);
}
