import processing.serial.*;

Serial myPort;
String val;

int lastTime = 50;
int newTime = 51;

float lastVal = 0;

void setup()
{
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  
  fullScreen();
}

void draw() {
  val = myPort.readStringUntil('\n');
  
  if (val == null) {
    return;
  } else println(val);
  
  line(50, 0, 50, height - 50);
  line(50, height - 50, width, height - 50);
  
  fill(0, 0, 0);
  textSize(20);
  for (int i = 21; i < 36; i ++) text(Integer.toString(i), 10, height - (i-20)*50);
  for (int i = 0; i < 120; i += 6) text(Integer.toString(i*10), 50+i*50, height - 10);
  
  if (lastVal != 0) line(lastTime, height - (lastVal-20)*50, newTime, height - (parseFloat(val)-20)*50);
  
  lastTime ++;
  newTime ++;
  
  lastVal = parseFloat(val);
}
