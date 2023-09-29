import processing.serial.*;
Serial myPort;
String value;

void setup() {
  size(380,200);
  background(255);
  stroke(160);
  fill(50);
  String portName=Serial.list()[1];
  println(portName);
  myPort =new Serial(this, portName, 9600);
}

void draw() {
  background(255);
  value = myPort.readStringUntil('\n');
  
  if(value == null){
    return;
  }
  else{
   println(value); 
  }
}
