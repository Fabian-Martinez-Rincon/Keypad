int boton1=A0;
int boton2=A1;
int boton3=A2;
int data1=0;
int data2=0;
int data3=0;


void setup() {
  pinMode(boton1, INPUT);  
  pinMode(boton2, INPUT);  
  pinMode(boton3, INPUT);  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);  


}

void loop() {
  data1=digitalRead(boton1);
  if(data1==LOW){
    digitalWrite(12, HIGH);
    delay(50);
    digitalWrite(12, LOW);
    }
    
  data2=digitalRead(boton2);
  if(data2==LOW){
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
   
    }

    data3=digitalRead(boton3);
    if(data3==LOW){
    digitalWrite(11, HIGH);
    delay(50);
    digitalWrite(11, LOW);
   
    }

}
