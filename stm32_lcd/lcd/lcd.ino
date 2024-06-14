#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 20, 4);
void setup()
{
lcd.init(); //display initialization
}
void loop()
{
lcd.backlight(); // activate the backlight
lcd.setCursor(0, 0); // stand in the front line
lcd.print(" Obichaite");  // Display the word 'card' on the I2C LCD 1602 display
lcd.setCursor(0,1);  // stand on the second line
lcd.print(" Se"); // Display the word 'Arduino'
}
