float restX; // X-Koordinate für Ball und Gegnerplattform
float restY; // Y-Koordinate für Ball und Gegnerplattform

float backgroundGrey = 100; // Variable für den Hintergrund

float xSpeed = -5; // Geschwindigkeit vom Ball für die X-Koordinate
float ySpeed = 2; // Geschwindigkeit vom Ball für die Y-Koordinate

float score = 0;

void setup() {
  fullScreen();
  background(80, 0, 50);
  
  restX = width/2;
  restY = height/2;
};

void draw() {

  // Hintergrund
  background(80, 0, 50);

  // Punktezahl
  textSize(50);
  text("Punktzahl: " + round(score), width/2 - 100, 50);

  // Dreht den Ball an der linken Wand um
  if ((restX + xSpeed) < 25) {
    xSpeed = xSpeed * -1;
  };

  // Dreht den Ball an der oberen und unteren Wand um
  if ((restY + ySpeed) < 25 || (restY + 25) > height) {
    ySpeed = ySpeed * -1;
  };
  
  // Der Ball trifft eine Plattform
  if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50) || (restX + xSpeed) > width - 120) { //Schaut ob der Ball eine Platform trifft
    
    // Der Ball trifft die Spielerplattform
    if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50)) score++;
    
    // Der Ball dreht an der Plattform um
    xSpeed = xSpeed * -1;
    
    // Der Ball erhöht die Geschwindigkeit
    if (sqrt(pow(xSpeed, 2)) < 20) { //der Ball wird schneller wenn er eine Platform trifft
      if (xSpeed < 0) xSpeed --;
      if (xSpeed > 0) xSpeed ++;
    };
    if (sqrt(pow(ySpeed, 2)) < 20) {
      if (ySpeed < 0) ySpeed --;
      if (ySpeed > 0) ySpeed ++;
    };
    
    // Alle Objektfarben ändern sich
    fill (random(1, 255), random(1, 255), random(1, 255));
  };
  
  
  // Der Ball bewegt sich
  restX = restX + xSpeed;
  restY = restY + ySpeed;

  // Die Formen werden gerendert
  rect(100, mouseY - 50, 20, 100);
  rect(width - 100, restY - 50, 20, 100);
  
  circle(restX, restY, 50);
};
