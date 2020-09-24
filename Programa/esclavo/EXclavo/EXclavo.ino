#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);
int data3=11;
int data1=12;
int data2=13;

void setup() {
  pinMode(data1,INPUT);
  pinMode(data2,INPUT);
  pinMode(data3,INPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("Algo");
  lcd.setCursor(1,0);
  lcd.print("Algo");
  delay(500);
  
}

void loop() {
  int val1=digitalRead(data1);
  if(val1==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Boton1");
    lcd.setCursor(0,1);
    lcd.print("Rotar");
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    } 

  int val2=digitalRead(data2);
  if(val2==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Boton2");
    lcd.setCursor(0,1);
    lcd.print("Rotar");
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    } 
  int val3=digitalRead(data3);
  if(val3==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Boton3");
    lcd.setCursor(0,1);
    lcd.print("Rotar");
    digitalWrite(A4,HIGH);
    digitalWrite(A5,HIGH);
    delay(100);
    } 
}
