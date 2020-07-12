int SUBIR=2;
int BAJAR=3;
int CONFIRMAR=4;
bool activarABC=false;
char *tecladoABC[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
char opciones[20][19]= {{"dsa" },{"bolas"}};
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
    CargarOpcion();
    
    botonera();  

}

void botonera()
{
    int j=3;
    if(digitalRead(SUBIR)==HIGH)
    {
      
        abc();
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4,LOW);
    
    }
   if(digitalRead(BAJAR)==HIGH)
   {
      
   }

}
void abc(){
  for (int i = 0; i < 6; i++) {
    Serial.println(tecladoABC[i]);
    delay(500);
  }
  
  }
