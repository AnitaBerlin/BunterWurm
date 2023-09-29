//Author: Florian Fritz Wiede
//Date: 29/09/2023
//Name: Ascii-Tabelle

#include <Wire.h>                                                                 //importing libarys                     
#include <Adafruit_RGBLCDShield.h>                                                //importing libarys                                      
#include <utility/Adafruit_MCP23017.h>                                            //importing libarys                                          

int posx=0;                                                                        // defining variables                                     
int posy=1;                                                                        // defining variables                                     
int thisByte = 33;                                                                 // defining variables                                             
uint8_t i=0;                                                                       // defining variables                                       
int moveRight=0;                                                                   // defining variables                                           
//
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();                                                                                                                     
//
#define RED 0x1                                                                    //defining colors                                                 
#define YELLOW 0x3                                                                 //defining colors                                                     
#define GREEN 0x2                                                                  //defining colors                                                   
#define TEAL 0x6                                                                   //defining colors                                                   
#define BLUE 0x4                                                                   //defining colors                                                   
#define VIOLET 0x5                                                                 //defining colors                                                     
#define WHITE 0x7                                                                  //defining colors                                                   
//
void setup() {                                                                     //                                                 
  // put your setup code here, to run once:                                        //                                                                             
Serial.begin(9600);                                                                // sets Serial to 9600                                                    
 lcd.print("ASCII Table");                                                         // prints Ascii Table onto the screen                                                            
 lcd.begin(55, 2);                                                                 // defines the columns of the screen                                                    
 // lcd.setCursor(posx, posy);                                                     //                                                                 
 // lcd.print(char(33));                                                           //                                                           
 // lcd.print(", dec: ");                                                          //                                                           
 // lcd.print(33);                                                                 //                                                     
 // lcd.print(", hex: ");                                                          //                                                           
 // lcd.print(33, HEX);                                                            //                                                         
 // lcd.print(", oct: ");                                                          //                                                           
 // lcd.print(33, OCT);                                                            //                                                         
 // lcd.print(", bin: ");                                                          //                                                           
 // lcd.println(33, BIN);                                                          //                                                           
}                                                                                  //                                   


void loop() {                                                                                                                   


  uint8_t buttons = lcd.readButtons();                                             //                                                                         
  if (buttons)                                                                     //programming the buttons                                                 
  {                                                                                //                                     
    lcd.clear();                                                                   //clearing                                                   
    lcd.setCursor(0, 0);                                                           //sets the Curser to 0,0                                                           
    if (buttons & BUTTON_UP) {                                                     //defining button up                                                                 
      Serial.println(thisByte);                                                    //printed thisByte onto the screen                                                                 
      thisByte--;                                                                  //thisByte -1                                                   
      Serial.println(thisByte);                                                    //printed new thisByte onto the screen                                                                  
      moveRight = 0;                                                               //sets moveRight to 0                                                       
      if (thisByte < 33) {                                                         //u aren't able to go below 33                                                             
        thisByte = 33;                                                             //                                                         
  }                                                                                //                                     
    }                                                                              //                                       
    if (buttons & BUTTON_DOWN) {                                                   //defining button down                                                                   
      Serial.println(thisByte);                                                    //                                                                 
      thisByte++;                                                                  //thisByte +1                                                    
      Serial.println(thisByte);                                                    //                                                                 
      moveRight = 0;                                                               //                                                       
      if (thisByte > 126) {                                                        //u aren't able to go above 126                                                             
        thisByte = 126;                                                            //                                                         
  }                                                                                //                                     
    }                                                                              //                                       
    if (buttons & BUTTON_LEFT) {                                                   //defining button left                                                                   
      moveRight--;                                                                 //puts moveRigt -1                                                     
      if (moveRight < 0){moveRight=0;}                                             //aren't allowed to go below the 0 case                                                                         
    }                                                                              //                                       
    if (buttons & BUTTON_RIGHT) {                                                  //defining btton right                                                                   
      moveRight++;                                                                 //puts moveRight +1                                                     
      if (moveRight > 3){moveRight=3;}                                             //aren#t allowed to go above the 3 case                                                                         
//
    }                                                                              //                                       
  }                                                                                //                                     
  lcd.setCursor(0, 0);                                                             //                                                         
  lcd.print("Ascii Tabelle");                                                      //                                                               
  lcd.setCursor(0, 1);                                                             //                                                         
  switch(moveRight){                                                               //defining moveRight function                                                       
    case 0:                                                                        //cases and what they are ment to do                                             
      lcd.print(char(thisByte));                                                   //based on the size of the screen                                                                   
      lcd.print(", dec: ");                                                        //                                                             
      lcd.print(thisByte);                                                         //                                                             
      break;                                                                       //                                               
    case 1:                                                                        //                                             
      lcd.print(", hex: ");                                                        //                                                             
      lcd.print(thisByte, HEX);                                                    //                                                                 
      break;                                                                       //                                               
    case 2:                                                                        //                                             
      lcd.print(", oct: ");                                                        //                                                             
      lcd.print(thisByte, OCT);                                                    //                                                                 
      break;                                                                       //                                               
    case 3:                                                                        //                                             
      lcd.print(", bin: ");                                                        //                                                             
      lcd.println(thisByte, BIN);                                                  //                                                                   
      break;                                                                       //                                               
  }                                                                                //                                     
}                                                                                  //                                   
