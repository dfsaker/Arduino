#include <LCD_I2C.h>


LCD_I2C lcd(0x27,20,4);

int i;

#define LED_BLANCO 5
#define LED_ROJO 4
#define BUZ 3


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_ROJO,OUTPUT); // CONFIGURA EL PIN DIGITAL 4 COMO SALIDA 
  pinMode(LED_BLANCO,OUTPUT);

  pinMode(BUZ,OUTPUT);

  pinMode(2,OUTPUT);

  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  digitalWrite(LED_ROJO, HIGH);  // CAMBIO EL NIVEL DEL VOLTAJE DEL PIN 4 A HIGH
  digitalWrite(LED_BLANCO, LOW);

  digitalWrite(2, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  digitalWrite(BUZ, HIGH);



 


  lcd.begin();
  lcd.backlight();

  for (i=10;i>0;i--)
   {
    // Posicionamos y mandamos el texto centrado   lcd.setCursor(columnaInicio, fila);
 
    lcd.setCursor(9,0);
    lcd.print(i);
    delay(200);
    lcd.clear();
    delay(200);
    digitalWrite(BUZ, HIGH);
    digitalWrite(LED_ROJO, HIGH);
    delay(200);
    digitalWrite(BUZ, LOW);
    digitalWrite(LED_ROJO, LOW);
    
    

   }

    lcd.setCursor(6,0);
    digitalWrite(BUZ, HIGH);
    digitalWrite(LED_ROJO, HIGH);
    lcd.print("BOOM!!!");
    delay(1500);
    lcd.clear();
  

   digitalWrite(BUZ, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:




/* 
  for (i=10;i>0;i--)
   {
    lcd.print(i);
    delay(200);
    lcd.clear();
    delay(200);
    digitalWrite(BUZ, HIGH);
    delay(200);
    digitalWrite(BUZ, LOW);
   }

  digitalWrite(BUZ, HIGH);
  lcd.print("BOOOM");
  delay(1500);
  lcd.clear();
  
 */ 

  
}




