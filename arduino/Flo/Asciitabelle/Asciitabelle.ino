/*
  ASCII table on Display

  This example shows how to show the ASCII table from the expamplestab on a connected Display

  The circuit:
  - Display attached via ports SV, 2, 3 and GRD.

  created 27 September 2023
  by Florian Meyhak
*/

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

int thisByte = 33; //Defines Variable that will run through all the numbers from 33 to 126
int x=0; // Sets the Variable x to 0. x will be the column counter for the cursor

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  lcd.begin(55, 2); // Sets Display-width and -length (55 columns, 2 rows)
  lcd.setBacklight(WHITE); // Sets the background to White
}

void loop() {

  uint8_t buttons = lcd.readButtons();

// If the Display shows the top of the table, the Display wont change even if
// we keep pressing the up Button.
// Also sets the Counter to 33 everytime.
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
//If not on top of the table show the ASCII tablerow of counter-1 in top row of the Display
//and the tablerow of the counter in bottom row of the Display.
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
      thisByte = thisByte +1; //If button down is pushed, count one up
    }
    if (buttons & BUTTON_UP) {
      thisByte = thisByte -1; //If butoon up is pushed, count one down
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
