#include "Keypad.h"
#include <Wire.h>
#include<EEPROM.h>
#include <LiquidCrystal.h>
#define buzzer 15
int led=13;
int led2=12;
LiquidCrystal lcd(10,11,A2,A3,A4,A5);
char okunan=0;
const byte satir = 4; //4 satir
const byte sutun = 4; //3 sutun
char password[4];
char pass[4],pass1[4];
int i=0;
char rakamlar[satir][sutun] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte satirpin[satir] = {5,4,3,2}; //satır pinleri
byte sutunpin[sutun] = {9,8,7,6}; //sutunpinleri
Keypad butonlar = Keypad(makeKeymap(rakamlar), satirpin, sutunpin,
satir, sutun);
void setup()
{
lcd.begin(16,2);

pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(buzzer, OUTPUT);
lcd.print(" Elektronik ");
lcd.setCursor(0,1);
lcd.print(" Sifreli Kilit ");
delay(2000);
lcd.clear();
lcd.print("Sifreyin: ");
/*
bu kod ilk şifre belirleniken aktif edilecektir.
for(int j=0;j<4;j++)
EEPROM.write(j, j+49);
for(int j=0;j<4;j++)
pass[j]=EEPROM.read(j);
*/
}
void loop()
{
okunan = butonlar.getKey();
if(okunan=='#')
sifredegisim();
if (okunan)
{
password[i++]=okunan;
lcd.print(okunan);

}
if(i==4)
{
delay(200);
for(int j=0;j<4;j++)
pass[j]=EEPROM.read(j);
if(!(strncmp(password, pass,4)))// karsılastırma 2 string ifadeyi
{
digitalWrite(led, HIGH);

lcd.clear();
lcd.print("Sifrelandi!");
delay(2000);
lcd.setCursor(0,1);
lcd.clear();
lcd.print("Sifreyin:");
lcd.setCursor(0,1);
i=0;
digitalWrite(led, LOW);
}
else
{
digitalWrite(buzzer, HIGH);
lcd.clear();
lcd.print("Tekraryin...");
digitalWrite(led2, HIGH);
lcd.setCursor(0,1);
delay(1000);
digitalWrite(led2, LOW);
lcd.clear();
lcd.print("Sifreyin:");
lcd.setCursor(0,1);
i=0;
digitalWrite(buzzer, LOW);
}
}
}
void sifredegisim()
{
int j=0;
lcd.clear();
lcd.print("Gecerlila Girin");
lcd.setCursor(0,1);
while(j<4)
{
char key=butonlar.getKey();
if(key)
{
pass1[j++]=key;
lcd.print(key);

}
key=0;
}
delay(500);
if((strncmp(pass1, pass, 4)))// karşılaştırma
{
lcd.clear();
lcd.print("Hatalila...");
digitalWrite(led2, HIGH);
lcd.setCursor(0,1);
lcd.print("Tekraryin");
delay(1000);
digitalWrite(led2, LOW);
}
else
{
j=0;
lcd.clear();
lcd.print("Yenila Girin:");
lcd.setCursor(0,1);
while(j<4)
{
char key=butonlar.getKey();
if(key)
{
pass[j]=key;
lcd.print(key);
EEPROM.write(j,key);
j++;

}
}
lcd.print(" Basarili......");
delay(1000);
}
lcd.clear();
lcd.print("Sifreyin:");
lcd.setCursor(0,1);
okunan=0;
}

