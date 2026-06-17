#include <LCD_I2C.h>



LCD_I2C lcd(0x27,20,4);

//REGULADOR DE VELOCIDAD CON POTENCIOMETRO 



#define VOL 3

#define  LED 4

#define BUZ 7



void setup() 
    { 

      lcd.begin();
      lcd.backlight();
      pinMode(3,OUTPUT);
      pinMode(4,OUTPUT);
      pinMode(7,OUTPUT);

      // put your setup code here, to run once:

    }

int brillo;
int adc;
int Porcentaje;

void loop()

 {
 


  adc=analogRead(A2); // LEEMOS EL VOLTAJE DEL POTE EN UNA ENTRADA ANALOGICA A2 VALOR ENTRE 0 Y 1023

  brillo= adc/4; // CONVERTIMOS EL VALOR LEIDO EN EL PIN ANALOGICO ENTRE 0 Y 255 QUE ES LA SEÑAL PWM
  

  lcd.clear();
  lcd.print("Voltaje: ");



  Porcentaje=brillo*100/255;

  lcd.print(Porcentaje); // SE CALCULA EN PORCENTAJES CUANDO BRILLO ALCANZA VALOR 255 ES 100%

  if (Porcentaje>98) 
  {

    digitalWrite(BUZ, HIGH);
    digitalWrite(LED, HIGH);
    lcd.setCursor(1, 5);
    lcd.print("VOLTAJE MAXIMO!");
    delay(200);
    lcd.clear();
   // lcd.print("               ");
    digitalWrite(BUZ, LOW);
    digitalWrite(LED, LOW);
    
    


  }

  lcd.print(" %");

  analogWrite(VOL,brillo);
  
  delay(200);

  }
