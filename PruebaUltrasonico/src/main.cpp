#include <Arduino.h>


//Practica UltraSensor para Repasar
//

//Vamos a declarar las variables de los componentes en este caso para el sensor Ultrasonico y el semaforo	
int Triger = 8;
float Eco =9;


int LedR =2;
int LedA = 3;
int LedV= 4;
int buzer = 7;
long duracion,cm,in;
void setup()
{
  Serial.begin(9600);
  pinMode(LedV,OUTPUT);
  pinMode(LedA,OUTPUT);
  pinMode(LedR,OUTPUT);
  pinMode(Eco, INPUT);
  pinMode(Triger, OUTPUT);
  pinMode(buzer,OUTPUT);

  digitalWrite(Triger,LOW);
}


void loop()
{
  //prender el triger para que mande el eco.
  digitalWrite(Triger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Triger,LOW);

  duracion=pulseIn(Eco,HIGH);
  cm= duracion / 59.0;
  in=(duracion/2)/74;

  Serial.print ("Distancia :");
  Serial.println (cm);
  
  if (cm <10) {
    digitalWrite(LedV,LOW);
    digitalWrite(LedA,LOW);      
    digitalWrite(LedR,HIGH);
  } else if (cm <30) {
    digitalWrite(LedV,LOW);
    digitalWrite(LedA,HIGH);      
    digitalWrite(LedR,LOW);
  } else if (cm <100)     {
    digitalWrite(LedV,HIGH);
    digitalWrite(LedA,LOW); 
    digitalWrite(LedR,LOW);
  } 
  else {
    digitalWrite(LedV,LOW);
    digitalWrite(LedA,LOW);      
    digitalWrite(LedR,LOW);
  }


  Serial.println(cm);
  
 
 
}


 