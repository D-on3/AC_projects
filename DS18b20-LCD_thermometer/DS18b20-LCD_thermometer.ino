//Follow us on other social media

//https://www.youtube.com/c/ZinTechIdeas
//https://www.facebook.com/zin.techideas.3
//https://www.instagram.com/zintechideas/
//https://twitter.com/Zintechideas
//https://zintechideas.ir/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define ONE_WIRE_BUS 2
 
LiquidCrystal_I2C lcd(0x27, 16, 2); 


// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);
 
 
void setup(void)
{
  sensors.begin();
  Serial.begin(9600);
lcd.init(); //display initialization
lcd.backlight();
}
void loop(void)
{ 

  sensors.requestTemperatures();

 

  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(7,1);
  lcd.print("C");
  lcd.setCursor(9,1);
  lcd.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  lcd.setCursor(15,1);
  lcd.print("F");
  
  
  delay(1000);
} 
