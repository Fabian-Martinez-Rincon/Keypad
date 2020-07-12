int Boton1=2;
int Boton2=3;
bool activarABC=false;
char *myStrings[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
                    };
char *ABC[27];//={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
void setup()
{
    Serial.begin(9600);
    pinMode(Boton1, INPUT);
    pinMode(Boton2, INPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{

      
    botonera();  

}

void botonera()
{
    int j=3;
    if(digitalRead(Boton1)==HIGH)
    {
      
        abc();
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4,LOW);
    
    }

}
void abc(){
  for (int i = 0; i < 6; i++) {
    Serial.println(myStrings[i]);
    delay(500);
  }
  
  }
