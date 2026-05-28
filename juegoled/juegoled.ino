#include <LCD_I2C.h>

//JUEGO LUCES LED . . 

/* 
   #define : ordenes para el entorno del desarollo o compilador, no recibe esta info la placa 

   #define MOTOR 3  // REEMPLAZA EL NRO 3 POR LA PALABRA MOTOR PARA NO CONFUDIRSE DURANTE LA PROGRAMACION 

  */

  #define LED_ROJO 4


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ROJO,OUTPUT); // CONFIGURA EL PIN DIGITAL 4 COMO SALIDA 
  pinMode(5,OUTPUT);

  pinMode(3,OUTPUT);

  pinMode(2,OUTPUT);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  digitalWrite(LED_ROJO, HIGH);  // CAMBIO EL NIVEL DEL VOLTAJE DEL PIN 4 A HIGH
  digitalWrite(5, HIGH);

  digitalWrite(3, HIGH);

  digitalWrite(2, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:


  digitalWrite(LED_ROJO, HIGH);
  delay(500);
  digitalWrite(5, HIGH);

  digitalWrite(LED_ROJO, LOW);
  delay(500);
  digitalWrite(5, LOW);
  

  
}


