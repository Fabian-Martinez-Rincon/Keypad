# Keypad.
## Introduction.
This report will show and describe everything accomplished by the student Fabian
Martinez Rincon from the Albert Thomas Technical School number 6, in the sector
Arduino. During the internship period we will learn the use and functions of the
tools and modules that Arduino gives us and how to take advantage of them throughout
of our projects. We are going to make a keypad in which by means of two
keys allows us to go up and down in an alphabet and to be able to choose letter by letter
until sending a phrase by bluetooh to our receiver that is in the
place desired by the user.

## Components.
- Arduino UNO (2)
- LCD OLED I2C 128 x 64 (1)
- LCD 16 x 2 SPI (1)
- Buttons (4)
- Module Bluetooh HC - 06 (1)
- Module Bluetooh HC - 05 (1)
- Transformer 5v (2)
- Buzzer (1)
#### Square 1:1 Component Table.

### General diagram.
![](Images/diagrama.png)

### Keypad diagram.

![](Images/diagrama2.png)

## Progress
At the beginning we program the push buttons to send a word written by the user to the serial port. For this the user has to navigate through the array
abc through the letter by letter pushbuttons until you find the one you want and when you finish sending it. The teacher who will be in charge of sending for
serial port this data, so that, when entering the "finish word" button, only the loaded word is sent. As shown in “figure
10 ".

### Circuit with push buttons and serial display.
![Diagrama General](Images/1.png)

Once we have the circuit, to check that it works, we enter a certain number of letters to be aware of how it works. The letter “ñ” is not in our language, but we will correct this later.
In this case we use the serial to check that we do not have errors in the code since it may happen that due to connection errors we take much longer in finding the error that if we only use the serial port. In addition, later it will help us since we know what it has to show on the display and it doesn't have to show in case of errors.

### Serial display.
![Diagrama General](Images/2.png)

We changed the pull down buttons that we were using for pull up buttons, since it allowed us to use the internal resistors of the
Arduino and save on components (which in this case are not necessary) and the circuit is more compact.

### Diagram pushbutton Pull Up.
![Diagrama General](Images/3.png)

In order to use the buttons we need to change the configuration of the current pins, since they were in pull configuration
down. To change them we have to configure the modes in which Arduino reads the pins, both input and output.
In order for us to use it, we have to have the pins in the IPUT_PULLUP mode since it allows us to always have 5v at the output.
We add the HC-06 and HC-05 Bluetooth Module. In the case that we only have these modules in simulation we have to create two virtual ports so that proteus allows us to read both modules. We use the program to simulate these pins. (The libraries that we use for the modules, we leave them at the end of the report).

### Pins simulator.
![bloque](Images/4.png)

Once we have finished assembling the code and being able to configure all the necessary pins to be able to use the bluetooh modules in proteus, we arrange the connections of both the pushbuttons and the modules to be able to use it from both serial screens. We have both the receiver and the sender. We have an image that shows us how it works on both serial screens.

## Circuit with printed pushbuttons.
![bloque](Images/5.png)

## Circuit with serial ports in simulation.
![bloque](Images/6.png)

We have the circuit working and showing what it would look like in the series when a complete word is sent. We use the script as
symbol for "space". Once the word is sent it restarts. In the button code “DOWN”, instead of use a "delay ()" which is a blocking function, we use a counter, the number in counterB is 10000 since the button was slower than the path
of the same one and returned to execute another letter. That is why that is the minimum value.

## Pushbutton Configuration.
![bloque](Images/7.png)

### Arduino master
On the part of the master Arduino circuit, it is shown how it looks after entering the oled that we will use as interface and menu for the
client. The interface is displayed on the LCD and as we press the switches, we can move between the menu options that we have loaded previously.

## Complete assembly of the Arduino master.
![bloque](Images/8nose.png)

## Master Arduino Printed Circuit.
![bloque](Images/8.png)

Tenemos el circuito impreso en caso de que vayamos a montarlo o que mandemos a hacer la plaqueta pcb. También hicimos el modelaje de la plaqueta en 3D para que el usuario que arme el circuito tenga una visión mas amplia de como quedaría una vez completado. 

## Parte trasera de la placa.
![bloque](Images/9.png)

## Parte delantera de la placa.
![bloque](Images/10.png)

Tuvimos que utilizar un Jumper ya que no se nos presento otra forma de completarlo.

## Diagrama de flujo Arduino esclavo.
![bloque](Images/diagrama3.png)

### Arduino Esclavo.
Una vez que tenemos el maestro procedemos a instalar y programar el Arduino esclavo, este mismo nos servirá como un
receptor por el que el Arduino maestro mande una palabra escrita por el usuario y muestre en el lcd que tengamos conectado este mismo Arduino y que pueda
alertar de que llego una frase.

## Ensamble del Arduino esclavo.
![bloque](Images/nueva.png)

El circuito impreso de Arduino esclavo se muestra en la imagen, tenemos tanto el Arduino como el display de 16x2.

## Circuito impreso Arduino Esclavo.
![bloque](Images/me.png)

### Circuito impreso en 3d del Arduino esclavo.
Para tener una visión de cómo quedaría el circuito ya montado, procedemos a mostrar el circuito en 3d..

## Impreso trasero.
![bloque](Images/3d.png)

## Impreso delantero.
![bloque](Images/32d.png)

## Simulación en Proteus.

Tenemos imágenes de lo que es la simulación en proteus por parte del Arduino esclavo y en la figura 12.1 tenemos otra imagen de la simulación, pero en esta ya se eligió la opción de confirmar la opción demandada.

### Oled Confirmando Opción.
![bloque](Images/11.png)

Lo primero que hacer es guardar la opción 1 ya que tenemos un array en el que vamos guardando las palabras que vamos escribiendo. Si ingresamos otra vez
a nuestro circuito, ya tendríamos las opciones cargadas por la eeprom. Cuando cargamos las opciones, nos quedaría de la forma en la que se encuentra en la
imagen de la “figura 26"

### Oled eligiendo slot.
![bloque](Images/12.png)

Acá, independientemente de la opción que se elija, ya la podemos mostrar tanto por el display como por el serial de cómo se muestra en las imágenes de la “figura 27” y “figura 28

## Terminales del Emisor y Receptor.
![bloque](Images/13.png)

En la “figura 29” se muestra cómo se vería el mensaje enviado a través del Arduino maestro en el Arduino esclavo

## LCD Receptor.
![bloque](Images/15popo.png)

Una vez terminado el display del Arduino esclavo como se muestra en la “figura 29“procedemos a conectar en el Arduino maestro el display principal, con este mismo controlaremos el menú principal en donde nuestro cliente podrá insertar las opciones y luego guardarlas, con una interfaz en la que muestra el nombre del colegio. El esquema final sería el que se muestra en la “figura 30

## Ensamblaje Final del Proyecto.
![bloque](Images/16.png)

### Conclusión
En la primera parte del trabajo nos dedicamos al armado básico del Arduino
maestro (Los pulsadores más los monitores serial), en este mismo programamos
para que el cliente pueda ingresar palabras a su comodidad y mandarlas al menú
principal. Por parte del receptor, tenemos un Arduino esclavo el cual se encarga
de cargar la frase que fue cargada por el Arduino maestro y mandarla al segundo
display de 16x2, en este mismo se mostrara el mensaje enviado por el cliente.
Al finalizar el proyecto, pudimos terminar con todos los objetivos planteados ya
que cumple con todos los requerimientos necesarios, para el funcionamiento
básico del circuito.

### Mejoras
- Hacer una api para controlar los pulsadores
- Aumentar la velocidad de lectura de teclas
- Pulir la interfaz de usuario
- Tener alimentación para ambos Arduinos


