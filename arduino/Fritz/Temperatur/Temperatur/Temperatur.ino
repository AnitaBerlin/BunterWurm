
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <OneWire.h>
#include <DallasTemperature.h>


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  sensors.begin();
  lcd.begin(16, 2);

}

void loop(void){ 
  lcd.setCursor(0, 0);
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  lcd.print("Grad Celsius: ");
  lcd.setCursor(0, 1);
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  lcd.print(sensors.getTempCByIndex(0)); 
 // Serial.print(" - Fahrenheit temperature: ");
 // Serial.println(sensors.getTempFByIndex(0));


  uint8_t buttons = lcd.readButtons();
  if (buttons) 
  {
    if (buttons & BUTTON_UP) {
        lcd.setBacklight(RED);
    }
    if (buttons & BUTTON_DOWN) {
        lcd.setBacklight(YELLOW);
    }
    if (buttons & BUTTON_LEFT) {
        lcd.setBacklight(GREEN);
    }
    if (buttons & BUTTON_RIGHT) {
        lcd.setBacklight(VIOLET);
    }
  }
    delay(1000);

    Serial.println(sensors.getTempCByIndex(0)); 
}
