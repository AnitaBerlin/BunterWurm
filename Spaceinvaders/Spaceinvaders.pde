Raumschiff a;
Kanonenkugel b;
float rsx1 = 285;
float rsy1 = 550;
float rsx2 = 300;
float rsy2 = 560;
float rsx3 = 300;
float rsy3 = 520;
float rsx4 = 315;
float rsy4 = 550;


void setup() {
  size(600, 600);
  a = new Raumschiff(rsx1, rsy1, rsx2, rsy2, rsx3, rsy3, rsx4, rsy4);
  b = new Kanonenkugel(rsx3,rsy3,10,30,90,90,90,90);
}

void draw() {
  background(0);
  a.move();
  if (key == 'c') {
    
  }
}
