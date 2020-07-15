int ConfirmarOpcion=5;
int ConfirmarLetra=4;
int SUBIR=2;
int BAJAR=3;
int tecla=0;
int opcion=2;
int columna=0;
bool activarABC=false;
int confirmar=0;
char letra="";
char *tecladoABC[27] = {  "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"  };
//char *tecladoABC[3][9] ={{"a","b","c","d"},{""}};
char opciones[20][19]= {{"" },{""}};
//__________________________________________________________________________________________________________________________________________________________________________________________
void setup()
{
    Serial.begin(9600);
    pinMode(SUBIR, INPUT);
    pinMode(BAJAR, INPUT);
    pinMode(ConfirmarLetra, INPUT);
    pinMode(ConfirmarOpcion, INPUT);
    pinMode(6, OUTPUT);
     Serial.println("Configuracion del teclado");
     Serial.println(" a  b  c  d  e  f  g  h  i ");
     Serial.println(" j  k  l  m  n  ñ  o  p  q ");
     Serial.println(" r  s  t  u  v  w  x  y  z ");
     
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void loop()
{

    
    botonera();

}
//__________________________________________________________________________________________________________________________________________________________________________________________


void botonera()
{
   
    if((digitalRead(SUBIR)==HIGH))
    {
        subir();
    
    }
   if((digitalRead(BAJAR)==HIGH))
   {
      bajar();
        
   }
   if(digitalRead(ConfirmarLetra)==HIGH)
   {
    FuncionLetra();
    }
  if (tecla==27){
    tecla=0;
    }
  if(tecla<0){
    tecla=26;
    }
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void subir()
{

        digitalWrite(5, HIGH);
        
        Serial.print(tecladoABC[tecla]);
        tecla++;
        letra=tecladoABC[tecla];
        delay(200);
        digitalWrite(5,LOW);
}
//__________________________________________________________________________________________________________________________________________________________________________________________
void bajar()
{
  
        digitalWrite(6, HIGH);
        letra=tecladoABC[tecla];
        Serial.print(letra);
        tecla--;
        
        delay(200);
        digitalWrite(6,LOW);
  
  
  }
//__________________________________________________________________________________________________________________________________________________________________________________________
void FuncionLetra()
{
   opciones[columna][confirmar++]=tecladoABC[tecla];
   
   Serial.print(opciones[columna][confirmar++]);
   
    
}
