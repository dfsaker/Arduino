// C++ code
//JUEGO DE SEMAFOROS



#define LED_ROJO1 2
#define LED_ROJO2 5
#define LED_AMARILLO1 3
#define LED_AMARILLO2 6
#define LED_VERDE1 4
#define LED_VERDE2 7

#define  BTN_DOWN 11

void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //pinMode(BTN_UP,INPUT_PULLUP);
 // pinMode(BTN_DOWN,INPUT_PULLUP);
}

void loop()
  
 { 
   digitalWrite(LED_VERDE1, HIGH);
   digitalWrite(LED_ROJO2, HIGH);
   delay(5000);
  
  digitalWrite(LED_VERDE1, LOW);
  digitalWrite(LED_ROJO2, LOW);
  
  digitalWrite(LED_AMARILLO1, HIGH);
  digitalWrite(LED_AMARILLO2, HIGH);
  delay(2000);
   
  digitalWrite(LED_AMARILLO1, LOW);
  digitalWrite(LED_AMARILLO2, LOW);
   
  digitalWrite(LED_ROJO1, HIGH);
  digitalWrite(LED_VERDE2, HIGH);
  delay(5000);
  
   digitalWrite(LED_ROJO1, LOW);
   digitalWrite(LED_VERDE2, LOW);
  
   digitalWrite(LED_AMARILLO1, HIGH);
   digitalWrite(LED_AMARILLO2, HIGH);
    delay(2000);
  
   digitalWrite(LED_AMARILLO1, LOW);
   digitalWrite(LED_AMARILLO2, LOW);
  

  
  
 }
