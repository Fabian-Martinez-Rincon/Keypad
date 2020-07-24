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
int contador=0;
char *tecladoABC[27] = {  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'  };
//char *tecladoABC[3][9] ={{"a","b","c","d"},{""}};
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
   if(digitalRead(ConfirmarOpcion)==HIGH)
   {
       for(int i=0;i<contador;i++)
       {
            opciones[i];
      
      Serial.print(opciones[i]);
        }
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
        letra=tecladoABC[tecla];
        Serial.print(letra);
        tecla++;
        
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
void FuncionOpcion(){
  
       Serial.println("Su palabra se cuardo como:");
       for(int i=0;i<4;i++){
          opciones[i];
          Serial.print(opciones[i]);
          
          }
       
  
  
  
  }
