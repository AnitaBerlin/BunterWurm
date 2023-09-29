#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

int posx=0;
int posy=1;
int thisByte = 33;
uint8_t i=0;
int moveRight=0;

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
 lcd.print("ASCII Table");
 lcd.begin(55, 2);
 // lcd.setCursor(posx, posy);
 // lcd.print(char(33));
 // lcd.print(", dec: ");
 // lcd.print(33);
 // lcd.print(", hex: ");
 // lcd.print(33, HEX);
 // lcd.print(", oct: ");
 // lcd.print(33, OCT);
 // lcd.print(", bin: ");
 // lcd.println(33, BIN);
}



void loop() {
  uint8_t buttons = lcd.readButtons();
  if (buttons) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    if (buttons & BUTTON_UP) {
      Serial.println(thisByte);
      thisByte--;
      Serial.println(thisByte);
      moveRight = 0;
    }
    if (buttons & BUTTON_DOWN) {
      Serial.println(thisByte);
      thisByte++;
      Serial.println(thisByte);
      moveRight = 0;
    }
    if (buttons & BUTTON_LEFT) {
      moveRight--;
      if (moveRight < 0){moveRight=0;}
    }
    if (buttons & BUTTON_RIGHT) {
      moveRight++;
      if (moveRight > 3){moveRight=3;}
    
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("Ascii Tabelle");
  lcd.setCursor(0, 1);
  switch(moveRight){
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



