import processing.serial.*;
Serial myPort;
String value;

int lastTime = 50;
int newTime = 51;

float lastValue = 0;

void setup() {
  fullScreen();
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
  
  line(50, 0, 50, height -50);
  line(50, height-50, width, height-50);
  
  fill(0,0,0);
  textSize(10);
  for(int i = 0 ; i < 46 ; i++){
    text(Integer.toString(i), 10, height- i*28.6 -50);
  }
  for(int i = 0 ; i < 3601; i +=30){
    text(Integer.toString(i), i+50, height-10);
  }
  
  if (lastValue != 0) line(lastTime, height - (lastValue)*30 -20, newTime, height- (parseFloat(value))*30-20);
  
  
  lastTime ++;
  newTime ++;
  
  lastValue = parseFloat(value);
}
