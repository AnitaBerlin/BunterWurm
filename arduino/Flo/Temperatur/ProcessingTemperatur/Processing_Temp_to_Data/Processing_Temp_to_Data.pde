/*
  Temperature text file

  This example shows how to show the measured temperature in a text file

  created 29 September 2023
  by Florian Meyhak
*/

//import the required librarys
import processing.serial.*;
PrintWriter output;//sets up the file commands
Serial myPort;//creates new serial that reads the port
String value;//creates String for measured temperatures


void setup() {
  output = createWriter("temp.txt"); //creates the txt file for the temperatures
  String portName=Serial.list()[1];//defines which port is being used
  myPort =new Serial(this, portName, 9600);//connects myport to portName
}

void draw() {
  value = myPort.readStringUntil('\n');//gets temperatures as values from the ArduinoIDE
  
   //if there ist no temperature to be given, dont print "null". Instead print nothing and wait for real temperature
  if(value == null){
    return;
  }
  else{
   println(value); 
  }
  
  output.println(value);//if there is a temperature value print it into the txt file
}

//if any key ist pressed...
void keyPressed() {
  output.flush();//put the remaining data into the txt file
  output.close();//save and close the txt file
  exit();//close the processing tab
}
