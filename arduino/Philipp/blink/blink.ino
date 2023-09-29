
// Setup Pins for output
void setup() {
  
  // First output
  pinMode(2, OUTPUT);

  // Second output
  pinMode(13, OUTPUT);
}

// Loop 
void loop() {

  // Blink first output
  digitalWrite(2, HIGH); // LED on
  delay(100);
  digitalWrite(2, LOW); // LED off
  delay(100);  
  
  // Blink second output
  digitalWrite(13, HIGH); // LED on
  delay(100);
  digitalWrite(13, LOW); // LED off
  delay(100); 
}
