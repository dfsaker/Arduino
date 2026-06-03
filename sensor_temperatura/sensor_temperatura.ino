#include <LCD_I2C.h>

LCD_I2C lcd(0x27,20,4);


// variable para guardar el numero de pin donde conectaremos el sensor LM35DZ
int pinsensor = A1;
 
#define BUZ 8

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

  analogReference(INTERNAL);



 

  lcd.begin(20,4);
  lcd.backlight();

  // Guardamos los caracteres en la memoria interna del LCD
  lcd.createChar(0, termometro);  // Asigna el termómetro al espacio 0
  lcd.createChar(1, rayoVoltaje); // Asigna el rayo al espacio 1
  

 
 
}
 
/**
   Función loop: se ejecuta continuamente mientras el arduino permanece encendido
*/
void loop() {

  // variable local para el valor del ADC que va en un rango de 0 a 1023

  int adc = analogRead(pinsensor);
 
  // calculamos la temperatura con la fórmula siguiente

  float temperatura = (110.0 * adc) / 1024.0;
 
  // borrar toda la pantalla

  lcd.clear();

  // imprimir a la pantalla una leyenda

 
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); // Imprime el termómetro (espacio 0)
  lcd.print(" Temp:");  

  lcd.setCursor(0, 1); 
  lcd.write(byte(1)); // Imprime el rayo de voltaje (espacio 1)
  lcd.print(" Volt:"); 
  

  // CONVERSION DE ADC A VOLTAJE 

  float voltaje = (adc * 5.0) / 1023.0;
 
  delay(200);


  
  // imprimir el valor de la medición de temperatura

  lcd.setCursor(7, 0); 

  lcd.print(temperatura, 1);

  // secuencia de escape para imprimir el simbolo de grados que forma
  // parte de los caracteres especiales de la pantalla LCD

  lcd.print(" \337C");

  //IMPRIMIR VALOR DE VOLTAJE 
  lcd.setCursor(7, 1);
  lcd.print(voltaje);
  lcd.print(" v");
 
 
  

  


//CONDICION SI TEMPERATURA ES MAYOR A 40 GRADOS 

  if (temperatura>40)
   {

    lcd.setCursor(0,3);
   // digitalWrite(BUZ,HIGH);
    delay(500);
    digitalWrite(BUZ,LOW);
    int i;
 
    for (i=5;i>0;i--)
        {
          // Posicionamos y mandamos el texto centrado   lcd.setCursor(columnaInicio, fila);
      
          lcd.setCursor(3,3);
          lcd.print("Temp Maxima!!");
          delay(250);
          lcd.clear();
          delay(250);
          digitalWrite(BUZ, HIGH);
          delay(250);
          digitalWrite(BUZ, LOW);
        }
 
    
          
   }
 
  // esperamos medio segundo  antes de realizar una nueva medición
  // podemos personalizar este retardo a nuestro gusto
  delay(500);
}