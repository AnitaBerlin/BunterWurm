/*
  Fading

  This example shows how to fade an LED using the analogWrite() function.

  The circuit:
  - LED attached from digital pin 11 to ground through 220 ohm resistor.

  created 27 September 2023
  by Florian Meyhak
*/

int ledPin = 11;  // LED connected to digital pin 11

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