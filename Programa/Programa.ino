int SUBIR=2;
int BAJAR=3;
int tecla=0;
int CONFIRMAR=4;
bool activarABC=false;
char *tecladoABC[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
char opciones[20][19]= {{"" },{""}};
void setup()
{
    Serial.begin(9600);
    pinMode(SUBIR, INPUT);
    pinMode(BAJAR, INPUT);
    pinMode(CONFIRMAR, INPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}

void loop()
{
//    CargarOpcion();
    
    botonera();  

}

void botonera()
{
   
    if(digitalRead(SUBIR)==HIGH)
    {
        
    
    }
   if(digitalRead(BAJAR)==HIGH)
   {
      
        
   }
   if(digitalRead(CONFIRMAR)==HIGH)
   {
    
    }

}
void subir()
{
tecla++;
        Serial.println(tecladoABC[tecla]);
        
        digitalWrite(5, HIGH);
        delay(200);
        digitalWrite(5,LOW);
}
void bajar()
{
  tecla--;
        Serial.println(tecladoABC[tecla]);
        digitalWrite(6, HIGH);
        delay(200);
        digitalWrite(6,LOW);
  
  
  }
  void confirmar(){
    
    
    }
void abc(){
  for (int i = 0; i < 6; i++) {
    Serial.println(tecladoABC[i]);
    delay(500);
  }
  
  }
