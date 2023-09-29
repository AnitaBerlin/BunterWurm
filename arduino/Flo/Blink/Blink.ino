/*
  Blink

  This example shows how to let two LEDs blink seperately

  The circuit:
  - LED attached from digital pin 2 to ground through 220 ohm resistor.

  created 27 September 2023
  by Florian Meyhak
*/

void setup() {
  // initialize digital pin 2 as an output.
  pinMode(2, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH); // turn the extern LED on
  delay(1000); // wait for a second
  digitalWrite(2, LOW); // turn the extern LED off
  digitalWrite(13, HIGH); // turn the intern LED on
  delay(1000); // wait for a second
  digitalWrite(13,LOW); // turn the intern LED off
}