int Boton1=2;
int Boton2=3;
char ABC[27];//={"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
void setup()
{
    Serial.begin(9600);
    pinMode(2, INPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    Serial.print("Hola");
    botonera();  

}

void botonera()
{
    if(Boton1==HIGH)
    {
        Serial.print("Hola");
        digitalWrite(4, HIGH);
    
    }


}
