/*
  # Program to let an LED fade
  #
  # Author: Philipp Ackermann
  # Date: 29.09.2023
*/

// Pin for output
int led = 3;

// Brightness for ouput
int brightness = 0;

// Value for changing brightness
int fadeAmount = 5;


void setup() {

  // Declare pin as output
  pinMode(led, OUTPUT);
}


void loop() {

  // Set brightess of pin
  analogWrite(led, brightness);

  // Change brightness with fadeAmount
  brightness = brightness + fadeAmount;

  // Change brightness with fadeAmount
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // wait
  delay(30);
}
