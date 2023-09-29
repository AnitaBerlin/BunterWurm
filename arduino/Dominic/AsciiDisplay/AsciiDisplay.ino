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
int move = 0;
double nowTime = 0;


void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2); //Die Zeilen und Reihen werden gesetzt
  lcd.setBacklight(WHITE); //Die Hintergrundsfarbe wird gesetzt
}

uint8_t i = 0;
void loop() {
  uint8_t buttons = lcd.readButtons();//Die Zustände der Knöpfe werden eingelesen

  if (buttons) {//Wenn ein Knopf gedrückt ist
    lcd.setCursor(0, 0);//Der Cursor wird nach 0, 0 gesetzt
    if (buttons & BUTTON_UP) {//Wenn der Knopf gedrückt wird, wird alles "gecleared" und der Zähler (thisByte) wird um eins erhöht
      lcd.clear();
      lcd.print("ASCII Table");
      thisByte++;
      if (thisByte > 126) {//Zum reguliren der Obergrenze
        thisByte = 126;
      }
      move = 0;
    }
    if (buttons & BUTTON_DOWN) {//Wenn der Knopf gedrückt wird, wird alles "gecleared" und der Zähler (thisByte) wird um eins gesenkt
      lcd.clear();
      lcd.print("ASCII Table");
      thisByte--;
      if (thisByte < 33) {//Zum reguliren der Untergrenze
        thisByte = 33;
      }
      move = 0;
    }
    if (buttons & BUTTON_LEFT) {//Der Zähler move um eins gesenkt
      move--;
      lcd.clear();
      if (move < 0) {//Zum reguliren der Untergrenze
        move = 0;
      }
    }
    if (buttons & BUTTON_RIGHT) {//Der Zähler move um eins erhöht
      move++;
      lcd.clear();
      if (move > 3) {//Zum reguliren der Obergrenze
        move = 3;
      }
    }
    lcd.setCursor(0, 0);
    lcd.print("ASCII Table");
    lcd.setCursor(0, 1);
    switch (move) {//Hier wird geguckt welcher zustand gerade ist, also ob man nach rechts oder links gehen will
      case 0:
        lcd.print(char(thisByte));
        lcd.print(", dec: ");
        lcd.print(thisByte);
        break;
      case 1:
        lcd.print(", hex: ");
        lcd.print(thisByte, HEX);
        break;
      case 2:
        lcd.print(", oct: ");
        lcd.print(thisByte, OCT);
        break;
      case 3:
        lcd.print(", bin: ");
        lcd.println(thisByte, BIN);
        break;
    }
  }
}