//I2C SLAVE CODE
//I2C Communication between Two Arduino
//CircuitDigest
//Pramoth.T

#include<Wire.h>                          //Library for I2C Communication functions
#include<LiquidCrystal.h>                 //Library for LCD display function
LiquidCrystal lcd(2, 7, 8, 9, 10, 11);    //Define LCD Module Pins (RS,EN,D4,D5,D6,D7)

byte SlaveReceived = 0;

void setup() 

{
  lcd.begin(16,2);                        //Initilize LCD display
  lcd.setCursor(0,0);                     //Sets Cursor at first line of Display 
  lcd.print("Circuit Digest");            //Prints CIRCUIT DIGEST in LCD 
  lcd.setCursor(0,1);                     //Sets Cursor at second line of Display
  lcd.print("I2C 2 ARDUINO");             //Prints I2C ARDUINO in LCD
  delay(5000);                            //Delay for 5 seconds
  lcd.clear();                            //Clears LCD display
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(8);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 

void loop(void) 
{
  lcd.setCursor(0,0);                              //Sets Currsor at line one of LCD
  lcd.print(">>  Slave  <<");                      //Prints >> Slave << at LCD
  lcd.setCursor(0,1);                              //Sets Cursor at line two of LCD
  lcd.print("MasterVal:");                         //Prints MasterVal: in LCD
  lcd.print(SlaveReceived);                        //Prints SlaveReceived value in LCD received from Master
  Serial.println("Slave Received From Master:");   //Prints in Serial Monitor 
  Serial.println(SlaveReceived); 
  delay(500);
  lcd.clear();
  
}

void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master
{
   SlaveReceived = Wire.read();                    //Used to read value received from master and store in variable SlaveReceived
}

void requestEvent()                                //This Function is called when Master wants value from slave
{
  int potvalue = analogRead(A0);                   // Reads analog value from POT (0-5V)
  byte SlaveSend = map(potvalue,0,1023,0,127);    // Convert potvalue digital value (0 to 1023) to (0 to 127)
  Wire.write(SlaveSend);                          // sends one byte converted POT value to master
}
