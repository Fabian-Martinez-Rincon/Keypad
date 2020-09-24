

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

int pin7=7;
int pin8=8;
int pin9=9;
int pin10=10;
//__________________________________________________________________________________________________________________________________________________________________________________________
void setup()
{
    Serial.begin(9600);
    pinMode(SUBIR, INPUT_PULLUP);
    pinMode(BAJAR, INPUT_PULLUP);
    pinMode(ConfirmarLetra, INPUT_PULLUP);
    pinMode(ConfirmarOpcion, INPUT_PULLUP);
    pinMode(pin7, OUTPUT);
    pinMode(pin8, OUTPUT);
    pinMode(pin9, OUTPUT);
    pinMode(pin10, OUTPUT);
   
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void loop()
{
     
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
            if(contadorB==10000)
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
