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
int moveRight = 0;
double nowTime = 0;


void setup() {
  // Debugging output
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.setBacklight(WHITE);
}

uint8_t i=0;
void loop() {
  lcd.setCursor(0, 0);
  uint8_t buttons = lcd.readButtons();
  //if(millis()-200 >= nowTime)
  //{
  //  lcd.clear();
  //  nowTime = millis();
  //}
  lcd.print("ASCII Table");
  lcd.setCursor(0, 1);


  if (buttons) {
    //lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.clear();
      lcd.print("ASCII Table");
      lcd.setCursor(0,1);
      thisByte++;
      if(thisByte > 126)
      {
        thisByte = 126;
      }
      Serial.println(thisByte);
      lcd.print(char(thisByte));
      lcd.print(", dec: ");
      lcd.print(thisByte);
      moveRight = 0;
      //lcd.print(", hex: ");
      //lcd.print(thisByte, HEX);
      //lcd.print(", oct: ");
      //lcd.print(thisByte, OCT);
      //lcd.print(", bin: ");
      //lcd.println(thisByte, BIN);
    }
    if (buttons & BUTTON_DOWN) {
      lcd.clear();
      lcd.print("ASCII Table");
      lcd.setCursor(0,1);
      thisByte--;
      if(thisByte < 33)
      {
        thisByte = 33;
      }
      Serial.println(thisByte);
      lcd.print(char(thisByte));
      lcd.print(", dec: ");
      lcd.print(thisByte);
      moveRight = 0;
      //lcd.print(", hex: ");
      //lcd.print(thisByte, HEX);
      //lcd.print(", oct: ");
      //lcd.print(thisByte, OCT);
      //lcd.print(", bin: ");
      //lcd.println(thisByte, BIN);
    }
    if (buttons & BUTTON_LEFT) {
      moveRight--;
      lcd.clear();
      lcd.setCursor(0,1);

      if(moveRight < 0)
      {
        moveRight = 0;
      }

      switch(moveRight)
      {
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
    if (buttons & BUTTON_RIGHT) {
      moveRight++;
      lcd.clear();
      lcd.setCursor(0,1);

      if(moveRight > 3)
      {
        moveRight = 3;
      }

      switch(moveRight)
      {
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
}


//void createAsciiTable()
//{
//  for(int i = 33; i < 126; i++)
//  {
//    asciiTable[i] = {String(byte(thisByte))};// + ", dec: " + thisByte};
//    Serial.println(asciiTable[i]);
//  }
  
  //Serial.write(thisByte);
  //Serial.print(", dec: ");
  //Serial.print(thisByte);
  //Serial.print(", hex: ");
  //Serial.print(thisByte, HEX);
  //Serial.print(", oct: ");
  //Serial.print(thisByte, OCT);
  //Serial.print(", bin: ");
  //Serial.println(thisByte, BIN);
  //if (thisByte == 126) {
  //  while (true) {
  //    continue;
  //  }
  //}
  //thisByte++;
//}