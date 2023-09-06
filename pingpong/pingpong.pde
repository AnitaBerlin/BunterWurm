float restX; //X variable für den Ball
float restY; //Y variable für den Ball

float backgroundGrey = 100; //Variable für den Hintergrund

float xSpeed = -5; // x geschwindigkeit
float ySpeed = 2; // y geschwindigkeit

float score = 0;

void setup() {
  fullScreen();
  background(80,0,50);
  restX = width/5;
  restY = height/2;
};

void draw() {
  background(80,0,50); // Setzt Hintergrund farbe
  
  textSize(50); //Setzt Textgröße
  text("Punktzahl: " + round(score), width/2 - 100, 50);
  
  if ((restX + xSpeed) < 25) { // verändert die Geschwindigkeit wenn der Ball die linke Wand trifft
    xSpeed = xSpeed * -1;
  };
  if ((restY + ySpeed) < 25 || (restY + 25) > height) { // verändert die Geschwindigkeit wenn der Ball die obere oder untere Wand trifft
    ySpeed = ySpeed * -1;
  };
  
  if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50) || (restX + xSpeed) > width - 120) { //Schaut ob der Ball eine Platform trifft
      if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50)) score++;
      xSpeed = xSpeed * -1;
      if (sqrt(pow(xSpeed, 2)) < 20) { //der Ball wird schneller wenn er eine Platform trifft
        if (xSpeed < 0) xSpeed --;
        if (xSpeed > 0) xSpeed ++;
      };
      if (sqrt(pow(ySpeed, 2)) < 20) {
        if (ySpeed < 0) ySpeed --;
        if (ySpeed > 0) ySpeed ++;
      };
      fill (random(1, 255), random(1, 255), random(1, 255)); //Verändert die Farbe nach Treffer
  };
  //Bewegt den Ball
  restX = restX + xSpeed;
  restY = restY + ySpeed;
  
//rendert die Formen
  rect(100, mouseY - 50, 20, 100);
  rect(displayWidth - 100, restY - 50, 20, 100);
  circle(restX, restY, 50);
};
