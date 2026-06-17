#include <DHT11.h>

#include <LCD_I2C.h>

DHT11 sensor(11);


LCD_I2C lcd(0x27,20,4);

float temp, hum;

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

      pinMode(11,INPUT_PULLUP);

      // put your setup code here, to run once:
    

    }


void loop()

 {

 
  sensor.read(hum,temp);
  
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Hum: ");
  lcd.print(hum);


  lcd.setCursor(0,1);
  lcd.print("Temp:  ");
  lcd.print(temp);


  delay(1200);




 

  }
