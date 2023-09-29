/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
  Based on the Dallas Temperature Library example
*********/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

// Data wire is conntec to the Arduino digital pin 7
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  lcd.begin(16,2);
  // Start up the library
  sensors.begin();
}

void loop(void){ 
  lcd.clear();
  lcd.setCursor(0,0);
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0));
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print("C");
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  Serial.println(sensors.getTempCByIndex(0));
  delay(1000);
}
