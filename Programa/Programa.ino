
#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 7, 8, 9, 10, 11);
#include <EEPROM.h>
#include "ssd1306.h"
#include <Wire.h>


int SUBIR=2;
int BAJAR=3;
int ConfirmarOpcion=5;
int ConfirmarLetra=4;


int tecla=0;    //Para ver la posicion del arreglo tecladoABC
//int confirmar=0;
char letra="";
int contador=0;// Cada vez que se sume una letra tenemos este contador para recorrer la cadena de texto
String opciones= "";
int contadorB=0;  //El contador que utilizo para medir el tiempo por palabra, en lugar de poner un "delay()"
char *tecladoABC[27] = 
{  '_' ,'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'  };


//__________________________________________________________________________________________________________________________________________________________________________________________
void setup()
{
    Serial.begin(9600);
    pinMode(SUBIR, INPUT_PULLUP);
    pinMode(BAJAR, INPUT_PULLUP);
    pinMode(ConfirmarLetra, INPUT_PULLUP);
    pinMode(ConfirmarOpcion, INPUT_PULLUP);
   lcd.begin(16,2);                           //Initilize LCD display
  lcd.setCursor(0,0);                        //Sets Cursor at first line of Display 
  lcd.print("Circuit Digest");               //Prints CIRCUIT DIGEST in LCD 
  lcd.setCursor(0,1);                        //Sets Cursor at second line of Display
  lcd.print("I2C 2 ARDUINO");                //Prints I2C ARDUINO in LCD
  delay(5000);                               //Delay for 5 seconds
  lcd.clear();                               //Clears LCD display
  Serial.begin(9600);                        //Begins Serial Communication at 9600 baud rate
  Wire.begin();                              //Begins I2C communication at pin (A4,A5)
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void loop()
{
      Wire.requestFrom(8,1);                           // request 1 byte from slave arduino (8)
    byte MasterReceive = Wire.read();                // receive a byte from the slave arduino and store in MasterReceive
    int potvalue = analogRead(A0);                   // Reads analog value from POT (0-5V)
    byte MasterSend = map(potvalue,0,1023,0,127);    //Convert digital value (0 to 1023) to (0 to 127)
     
    Wire.beginTransmission(8);                       // start transmit to slave arduino (8)
    Wire.write(MasterSend);                          // sends one byte converted POT value to slave
    Wire.endTransmission();                          // stop transmitting
    lcd.setCursor(0,0);                              //Sets Currsor at line one of LCD
    lcd.print(">>  Master  <<");                     //Prints >> Master << at LCD
    lcd.setCursor(0,1);                              //Sets Cursor at line two of LCD
    lcd.print("SlaveVal:");                          //Prints SlaveVal: in LCD
    lcd.print(MasterReceive);                        //Prints MasterReceive in LCD received from Slave
    Serial.println("Master Received From Slave");    //Prints in Serial Monitor 
    Serial.println(MasterReceive);
    delay(500);                                     
    lcd.clear();
    botonera();

}
//__________________________________________________________________________________________________________________________________________________________________________________________


void botonera()
{          
    subir();
    bajar();
    FConfirmarLetra();
    FConfirmarOpcion();
    FuncionABC();
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void subir()  //Bajo en el arreglo abc
{
    if((digitalRead(SUBIR)==LOW))
    {
        contadorB++;
        if(contadorB==1)
        {
            letra=tecladoABC[tecla];
            Serial.print(letra);
            tecla++;
        }
        if(contadorB==10000)     //Este numero es 10000 ya que el contador al mantenerse apretado por un cierto periodo de tiempo se ejecuta varias veces y la ideas es que solo ejecute una letra a la vez, ya que el numero es mas chico, aparecerian mas de una letra en el display        
        {
            contadorB=0;
        }
     }       
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void bajar()    //Bajo en el arreglo abc
{   
      
        if((digitalRead(BAJAR)==LOW))
        {
            contadorB++;
            if(contadorB==1)
            {
                letra=tecladoABC[tecla];
                Serial.print(letra);
                tecla--;  
            }
            if(contadorB==10000)
            {
                contadorB=0;
            }
        }
  
  }
//__________________________________________________________________________________________________________________________________________________________________________________________
void FConfirmarLetra() //Cargamos una letra y aumentamos en posicion de la cadena de texto 
{
    if(digitalRead(ConfirmarLetra)==LOW)
    {
        
         contadorB++;
         if(contadorB==1)
         {
            opciones=opciones+letra;
            Serial.println("");
            Serial.println("Letra confirmada:");
            Serial.println(letra);
            contador++;
          }
          if(contadorB==10000)
          {
             contadorB=0;
          }
   }
}
//__________________________________________________________________________________________________________________________________________________________________________________________

void FConfirmarOpcion()  //En cuando el pulsador se apague, se recorre el string opciones, utilizamos una variable contador para no usar el delay y una vez que termina, se reinicia
{
    if(digitalRead(ConfirmarOpcion)==LOW)
    {
        contadorB++;
        if(contadorB==1)
        {
            Serial.println("Su palabra es:");
            for(int i=0;i<contador;i++)
            {
                opciones[i];
                Serial.print(opciones[i]);
            }
            opciones= "";
            Serial.println();
        }
        if(contadorB==10000)
        {
            contadorB=0;
        } 
         
    }
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void FuncionABC()   //Cuando letra llega a el numero maximo del abcdario vuelve a empezar
{
if (tecla==27)   
    {
        tecla=0;
    }
    if(tecla<0)
    {
        tecla=26;
    }  
  
}
//__________________________________________________________________________________________________________________________________________________________________________________________
