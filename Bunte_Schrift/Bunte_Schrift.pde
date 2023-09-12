void setup() {
  size(1920, 1080);
  background(0);
  smooth();
}

int size = 60;
String[] fontList = PFont.list();

void draw() {
  delay(50);
  if (mousePressed) {
    textSize(size);
    fill(random(100, 255), random(100, 255), random(100, 255)) ;
    text(int(random(0, 99)), mouseX, mouseY);
    //text(int(random(0, 99)), mouseX + ((width/2)- mouseX)*2, mouseY);
  }
  if (keyPressed) {
    if (key == 'f') {
      int fontnumber = int(random(0, 481));
      textFont(createFont(fontList[fontnumber], 16, true), 60);
    }
    if (key == '+') {
      size = size+5;
    }
    if (key == '-') {
      size = size-5;
    }
  }
}
