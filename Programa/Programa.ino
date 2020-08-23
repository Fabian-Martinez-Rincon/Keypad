int SUBIR=2;
int BAJAR=3;
int ConfirmarOpcion=5;
int ConfirmarLetra=4;


int tecla=0;    //Para ver la posicion del arreglo tecladoABC
int confirmar=0;
char letra="";
int contador=0;
int contadorB=0;
char *tecladoABC[27] = 
{  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'  };

String opciones= "";
//__________________________________________________________________________________________________________________________________________________________________________________________
void setup()
{
    Serial.begin(9600);
    pinMode(SUBIR, INPUT);
    pinMode(BAJAR, INPUT);
    pinMode(ConfirmarLetra, INPUT);
    pinMode(ConfirmarOpcion, INPUT);
    pinMode(6, OUTPUT);
    
     
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
    FuncionLetra();
    FuncionOpcion();
    if (tecla==27)    //Cuando letra llega a el numero maximo del abcdario vuelve a empezar
    {
        tecla=0;
    }
    if(tecla<0)
    {
        tecla=26;
    }
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void subir()
{
    if((digitalRead(SUBIR)==HIGH))
    {
        contadorB++;
        if(contadorB==1)
        {
            letra=tecladoABC[tecla];
            Serial.print(letra);
            tecla++;
        }
        if(contadorB==9000)
        {
            contadorB=0;
        }
     }        //Este numero es 4000 ya que el contador al mantenerse apretado por un cierto periodo de tiempo se ejecuta varias veces y la ideas es que solo ejecute una letra a la vez, ya que el numero es mas chico, aparecerian mas de una letra en el display        
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void bajar()
{   
      
        if((digitalRead(BAJAR)==HIGH))
        {
            contadorB++;
            if(contadorB==1)
            {
                letra=tecladoABC[tecla];
                Serial.print(letra);
                tecla--;  
            }
            if(contadorB==9000)
            {
                contadorB=0;
            }
        }
  
  }
//__________________________________________________________________________________________________________________________________________________________________________________________
void FuncionLetra()
{
    if(digitalRead(ConfirmarLetra)==HIGH)
    {
        digitalWrite(7, HIGH);
        //opciones[confirmar++]=letra;
        opciones=opciones+letra;
        Serial.println("");
        Serial.println("Letra confirmada:");
        Serial.println(letra);
        contador++;
        delay(200);
        digitalWrite(7,LOW);
   }
}
//__________________________________________________________________________________________________________________________________________________________________________________________

void FuncionOpcion()
{
    if(digitalRead(ConfirmarOpcion)==HIGH)
    {
        Serial.println("Su palabra es:");
        for(int i=0;i<contador;i++)
        {
           opciones[i];
           Serial.print(opciones[i]);
        }
        Serial.println();
        delay(200);
        digitalWrite(5,LOW);
    }
}
//__________________________________________________________________________________________________________________________________________________________________________________________
