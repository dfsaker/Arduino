#include <LCD_I2C.h>

LCD_I2C lcd(0x27,20,4);


 
#define BUZ 7
#define LED 3

int adc;
float voltaje;
float temperatura;

// MATRIZ DE CARACTERES

// Matriz de 5x8 píxeles para el Termómetro (Dirección 0)
byte termometro[8] = {
  B00100,  //   *  
  B01010,  //  * * 
  B01010,  //  * * 
  B01010,  //  * * 
  B01110,  //  *** 
  B11111,  // *****
  B11111,  // *****
  B01110   //  *** 
};

// Matriz de 5x8 píxeles para el Rayo de Voltaje (Dirección 1)
byte rayoVoltaje[8] = {
  B00010,  //    *
  B00110,  //   **
  B01100,  //  **  
  B11111,  // *****
  B00110,  //   **
  B01100,  //  **  
  B01000,  //  *   
  B00000   //      
};



/**
  Función setup: se ejecuta una vez cuando encendemos el arduino
*/
void setup() {

  // utilizamos la referencia interna de voltaje del convertidor A/D
  // esta función configura la referencia del ADC ya sea interna o externa

  // para este programa utilizaremos la referencia interna de 1.1 volts


  pinMode(BUZ,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);

 
  




  digitalWrite(BUZ,HIGH);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(BUZ,LOW);
  digitalWrite(LED,LOW);
 

  lcd.begin(20,4);
  lcd.backlight();

  // Guardamos los caracteres en la memoria interna del LCD
  lcd.createChar(0, termometro);  // Asigna el termómetro al espacio 0
  lcd.createChar(1, rayoVoltaje); // Asigna el rayo al espacio 1
  

 
 
}
 

void loop() 
{

            

  adc = analogRead(A1);  // variable local para el valor del ADC que va en un rango de 0 a 1023

  voltaje = (float) adc * 5.0 / 1023.0;  // CONVERSION DE ADC A VOLTAJE 
  temperatura = voltaje * 1 / 0.01;  // calculamos la temperatura con la fórmula siguiente
  
  // borrar toda la pantalla

  //lcd.clear();

  // IMPRIME CARACTERES Y LEYENDA TEMP Y VOLT 


  lcd.setCursor(0, 0);
  lcd.write(byte(0)); // Imprime el termómetro (espacio 0)
  lcd.print(" Temp:");  

  lcd.setCursor(0, 1); 
  lcd.write(byte(1)); // Imprime el rayo de voltaje (espacio 1)
  lcd.print(" Volt:"); 
  

  //delay(10);


  
  // IMPRIME VALOR DE TEMPERATURA 
  lcd.setCursor(7, 0); // imprime en columna 7 y fila 0 
  lcd.print(temperatura, 1);
  lcd.print(" \337C");

  //IMPRIME  VALOR DE VOLTAJE 
  lcd.setCursor(7, 1); // imprime en columna 7 y fila 1 
  lcd.print(voltaje);
  lcd.print(" v");


  
  if (temperatura>40)   //CONDICION SI TEMPERATURA ES MAYOR A 40 GRADOS 

      {
      
        int i;
        
        //for (i=5;i>0;i--)
      
        // lcd.clear();
        lcd.setCursor(3,3);
        lcd.print("Temp Maxima!!");
        digitalWrite(BUZ, HIGH);
        digitalWrite(LED, HIGH);
        delay(300);
       
        digitalWrite(BUZ, LOW);
        digitalWrite(LED, LOW);
        lcd.setCursor(3,3);
        lcd.print("             ");
       
              
            
      }   

                  
  // esperamos medio segundo  antes de realizar una nueva medición

 delay(500);         
 }             
                    
            
          
           
