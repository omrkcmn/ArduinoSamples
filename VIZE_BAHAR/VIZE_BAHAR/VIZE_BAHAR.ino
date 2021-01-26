

/*EEPROM Kullanımı
bellekteki bilgilerin silinmemesi sağlanır.

/*Kullanıcıdan alınan şifreyi alan program
*/
#include <EEPROM.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
char secim;
char sifre;
int konum=0;
void setup() {
  lcd.begin(16,2);
  /*lcd.setCursor(0,0);
  lcd.print("YENI SIFRE<E><H>");*/
  Serial.begin(9600);
  Serial.println("Yeni Sifre<E><H>");
}

void loop() {
  
  secim=Serial.read();
  if(secim=='e')
  {
    Serial.println("Lutfen Sifre Girin");
    sifre=Serial.read();
    for(int i=0;i<sifre;i++)
    {
      EEPROM.write(i,sifre);
    }   
  }
  else if(secim=='h')
  {
    char value = EEPROM.read(1);
    Serial.println(value);
  }

}
