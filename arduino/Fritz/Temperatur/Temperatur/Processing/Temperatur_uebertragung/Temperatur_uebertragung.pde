import processing.serial.*;

Serial myPort;            //
String val;               //

static float sensorVal = 0;  //
int sek = 50;                //
int newsek = 51;            //
float lastVal=0;            //

void setup()
{
  size(600,600);          //
  background(255);         //
  String portName = Serial.list()[1]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);  //
}


void draw() {
  val = myPort.readStringUntil('\n');    //

  if (val == null) {                    //
    return;
  } else println(val);

  line(50, 0, 50, height - 50);                    //
  line(50, height - 50, width, height - 50);

  fill(0, 0, 0);            //
  textSize(10);
  for (int i = 21; i < 36; i ++) text(Integer.toString(i), 10, height - (i-20)*50);
  for (int i = 0; i < 120; i += 6) text(Integer.toString(i*10), 50+i*8, height - 20);

  if (lastVal != 0) line(sek, height - (lastVal-20)*50, newsek, height - (parseFloat(val)-20)*50);

  sek ++;
  newsek ++;

  lastVal = parseFloat(val);
}
