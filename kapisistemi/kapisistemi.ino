#include <EEPROM.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(10,11,A2,A3,A4,A5);//Hacı Bu LCD kodu isi için
#include <Keypad.h>
String asama="giris";
byte sinir=6,j=0;
int i=6;

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
	};
byte rowPins[ROWS] = {5,4,3,2}; //Bunlarda tuşlar işte sadece yaz
byte colPins[COLS] = {6,7,8,9}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("Sifreli");
  lcd.setCursor(0,1);
  lcd.print("**Kapi Sistemi**");
  delay(2000);
  lcd.clear();
  anamenu();
}

void loop()
{
    char key = keypad.getKey();
    if(key=='A')
    {
      fonksA();
    }
    if(key=='B')
    {
      fonksB();
    }
    if(key=='C')
    {
      fonksC();
    }
    if(key=='D')
    {
      fonksD();
    }
}

void giris(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hosgeldiniz");
    lcd.setCursor(0,1);
    lcd.print("Sifre:");
    
    while(asama=="giris")
    {
      char key = keypad.getKey();
      if(key)
      {
        lcd.setCursor(i,1);
        i++;
        lcd.print("*");
        if(i>11)
        {
          delay(500);
          lcd.clear();
          for(j; j<=sinir; j++)
          {
            int fark=sinir-j;
            if(fark==6)
            {
              j+15;
              sinir+21;
            }
            Serial.println(j);
            Serial.println(sinir);
            delay(500);
          }
        }
      }
    }
}

void anamenu(){
    if(asama!="giris")
    {
      asama="anamenu";
    }
    lcd.setCursor(0,0);
    lcd.print("Menuye Giris(D)");
    lcd.setCursor(0,1);
    lcd.print("Menuden Cikis(C)");
    delay(2000);
    giris();
  }

void fonksA(){
    asama="atama";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Atama Yapilacak");
    lcd.setCursor(0,1);
    lcd.print("Kisi Sec (1-5)");
    
}

void fonksB(){
    asama="sifredegis";
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sifre Degisecek");
    lcd.setCursor(0,1);
    lcd.print("Kisi Sec (1-5)");
}

void fonksC(){
  if(asama=="menu")
  {
    lcd.clear();
    anamenu();
  }
  if(asama=="anamenu")
  {
    giris();
  }
  if(asama=="atama")
  {
    fonksD();
  }
  if(asama=="sifredegis")
  {
    fonksD();
  }
}

void fonksD(){
  if(asama!="giris")
  {
    asama="menu";
  }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Kullanici Ata(A)");
    lcd.setCursor(0,1);
    lcd.print("Sifre Degisimi(B)");
}
