import processing.serial.*;

Serial myPort;
String val;
float lastFloat = 0;
int now;
float[] messungen = new float[100];

Table table = new Table();
int saveInTable = 0;
TableRow newRow = table.addRow();
void setup()
{
  size(1000,600);
  String portName = Serial.list()[1];
  myPort = new Serial(this, portName, 9600);
  messungen[0] = 0;
  table.addColumn("Time");
  table.addColumn("Teperature");
  TableRow newRow = table.addRow();
  //newRow.setString(1, "Test1");
  
  //saveTable(table, "data/new.csv");
}

void draw()
{
  background(255);
  drawGraph();
  if(myPort.available() > 0)
  {
    val = myPort.readStringUntil('\n');
  }
  if(val != null)
  {
    if(now == 99)
    {
      swap();
    }
    else
    {
      now++;
    }
    
    messungen[now] = Float.parseFloat(val);
    newRow.setString(0,time);
    newRow.setString(1,val);
    saveTable(table,"data/new.csv");
    println(val);
    drawLines();
    //drawInFirstQuad(map(now -1, 0, 100, 100, 900), map(messungen[now - 1], 0, 100, 50, 500), map(now, 0, 100, 100, 900), map(messungen[now], 0, 100, 50, 500));//messungen[now-1], now, messungen[now]);
    lastFloat = Float.parseFloat(val);
  }
  
  
}

void drawGraph()
{
  line(100, 550, 100, 100); //Y-Achse
  line(50, 500, 900, 500); //X-Achse
  textSize(10);
  text(0 , 50, 950);
  //for(int i = 0; i <50; i = i +10)
  //{
  //  text(i, 0, 100, height - map(i, 0, 100, 50 , 500 ));
  //}
}

void drawInFirstQuad(float x1, float y1, float x2, float y2)
{
   line(x1, height - y1, x2, height - y2); 
}

void swap()
{
  for(int i = 1; i < messungen.length; i++)
  {
    messungen[i - 1] = messungen[i];
  }
}

void drawLines()
{
  for(int i = 1; i < messungen.length; i++)
  {
    
    drawInFirstQuad(map(i -1, 0, 100, 100, 900), map(messungen[i - 1], 0, 100, 50, 500), map(i, 0, 100, 100, 900), map(messungen[i], 0, 100, 50, 500));
    //if(messungen[i] != 0)
    //{
    //  drawInFirstQuad(map(now -1, 0, 100, 100, 900), map(messungen[now - 1], 0, 100, 50, 500), map(now, 0, 100, 100, 900), map(messungen[now], 0, 100, 50, 500));
    //}
    
  }
}
