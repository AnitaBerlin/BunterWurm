/*
  Temperature Display

  This example shows how to show the measured temperature on a connected Display

  The circuit:
  - Display attached via ports SV, 2, 3 and GRD.
  - Temperature measurement system attached via port 7.

  created 29 September 2023
  by Florian Meyhak
*/

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

// Data wire is plugged into port 7 on the Arduino
#define ONE_WIRE_BUS 7

// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();

  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 2);
  lcd.setBacklight(WHITE);
}


/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  //Import Button Data
  uint8_t buttons = lcd.readButtons();

  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  lcd.setCursor(0, 0); // Write in top row
  lcd.print("Temperature:");

  sensors.requestTemperatures(); // Send the command to get temperatures

  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    lcd.setCursor(0, 1); //Write in bottom row
    lcd.print(tempC); //put in measure temperatures
  } 
  else
  {
    lcd.print("Error: Could not read temperature data"); //give out error warning
  }
}
