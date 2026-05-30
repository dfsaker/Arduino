// C++ code
//CODIGO SECUENCIAL PARA ENCENCEDER LAS 6 LUCES

byte pin=1;


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
   digitalWrite(pin, HIGH);
   delay(150);
   digitalWrite(pin, LOW);
   delay(150);
        
  if ( digitalRead(BTN_UP) == LOW &&  pin <6) // &&  va a tener 0v (LOW) cuando se apriente el boton>>
    
      { 
        pin++;
      }
  if ( digitalRead(BTN_DOWN) == LOW && pin>1) // &&  va a tener 0v (LOW) cuando se apriente el boton
    
      { 
        pin--;
      }
  
 
  
}