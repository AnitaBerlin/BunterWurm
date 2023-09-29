/*
  # ASCII Tabelle für Arduino Display
  #
  # Author: Philipp Ackermann
  # Datum: 29.09.2023
*/

// Import Adafruit library
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>


// Define lcd class
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

// Define colors to change display color
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

  // Number of columns and rows of lcd screen
  lcd.begin(16, 2);

  // Clear screen
  lcd.setBacklight(WHITE);
}

// First symbol as decimal
int symbol = 33;

// Set the starting position for the cursor
int firstCursorPos = 0;


// Loop function
void loop() {

  // Set cursor to top row
  lcd.setCursor(firstY, 0);

  // Print ASCII Title or Symbol infos
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

  // Set cursor to bottom row
  lcd.setCursor(firstY, 1);

  // Print infos of next Symbol
  lcd.print(char(symbol));
  lcd.print(", dec: ");
  lcd.print(symbol, DEC);
  lcd.print(", hex: ");
  lcd.print(symbol, HEX);
  lcd.print(", oct: ");
  lcd.print(symbol, OCT);
  lcd.print(", bin: ");
  lcd.print(symbol, BIN);


  // Button input used for navigation

  // Read buttons
  uint8_t buttons = lcd.readButtons();

  // Navigate
  if (buttons) {

    // Clear Screen
    lcd.clear();

    // Navigate up
    if (buttons & BUTTON_UP) {
      if (symbol == 33) return;
      symbol --;
    }

    // Navigate down
    if (buttons & BUTTON_DOWN) {
      if (symbol == 126) return;
      symbol ++;
    }

    // Navigate left
    if (buttons & BUTTON_LEFT) {
      if (firstY == 0) return;
      firstY ++;
    }

    // Navigate right
    if (buttons & BUTTON_RIGHT) {
      firstY --;
    }

    // Reset horizontal navigation to start
    if (buttons & BUTTON_SELECT) {
      firstY = 0;
    }
  }
}
