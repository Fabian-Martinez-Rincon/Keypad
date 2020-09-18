#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     8 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

int guardar;
int pixel= -10;
int valor;
int boton1;
int boton2;
int boton3;
int contar;
int contadorP=1;
int seleccionar;

int MENU=6;
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
char *tecladoABC[26] = 
{ 'A', 'B', 'C', 'C', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'  };


static const unsigned char PROGMEM logo_bmp[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x06, 0x30, 0x00, 0x00, 0x00, 0x01, 0xFE, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3F, 0x06, 0x20, 0x00, 0x00, 0x00, 0x03, 0xFC, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x76, 0x0C, 0x60, 0x00, 0x00, 0x00, 0x00, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xE6, 0x0C, 0x60, 0x00, 0x00, 0xC0, 0x00, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xCE, 0x0C, 0xC0, 0x01, 0x01, 0x80, 0x00, 0xC1, 0x80, 0x00, 0x00, 0x00, 0x03, 0x00,
0x00, 0x1F, 0xFF, 0x18, 0xF0, 0xE3, 0xF3, 0xC0, 0x1C, 0xC1, 0xF0, 0x70, 0xBB, 0x87, 0x43, 0x00,
0x00, 0xFF, 0xFF, 0x18, 0xF9, 0xF3, 0xF7, 0xC0, 0x7E, 0xC1, 0xF1, 0xF9, 0xFF, 0x8F, 0xC7, 0x00,
0x01, 0xC3, 0x18, 0x31, 0x99, 0xF2, 0xC3, 0x00, 0xF1, 0x83, 0x31, 0x99, 0x99, 0x8C, 0xC7, 0x80,
0x03, 0x87, 0x18, 0x31, 0x9B, 0xF3, 0x83, 0x01, 0xC1, 0x83, 0x33, 0x19, 0x19, 0x98, 0x85, 0x80,
0x07, 0x06, 0x38, 0x23, 0x1B, 0x01, 0x86, 0x01, 0x83, 0x06, 0x23, 0x1B, 0x33, 0x19, 0x81, 0x80,
0x06, 0x0E, 0x3E, 0x7B, 0xF3, 0xF9, 0xF7, 0x83, 0x83, 0x06, 0x7B, 0xF3, 0x33, 0xDF, 0xEF, 0x80,
0x06, 0x0C, 0x1E, 0x7B, 0xE1, 0xF0, 0xF7, 0x83, 0x03, 0x04, 0x79, 0xE2, 0x23, 0xCE, 0xEF, 0x00,
0x06, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  pinMode(SUBIR, INPUT_PULLUP);
  pinMode(BAJAR, INPUT_PULLUP);
  pinMode(ConfirmarLetra, INPUT_PULLUP);
  pinMode(ConfirmarOpcion, INPUT_PULLUP);
  pinMode(MENU, INPUT_PULLUP);
  
  display.clearDisplay();
  display.drawBitmap(0, 0, logo_bmp, 128, 64, WHITE); // Mostramos el logo del Albert Thomas
  display.display();                                  // Mostrar en el Display
  delay(2000);                                        // Dejamos el logo 2000ms
 menu1();                                            // Mostramos el menu inicial
}

void loop() {
   menu(); // Codigo para seleccionar dentro del menu 
}

////////////////////////////////////////////////////////////////////////////////
void menu1() {                                        // Funcion del menu inicial
  if (boton3==0){
  display.clearDisplay();
  display.setTextSize(1);                             // Escala 1:1 texto
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Seteamos el color resaltado 
  display.setCursor(14,9);                            // Seleccionamos la posicion del texto
  display.println("Menu de opciones");

  display.setTextColor(SSD1306_WHITE);                 // Seteamos el color del texto en blanco
  display.setCursor(14,48);
  display.println("*Configuraciones");
  
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,28);
  display.println("*Elegir Opciones");

  display.display();
  }

}

////////////////////////////////////////////////////////////////////////////////
void menu(){                                          // Funcion del menu con el codigo para seleccionar
if (boton3==0)                                        // boton3 es una variable para limitar, cuando esta esta en 0 significa que esta en el menu inicial
  {
  contador1();
  if(valor==2)                                        // Si el boton esta en valor==2, seleccionamos el item de configuraciones
  {
  display.clearDisplay();
  display.setTextSize(1);                             // Escala 1:1 texto
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Seteamos el color resaltado      
  display.setCursor(14,9);                            // Seleccionamos la posicion del texto
  display.println("Menu de opciones");

  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setCursor(14,48);
  display.println("*Configuraciones");
  
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(14,28);
  display.println("*Elegir Opciones");

  display.display();
  }
  else if(valor==1)                                   // Si el boton esta en valor==1, seleccionamos el item de configuraciones
  {
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setCursor(14,9);             
  display.println("Menu de opciones");

  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,48);
  display.println("*Configuraciones");
  
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); 
  display.setCursor(14,28);
  display.println("*Elegir Opciones");

  display.display();
  }
  }
  menu_seleccionar_opciones();
  menu_opcion();
  configuraciones();
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void menu_seleccionar_opciones(){                                          // Funcion del codigo que muestra las opciones a elegir
if(digitalRead(ConfirmarOpcion)==LOW && valor==1 )            // si el boton de seleccionar se presiona y esta la opcion de "seleccionar opciones"
  {
   contadorP=1;
   boton3=1;
  valor=0;
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);    
  display.setCursor(0,9);   
  display.println("Seleccionar Opciones:");

  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,48);
  display.println("*Opcion 2");
  
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,28);
  display.println("*Opcion 1");

  display.display();

contador1();
          if(valor==1 && boton3==1)
  {
  seleccionar=1;
  display.clearDisplay();
  display.setTextSize(1);// Escala 1:1
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(0,9);                                    // Posicion del texto
  display.println("Seleccionar Opciones:");

  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(14,28);
  display.println("*Opcion 1");

  
  display.setTextColor(SSD1306_WHITE); // Escribimos
  display.setCursor(14,48);
  display.println("*Opcion 2");
  
  display.display();

  }
          else if(valor==2 && boton3==1)
  {
   seleccionar=2;
  display.clearDisplay();
  display.setTextSize(1);                                    // Escala de texto 1:1
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(0,9);                                    // Ubicacion del texto
  display.println("Seleccionar Opciones:");

  display.setTextColor(SSD1306_WHITE); // Draw 'inverse' text
  display.setCursor(14,28);
  display.println("*Opcion 1");
  
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.setCursor(14,48);
  display.println("*Opcion 2");

  display.display();

}
}
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void menu_opcion(){                                                  //Funcion que muestra los valores de las opciones

if(digitalRead(5)==LOW && valor==2 && seleccionar==2)
{
  display.clearDisplay();
  display.setTextSize(1);            
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
  display.setCursor(0,19);             
  display.println(EEPROM.read (2));
  display.display();
  delay(5000);
}
else if(digitalRead(5)==LOW && valor==1 && seleccionar==1)
{
  display.clearDisplay();
  display.setTextSize(1);            
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);       
  display.setCursor(0,19);             
  display.println(EEPROM.read (1));
  display.display();
  delay(5000);
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void configuraciones(){                                    // Funcion del codigo que muestra las configuraciones    
 if(digitalRead(5)==LOW && valor==2)             // si seleccionamos "configuracion"
  {
while (digitalRead(5)==LOW && valor==2)
{}
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        
  display.setCursor(0,0);           
  display.println("Escriba la Opcion");
  display.display();
  delay(200);
  valor=0;
  boton3=2;
  contadorP=0;
}
  botonera();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void contador1(){                         //Funcion del contador para seleccionar cualquier opcion
if (contadorP==1)
{
  if (digitalRead(SUBIR)==LOW)
{
 valor++;
 delay(300);
 Serial.print(valor);
 if (valor==3)
{
valor=1;
}

}

else if (digitalRead(BAJAR)==LOW)
{
 valor--;
 delay(300);
 Serial.print(valor);
 if (valor==-1 || valor==0)
{
  valor=2;
}
}
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
//______________________________________________________________


void botonera()
{   
  if (boton3==2)
  {
  // Serial.print("botonera");
    subir();
    bajar();
    FConfirmarLetra();
    FConfirmarOpcion();
    FuncionABC();
}
}
//______________________________________________________________
void subir()  //Bajo en el arreglo abc
{
    if((digitalRead(SUBIR)==LOW))
    {
        boton1=4;
        contadorB++;
        if(contadorB==1)
        {
            letra=tecladoABC[tecla];
            Serial.print(letra);
            display.setTextSize(1);             
            display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
            display.setCursor(0,10);
            display.println(letra);
            display.display();
            tecla++;
        }
        if(contadorB==10000)     //Este numero es 10000 ya que el contador al mantenerse apretado por un cierto periodo de tiempo se ejecuta varias veces y la ideas es que solo ejecute una letra a la vez, ya que el numero es mas chico, aparecerian mas de una letra en el display        
        {
            contadorB=0;
        }
     }       
}
//______________________________________________________________
void bajar()    //Bajo en el arreglo abc
{   
      
        if((digitalRead(BAJAR)==LOW))
        {
            boton1=4;
            contadorB++;
            if(contadorB==1)
            {
                letra=tecladoABC[tecla];
                Serial.print(letra);
                display.setTextSize(1);             
                display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
                display.setCursor(0,10);
                display.println(letra);
                display.display();
                tecla--;  
            }
            if(contadorB==10000)
            {
                contadorB=0;
            }
        }
  
  }
//______________________________________________________________
void FConfirmarLetra() //Cargamos una letra y aumentamos en posicion de la cadena de texto 
{
    if(digitalRead(ConfirmarLetra)==LOW)
    {
         contadorB++;
         if(contadorB==1)
         {
          pixel=pixel+10;
            opciones=opciones+letra;
            Serial.println("");
            Serial.println("Letra confirmada:");
              display.setTextSize(1);             
              display.setTextColor(SSD1306_WHITE);        // Escribimos el texto remarcado
              display.setCursor(0, 23);
              display.println("Letra confirmada");

              display.setTextColor(SSD1306_WHITE);        // Escribimos el texto remarcado
              display.setCursor(pixel,33);
              display.println(letra);
              display.display();
            Serial.println(letra);
            contador++;
          }
          if(contadorB==10000)
          {
             contadorB=0;
          }
   }
}
//______________________________________________________________


void FConfirmarOpcion()  //En cuando el pulsador se apague, se recorre el string opciones, utilizamos una variable contador para no usar el delay y una vez que termina, se reinicia
{
    if(digitalRead(ConfirmarOpcion)==LOW && boton1==4)
    {
        contadorB++;
        if(contadorB==1)
        {
          Serial.println("ConfirmarOpcion");
          display.clearDisplay();
          display.setTextSize(1);             
          display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
          display.setCursor(15,0);
          display.println("Su palabra es:");
            Serial.println("Su palabra es:");
            for(int i=0;i<contador;i++)
            {
                opciones[i];
                display.setTextSize(2);
                display.setCursor(35,20);
                display.setTextColor(SSD1306_WHITE);
                display.println(opciones);
                Serial.print(opciones);
                display.setTextSize(1);
                display.setCursor(0, 43);
                display.setTextColor(SSD1306_WHITE);        // Escribimos el texto remarcado
                display.println("Donde quiere guardar su opcion?");
                display.display();
                guardar=1;             
            }
            opciones= "";
            Serial.println();
        }
        if(contadorB==10000)
        {
            contadorB=0;
        }
    }
//delay(10000);
//menu_guardar();
}
//______________________________________________________________
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
////////////////////////////////////
void retroceso(){
   if (digitalRead(MENU)==LOW){
    Serial.print("Volvemos");
    display.clearDisplay();
    boton3=0;
  }

}
////////////////////////////////////
/*void menu_guardar(){                                          // Funcion del codigo que muestra las opciones a elegir
  if (guardar==1)
  {
  contador1();
  contadorP=1;
  boton3=4;
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);    
  display.setCursor(0,9);   
  display.println("Elija el SLOT");

  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,48);
  display.println("*Opcion 2");
  
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,28);
  display.println("*Opcion 1");

  display.display();


          if(valor==1)
  {
  display.clearDisplay();
  display.setTextSize(1);// Escala 1:1
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(0,9);                                    // Posicion del texto
  display.println("Elija el SLOT");

  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(14,28);
  display.println("*Opcion 1");

  
  display.setTextColor(SSD1306_WHITE); // Escribimos
  display.setCursor(14,48);
  display.println("*Opcion 2");
    display.display();
/*for(int i=0;i<contador;i++)
{
  EEPROM.write(1,opciones[i]);
} 


  }
          else if(valor==2)
  {
   seleccionar=2;
  display.clearDisplay();
  display.setTextSize(1);                                    // Escala de texto 1:1
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);        // Escribimos el texto remarcado
  display.setCursor(0,9);                                    // Ubicacion del texto
  display.println("Elija el SLOT");

  display.setTextColor(SSD1306_WHITE); // Draw 'inverse' text
  display.setCursor(14,28);
  display.println("*Opcion 1");
  
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
  display.setCursor(14,48);
  display.println("*Opcion 2");

  display.display();
 /* for(int i=0;i<contador;i++)
{
  EEPROM.write(2,opciones[i]);
}*/

//}
//}
//}    
