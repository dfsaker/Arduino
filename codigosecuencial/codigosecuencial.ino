#include <LCD_I2C.h>

// C++ code
//CODIGO SECUENCIAL PARA ENCENCEDER LAS 6 LUCES

byte pin=0;


#define BTN_UP 12

#define  BTN_DOWN 11

void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(BTN_UP,INPUT_PULLUP);
  pinMode(BTN_DOWN,INPUT_PULLUP);
}

void loop()
  
{  
  
        
  if ( digitalRead(BTN_UP) == LOW &&  pin <6) // SI APRETO BTN_UP Y ADEMAS PIN ES MENOR QUE 6
    
      {  
        pin++; // INCREMENTO UNA UNIDAD 
        digitalWrite(pin, HIGH);
    	  delay(150);
      }
  
  if ( digitalRead(BTN_DOWN) == LOW && pin>1) // SI APRETO BTN_UP Y ADEMAS PIN ES MAYOR QUE 1
    
      { digitalWrite(pin, LOW);
        pin--; // DECREMENTO UNA UNIDAD 
        delay(150);
      }
  
 
  
}
  