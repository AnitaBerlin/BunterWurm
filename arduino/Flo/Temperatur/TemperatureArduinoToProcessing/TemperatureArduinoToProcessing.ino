/*
  Temperature Arduino to Processing

  This example shows how to prepare the measured temperatures for processing to access them.

  The circuit:
  - Temperature measurement system attached via port 7.

  created 29 September 2023
  by Florian Meyhak
*/

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 7 on the Arduino
#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    Serial.println(tempC);
  } 
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
}
