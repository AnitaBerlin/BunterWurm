/*
  Temperature XY-Graph

  This example shows how to show the measured temperature in a XY-Graph

  created 29 September 2023
  by Florian Meyhak
*/

//import the required librarys
import processing.serial.*;
Serial myPort; //creates new serial that reads the port
String value;//creates String for measured temperatures

int lastTime = 50;//sets "time" which will be counted up to 50 px 
int newTime = 51;

float lastValue = 0;//creates variable to give a startpoint for the individual lines in the graph

void setup() {
  fullScreen();
  String portName=Serial.list()[1]; //defines which port is being used
  myPort =new Serial(this, portName, 9600); //connects myport to portName
}

void draw() {
  value = myPort.readStringUntil('\n'); //gets temperatures as values from the ArduinoIDE
  
  //if there ist no temperature to be given, dont print "null". Instead print nothing and wait for real temperature
  if(value == null){
    return;
  }
  else{
   println(value); 
  }
  
  line(50, 0, 50, height -50); //y-axis of the graph
  line(50, height-50, width, height-50); //x-axis of the graph
  
  fill(0,0,0);
  textSize(10);
  
  //labeling for y-axis
  for(int i = 0 ; i < 46 ; i++){
    text(Integer.toString(i), 10, height- i*28.6 -50);
  }
  
  //labeling for x-axis
  for(int i = 0 ; i < 3601; i +=30){
    text(Integer.toString(i), i+50, height-10);
  }
  
  //prints lines from last value to new value everytime there is a new value
  if (lastValue != 0) line(lastTime, height - (lastValue)*30 -20, newTime, height- (parseFloat(value))*30-20);
  
  //counts up last time and new time so that the lines still work
  lastTime ++;
  newTime ++;
  
  //sets current value to lastValue so that the new line has the right startpoint
  lastValue = parseFloat(value);
}
