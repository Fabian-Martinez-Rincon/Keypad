# Practicas-Botonera
## Introducción
En este informe se mostrará y describirá todo lo cumplido por el alumno Fabian Martinez Rincon de la Escuela Técnica numero 6 Albert Thomas, en el sector Arduino.
Durante el periodo de prácticas aprenderemos el uso y funciones de las herramientas y módulos que nos brinda Arduino y como aprovecharlas a lo largo de nuestros proyectos.
Vamos a realizar una botonera en el cual mediante dos teclas nos permite subir y bajar en un abecedario y poder elegir letra por letra hasta enviar una frase por bluetooh a nuestro receptor que se encuentra en el lugar deseado por el usuario.En este informe se mostrará y describirá todo lo cumplido por el alumno Fabian Martinez Rincon de la Escuela Técnica numero 6 Albert Thomas, en el sector Arduino. Durante el periodo de prácticas aprenderemos el uso y funciones de las herramientas y módulos que nos brinda Arduino y como aprovecharlas a lo largo de nuestros proyectos. Vamos a realizar una botonera en el cual mediante dos teclas nos permite subir y bajar en un abecedario y poder elegir letra por letra hasta enviar una frase por bluetooh a nuestro receptor que se encuentra en el lugar deseado por el usuario.

## Materiales
- Arduino UNO (2)
- LCD OLED I2C 128 x 64 (1)
- LCD 16 x 2 SPI (1)
- Pulsadores (4)
- Modulo Bluetooh HC - 06 (1)
- Modulo Bluetooh HC - 05 (1)
- Transformador de 5v (2)
- Buzzer (1)
#### Cuadro 1:1 Tabla de componentes

### Diagrama General
![Diagrama General](Images/diagrama.png)

### Diagrama Botonera

![Diagrama General](Images/diagrama2.png)

## Desarrollo
Al principio programamos los pulsadores para que mande una palabra escrita por el usuario al puerto serial. Para esto el usuario tiene que navegar por el array
abc a través de los pulsadores letra por letra hasta encontrar la que el desea y cuando termine poder enviarla. El maestro que será el encargado de mandar por
puerto serial estos datos, para que, al momento de ingresar el botón de “terminar palabra”, solo se mande la palabra cargada. Tal y como se muestra en la “figura
10”.

### Circuito con pulsadores y pantalla serial.
![Diagrama General](Images/1.png)

Una vez tenemos el circuito que se muestra en la “figura 9”, para comprobar que funciona, ingresamos cierta cantidad de letras para estar al tanto del
funcionamiento (Como se muestra en la figura 10). La letra “ñ” no está en nuestro lenguaje, pero esto lo corregimos más adelante.
En este caso utilizamos el serial para comprobar de que no tenemos errores en el código ya que puede pasar que por errores de conexión tardemos mucho mas
en encontrar el error que si solo utilizamos el puerto serial. A demás, mas adelante nos ayudara ya que sabemos que tiene que mostrar por el display y
que no tiene que mostrar en caso de errores.

### Pantalla serial.
![Diagrama General](Images/2.png)

En la “figura 11” se cambian los pulsadores pull down que estábamos utilizando por pulsadores pull up, ya que nos permitía utilizar las resistencias internas del
Arduino y ahorrar en componentes (que en este caso no son necesarias) y el circuito queda mas compacto.

### Esquema de Pulsadores Pull Up.
![Diagrama General](Images/3.png)

Para poder utilizar los pulsadores que tenemos en la “figura 11” necesitamos cambiar la configurar de los pines actuales, ya que estaban en configuración pull
down. Para cambiarlos tenemos que configurar los modos en los que Arduino lee los pines (como se muestra en la figura 12), tanto de entrada como de salida.
Para que nosotros lo podamos utilizar, tenemos que tener los pines en el modo IPUT_PULLUP ya que nos permite tener 5v siempre a la salida.
Agregamos los Modulo Bluetooth HC-06 y HC-05 (Como se muestra en la figura 5). En el caso de que solamente tengamos estos módulos en simulación tenemos que crear dos puertos virtuales para que proteus nos permita leer ambos módulos. Utilizamos el programa que se muestra en la “figura 13” para simular estos pines. (Las librerías que utilizamos para los módulos, las dejamos al final del informe).

### Simulador de pines.
![bloque](Images/4.png)

Una vez que terminamos de armar el código y de poder configurar todos los pines necesarios para poder utilizar los módulos bluetooh en proteus, acomodamos las conexiones tanto de los pulsadores, como de los módulos para poder utilizarlo desde ambas pantallas serial. En la “figura 14” tenemos tanto el receptor como el emisor. Y en la “figura 15” tenemos una imagen que nos muestra como es el funcionamiento en ambas pantallas serial.

## Circuito con pulsadores imprementados.
![bloque](Images/5.png)

## Circuito con puertos serial en simulación.
![bloque](Images/6.png)


En la “figura 15” imagen tenemos al circuito funcionando y mostrando como se vería en el seria al enviarse una palabra completa. Utilizamos el guion como
símbolo de “espacio”. Una vez que se envía la palabra se reinicia. En la “figura 16” se muestra el que código del pulsador “BAJAR”, en lugar de
usar un “delay ()” que es una función bloqueante, utilizamos un contador, el numero en contadorB es 10000 ya que el pulsador iba mas lento que el recorrido
del mismo y volvía a ejecutar otra letra. Es por eso que ese es el valor mínimo.

## Configuración de Pulsadores.
![bloque](Images/7.png)

### Arduino Maestro
Por parte del circuito del Arduino maestro, en la “figura 16“se muestra como quedo luego de ingresar el oled que utilizaremos como interfaz y menú para el
cliente. En el lcd que se muestra en la “figura 16” se muestra la interfaz y a medida que nosotros pulsamos los interruptores, podemos movernos entre las opciones del menú que hemos cargado con anterioridad.

## Ensamble completo del Arduino maestro.
![bloque](Images/8nose.png)

## Circuito Impreso Arduino maestro.
![bloque](Images/8.png)

Tenemos el circuito impreso mostrado en la figura 17 en caso de que vayamos a montarlo o que mandemos a hacer la plaqueta pcb. También hicimos el modelaje de la plaqueta en 3D para que el usuario que arme el circuito tenga una visión mas amplia de como quedaría una vez completado. Tal y como se
muestra en las “figuras 18 y 19”

## Parte trasera de la placa.
![bloque](Images/9.png)

## Parte delantera de la placa.
![bloque](Images/10.png)

Tuvimos que utilizar un Jumper ya que no se nos presento otra forma de completarlo.

## Diagrama de flujo Arduino esclavo.
![bloque](Images/10.png)
