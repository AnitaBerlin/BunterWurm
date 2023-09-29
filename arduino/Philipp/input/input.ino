/*
  # Set brightness of LED with keyboard input
  #
  # Author: Philipp Ackermann
  # Date: 29.09.2023
*/

int led = 3;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
int incomingByte = 0; // for incoming serial data

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led, OUTPUT); // declare pin 9 to be an output:
}

// the loop routine runs over and over again forever:
void loop() {

  // read keyboard input
  int input = Serial.read();

  // set brightness of LED to keyboard input
  analogWrite(led, Serial.parseInt());

  // wait
  delay(1000);
}
