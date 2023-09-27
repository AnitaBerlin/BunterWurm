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

void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Clear screen
  lcd.setBacklight(WHITE);
}

// Startsymbol
int symbol = 33;

int firstY = 0;

void printASCII (int firstY) {

  lcd.setCursor(firstY, 0);
  if (symbol == 33) {
    lcd.print("ASCII Table ~ Character Map");
  } else {
    lcd.print(char(symbol - 1));
    lcd.print(", dec: ");
    lcd.print(symbol - 1, DEC);
    lcd.print(", hex: ");
    lcd.print(symbol - 1, HEX);
    lcd.print(", oct: ");
    lcd.print(symbol - 1, OCT);
    lcd.print(", bin: ");
    lcd.print(symbol - 1, BIN);
  };

  lcd.setCursor(firstY, 1);
  lcd.print(char(symbol));
  lcd.print(", dec: ");
  lcd.print(symbol, DEC);
  lcd.print(", hex: ");
  lcd.print(symbol, HEX);
  lcd.print(", oct: ");
  lcd.print(symbol, OCT);
  lcd.print(", bin: ");
  lcd.print(symbol, BIN);
};

uint8_t i=0;
void loop() {

  uint8_t buttons = lcd.readButtons();

  printASCII(firstY);

  if (buttons) {
    lcd.clear();

    if (buttons & BUTTON_UP) {
      if (symbol == 33) return;
      symbol --;
    }
    if (buttons & BUTTON_DOWN) {
      if (symbol == 126) return;
      symbol ++;
    }
    if (buttons & BUTTON_LEFT) {
      if (firstY == 0) return;
      firstY ++;
    }
    if (buttons & BUTTON_RIGHT) {
      firstY --;
    }
    if (buttons & BUTTON_SELECT) {
      firstY = 0;
    }
  }
}
