//Author: Florian Fritz Wiede
//Date: 29/09/2023
//Name: Temperatur

#include <Wire.h>                                    //importing libarys           
#include <Adafruit_RGBLCDShield.h>                   //importing libarys                             
#include <utility/Adafruit_MCP23017.h>               //importing libarys                                 
#include <OneWire.h>                                 //importing libarys               
#include <DallasTemperature.h>                       //importing libarys                         


Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1                                     //defining colors                        
#define YELLOW 0x3                                  //defining colors                            
#define GREEN 0x2                                   //defining colors                          
#define TEAL 0x6                                    //defining colors                          
#define BLUE 0x4                                    //defining colors                          
#define VIOLET 0x5                                  //defining colors                            
#define WHITE 0x7                                   //defining colors                          
#define ONE_WIRE_BUS 7                              //defining colors                                

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
  
  lcd.print("Grad Celsius: ");    //prints that in the first line
  lcd.setCursor(0, 1);            //puts cursor in second column
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  lcd.print(sensors.getTempCByIndex(0)); 



  uint8_t buttons = lcd.readButtons();
  if (buttons) 
  {
    if (buttons & BUTTON_UP) {                                                                  
        lcd.setBacklight(RED);                                                                  
    }                                              //defining buttons to change color                   
    if (buttons & BUTTON_DOWN) {                   //defining buttons to change color                                               
        lcd.setBacklight(YELLOW);                  //defining buttons to change color                                               
    }                                              //defining buttons to change color                   
    if (buttons & BUTTON_LEFT) {                   //defining buttons to change color                                               
        lcd.setBacklight(GREEN);                   //defining buttons to change color                                               
    }                                              //defining buttons to change color                   
    if (buttons & BUTTON_RIGHT) {                  //defining buttons to change color                                               
        lcd.setBacklight(VIOLET);                  //defining buttons to change color                                               
    }                                              //defining buttons to change color                   
  }
    delay(1000);

    Serial.println(sensors.getTempCByIndex(0)); 
}
