/*
  # Create graph and save data to tempLog.txt from measured temp
  # 
  # Author: Philipp Ackermann
  # Date: 29.09.2023
*/

// Import serial
import processing.serial.*;

// Create printwriter to write in txt log
PrintWriter output;

// serial to read port
Serial myPort;

// value from port
String val;

// time variable with offset for graph boundaries
int lastTime = 50;
int newTime = 51;

// save last val to create line
float lastVal = 0;

void setup()
{
  // define which port is being used
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  // write header into log txt
  output = createWriter("tempLog.txt");
  output.println("Zeitstempel:                     Temperatur:");
  
  // set fullscreen for graph
  fullScreen();
}

void draw() {
  
  // read port
  val = myPort.readStringUntil('\n');
  
  // check if port has value
  if (val == null) {
    return;
  } else println(val);
  
  // draw graph border
  fill(0, 0, 0);
  line(50, 0, 50, height - 50);
  line(50, height - 50, width, height - 50);
  
  // set label for graph
  textSize(20);
  for (int i = 21; i < 36; i ++) text(Integer.toString(i), 10, height - (i-20)*50);
  for (int i = 0; i < 120; i += 6) text(Integer.toString(i*10), 50+i*50, height - 10);
  
  // draw value lines
  if (lastVal != 0) line(lastTime, height - (lastVal-20)*50, newTime, height - (parseFloat(val)-20)*50);
  
  // save data to file
  output.print(new java.util.Date());
  output.print("    ");
  output.print(val);
  
  // update time variable
  lastTime ++;
  newTime ++;
  
  // update lastval variable
  lastVal = parseFloat(val);
  
  // save new data to log
  output.flush();
}
