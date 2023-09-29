//Author: Florian Fritz Wiede
//Date: 29/09/2023
//Name: Blink

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(4, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(4, LOW);   // turn the LED off by making the voltage LOW
  //delay(1000);                     // wait for a second
  digitalWrite(13, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(13, LOW);   // turn the LED off by making the voltage LOW
  //delay(500);                     // wait for a second
}
