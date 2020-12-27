#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

 char dato="";


void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Iniciando...");
  delay(200);
  lcd.clear();
}

void loop() {
 delay(30);
 
  if (Serial.available()>0)
  {
  dato=Serial.read();
  lcd.print(dato);
  }
  if((digitalRead(A0)==LOW))
  {
    lcd.clear();
  }
}
