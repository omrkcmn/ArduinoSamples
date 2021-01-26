int a[4][3];
void setup() {
Serial.begin(9600);
}

void loop() {
 for(int i =0;i<3;i++)
 {
  for(int j=0;j<4;j++)
  {
    a[i][j]=random(1,100);
    Serial.print('i');
    Serial.print('=');
    Serial.print(i);
    Serial.print(" j");
    Serial.print("=");
    Serial.print(j);
    Serial.print(" 'inci eleman");
    Serial.print('=');
    Serial.println(a[i][j]);
    delay(500);
  }
 }
}
