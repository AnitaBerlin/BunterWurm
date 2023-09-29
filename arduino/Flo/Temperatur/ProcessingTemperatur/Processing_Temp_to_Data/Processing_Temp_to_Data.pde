import processing.serial.*;
PrintWriter output;
Serial myPort;
String value;


void setup() {
  output = createWriter("temp.txt"); 
  String portName=Serial.list()[1];
  myPort =new Serial(this, portName, 9600);
}

void draw() {
  value = myPort.readStringUntil('\n');
  
  
  if(value == null){
    return;
  }
  else{
   println(value); 
  }
  
  output.println(value);
}

void keyPressed() {
  output.flush();
  output.close();
  exit();
}
