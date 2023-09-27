/*********************

Example code for the Adafruit RGB Character LCD Shield and Library

This code displays text on the shield, and also reads the buttons on the keypad.
When a button is pressed, the backlight changes color.

**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

int thisByte = 33;
int curs = 0;
int x=0;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(55, 2);
  lcd.setBacklight(WHITE);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  uint8_t buttons = lcd.readButtons();

if (thisByte <= 32) {
  lcd.setCursor(x, 0);
  lcd.print("ASCII Table - Character Map");
  lcd.setCursor(x, 0);
  lcd.setCursor(x, 1);
  lcd.print(char(thisByte+1));
  lcd.print(",dec:");
  lcd.print(thisByte+1, DEC);
  lcd.print(",hex:");
  lcd.print(thisByte+1, HEX);
  lcd.print(",oct:");
  lcd.print(thisByte+1, OCT);
  lcd.print(",bin:");
  lcd.print(thisByte+1, BIN);
  thisByte = 33;
}
else {
  lcd.setCursor(x, 0);
  if (thisByte == 33) {
  lcd.print("ASCII Table - Character Map");
  }
  else {
  lcd.print(char(thisByte-1));
  lcd.print(",dec:");
  lcd.print(thisByte-1, DEC);
  lcd.print(",hex:");
  lcd.print(thisByte-1, HEX);
  lcd.print(",oct:");
  lcd.print(thisByte-1, OCT);
  lcd.print(",bin:");
  lcd.print(thisByte-1, BIN);
  }

  lcd.setCursor(x, 1);
  lcd.print(char(thisByte));
  lcd.print(",dec:");
  lcd.print(thisByte, DEC);
  lcd.print(",hex:");
  lcd.print(thisByte, HEX);
  lcd.print(",oct:");
  lcd.print(thisByte, OCT);
  lcd.print(",bin:");
  lcd.print(thisByte, BIN);
}
  
  
  if (buttons) {
    lcd.clear();
    
    if (buttons & BUTTON_DOWN) {
      thisByte = thisByte +1;
    }
    if (buttons & BUTTON_UP) {
      thisByte = thisByte -1;
    }
    if (buttons & BUTTON_LEFT) {
      x++;
    }
    if (buttons & BUTTON_RIGHT) {
      x--;
    }
    if (buttons & BUTTON_SELECT) {
    }
  }

}
