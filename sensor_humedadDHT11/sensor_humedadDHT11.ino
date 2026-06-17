#include <DHT11.h>

#include <LCD_I2C.h>

// SENSOR DE HUMEDAD Y TEMEPERATURA DHT11

DHT11 sensor(11);  //CONFIGURAMOS PIN DIGITAL 11 PARA CONECTAR EL SENSOR DHT11

LCD_I2C lcd(0x27,20,4);

float temp, hum;

void setup() 
    { 

      lcd.begin();
      lcd.backlight();
      pinMode(11,INPUT_PULLUP);

     }


void loop()

 {

 
  sensor.read(hum,temp); // LEEMOS LOS PARAMETROS DEL SENSOR DIGITAL 
  
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Hum: ");
  lcd.print(hum);


  lcd.setCursor(0,1);
  lcd.print("Temp:  ");
  lcd.print(temp);


  delay(1200);


}
