/* TMP36 (TMP36GT9Z) [S071] : http://rdiot.tistory.com/44 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
const int TMP36_pin = A0;
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{ 
  lcd.setCursor(0,0);
  lcd.print("S071:TMP36");
 
  int sensorValue = analogRead(TMP36_pin);  
  float mVoltage = sensorValue * 5000.0/1024.0;
  float temperatureC = (mVoltage - 500) / 10.0;  
 
  lcd.setCursor(0,1);
  lcd.print("temperature=" + (String)temperatureC + "'C");
 
  delay(1000);
}
