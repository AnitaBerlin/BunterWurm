/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 9 to ground through 220 ohm resistor.

  created 1 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fading
*/

int ledPin = 11;  // LED connected to digital pin 9

int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();

    analogWrite(ledPin, incomingByte);
  }
  else {
  analogWrite(ledPin, incomingByte);
  }
}

//void loop() {
  // fade in from min to max in increments of 5 points:
  //for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    //analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    //delay(30);
  //}

  // fade out from max to min in increments of 5 points:
  //for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    //analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    //delay(30);
  //}
//}
