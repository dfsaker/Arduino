#include <LCD_I2C.h>



LCD_I2C lcd(0x27,20,4);

//REGULADOR DE VELOCIDAD CON POTENCIOMETRO 



#define LED 3



void setup() 
    { 

      lcd.begin();
      lcd.backlight();
      pinMode(3,OUTPUT);

      // put your setup code here, to run once:

    }

int brillo;
int adc;

void loop()

 {
  // put your main code here, to run repeatedly:


  adc=analogRead(A2); // LEEMOS EL VOLTAJE DEL POTE EN UNA ENTRADA ANALOGICA A2 VALOR ENTRE 0 Y 1023

  brillo= adc/4; // CONVERTIMOS EL VALOR LEIDO EN EL PIN ANALOGICO ENTRE 0 Y 255 QUE ES LA SEÑAL PWM
  

  lcd.clear();
  lcd.print("Brillo: ");

  lcd.print(brillo*100/255); // SE CALCULA EN PORCENTAJES CUANDO BRILLO ALCANZA VALOR 255 ES 100%

  lcd.print(" %");

  analogWrite(LED,brillo);
  
  delay(100);

  }
