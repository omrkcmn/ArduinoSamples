#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(10,11,A2,A3,A4,A5);/*UNUTMAMAK LAZIM BU(8,9,4,5,6,7) ŞEKLİNDE. */

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'S','0','#','D'}
  };
byte rowPins[ROWS] = {5,4,3,2}; /*BU SINIFTA 11,12,13,A1 OLACAK. YANİ LCD SHIELD'DA SAĞ ÜST 
*PİNLER 4. PİNDEN İTİBAREN KEYPAD'DE BULUNAN L1,L2,L3,L4 SIRASIYLA BURAYA GÖRE BAĞLANACAK.*/
byte colPins[COLS] = {6, 7, 8, 9}; /*A2,A3,A4,A5 ŞEKLİNDE OLACAK. BEN PROTEUS'A GÖRE YAPTIĞIM
*İÇİN DEĞERLER FARKLI. ODA AYNI ŞEKİLDE R1,R2,R3,R4 OLARAK SIRASIYLA BU PİNLERE GÖRE BAĞLANACAK.*/

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int s1,s2,sonuc,konum=7,derece,durum=0;
float s3,s4,bolmeSonuc;
char islem;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("HESAP MAKINESI");
  delay(700);
  lcd.clear();
}

void loop() {
  
/*İLK SAYI EKRANI - BURADA İLK SAYI GİRİLENE KADAR BEKLİYORUM*/
       do{
        char key = keypad.getKey();
        lcd.setCursor(0,0);
        lcd.print("SAYI 1:");
        if(key){
        if(key!='A' &&  key!='B' &&  key!='C' &&  key!='D' &&  key!='S' &&  key!='#'){
        
  
        derece=derece*10+(key-48);/*BU FORMÜL ÇOK ÖENMLİ
        KEYPADDEN GİRİLEN RAKAMLAR ONDALIKLI SAYIYA ÇEVRİLİR*/
        
        }
       
        lcd.setCursor(konum,0);/*KONUM DEĞİŞKENİM EKRANA SIRAYLA YAZILMASINI
        SAĞLIYOR. BU (0,0) ŞEKLİNDEDE YAZILABİLİRDİ. ÇÜNKÜ
        DERECE VERİM ZATEN BİR 1 İSE 1, 120 İSE 120 OLARAK LCD'YE
        YAZILIYOR.*/
        lcd.print(derece);/*SAYIYI YAZIYORUM*/


         /*TOPLAMA*/
        if(key=='D'){/*İLK SAYIYI GİRİP D TUŞUNA YANİ TOPLAMAYA BASARSAM*/
          islem='+';/*CHAR TİPİ İŞLEM DEĞİŞKENİM TOPLAMA OLUYOR.
          (BKZ. SATIR 113)*/
          s1=derece;/*İLK  SAYIM GİRİLEN DERECE VERİSİ*/
          lcd.clear();
          durum=1;/*DO WHİLE'DAN ÇIKMAK İÇİN DURUM DEĞERİM 1 YAPTIM
          (BKZ. SATIR 98)*/
          konum=7;/*LCD YE GİRİLEN KARAKTERLERİN KONUMU. GEREK YOK*/
          derece=0;/*GİRİLEN DERECE TAMSAYIMI ARTIK SIFIRLIYORUM. VE ÇIKIYORUM*/
        }
        /*ÇARPMA*/
        if(key=='B'){
          islem='*';
          s1=derece;
          lcd.clear();
          durum=1;
          konum=7;
          derece=0;
        }
        /*ÇIKARMA*/
        if(key=='C'){
          islem='-';
          s1=derece;
          lcd.clear();
          durum=1;
          konum=7;
          derece=0;
        }
        
        /*BÖLME*/

        if(key=='A'){
          islem='/';
          s1=derece;
          lcd.clear();
          durum=1;
          konum=7;
          derece=0;
        }
       }
      
     }while(durum!=1);/*DURUM 1'E EŞİT DEĞİLSE. 1 OLDU DÖNGÜDEN ÇIKTIM*/



/*İKİNCİ SAYI EKRANI*/


    do{
      char key = keypad.getKey();
        lcd.setCursor(0,0);
        lcd.print("SAYI 2:");
      if(key){
      if(key!='A' &&  key!='B' &&  key!='C' &&  key!='D' &&  key!='S' &&  key!='#'){
        derece=derece*10+(key-48);//AŞIRI ÖNEMLİ
        lcd.setCursor(konum,0);
        lcd.print(derece);
      }
        if(key=='#'){/*EĞER EŞİTTİRE BASILDIYSA (BURADA #) S2 DERECEYİ ATA
          VE KONTROL ET islem DEĞİŞKENİ HANGİ KARAKTER? + İSE O İŞLEMİ YAP
          - İSE O İŞLEMİ YAP. KOPYALA YAPIŞTIR GERİSİ.*/
          s2=derece;
          if(islem=='+')
          {
            sonuc=s1+s2;//SONUCA İKİ SAYIYI TOPLA YAZ....
            lcd.setCursor(0,1);
            lcd.print(sonuc);
            durum=2;
          }

           if(islem=='-')
          {
            sonuc=s1-s2;
            lcd.setCursor(0,1);
            lcd.print(sonuc);
            durum=2;
          }
          
        }
       
      }
      
    }while(durum!=2);/*AYNI ŞEKİLDE SAYI GİRİLENE VE İŞLEM YAPILANA KADAR BEKLİYORUM.*/
}
