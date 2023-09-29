/*
  Temperature txt file tablet foramt

  This example shows how to show the measured temperature in a table in a txt file

  created 29 September 2023
  by Florian Meyhak
*/

//import the required librarys
import processing.serial.*;

PrintWriter output;//sets up the file commands
Serial myPort;//creates new serial that reads the port
String value;//creates String for measured temperatures


void setup() {
  output = createWriter("temptable.txt"); //creates the txt file for the temperatures
  String portName=Serial.list()[1];//defines which port is being used
  myPort =new Serial(this, portName, 9600);//connects myport to portName
  output.println("Zeit:                             Wert:"); //creates first row of table
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
  
  //prints all other rows. first the date and then the values
  output.print(new java.util.Date()); 
  output.print("     ");
  output.print(value);
  
}


//if any key ist pressed...
void keyPressed() {
  output.flush();//put the remaining data into the txt file
  output.close();//save and close the txt file
  exit();//close the processing tab
}
