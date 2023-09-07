float backgroundGrey = 100; // Variable für den Hintergrund

float score = 0;

Circle ball = new Circle(0, 0, -5, 2, 50);

void setup() {
  fullScreen();
  background(80, 0, 50);
  
  ball.posX = width/2;
  ball.posY = height/2;
};

void draw() {

  // Hintergrund
  background(80, 0, 50);

  // Punktezahl
  textSize(50);
  text("Punktzahl: " + round(score), width/2 - 100, 50);

  // Dreht den Ball an der linken Wand um
  if ((ball.posX + ball.xSpeed) < 25) {
    ball.xSpeed = ball.xSpeed * -1;
  };

  // Dreht den Ball an der oberen und unteren Wand um
  if ((ball.posY + ball.ySpeed) < 25 || (ball.posY + 25) > height) {
    ball.ySpeed = ball.ySpeed * -1;
  };
  
  // Der Ball trifft eine Plattform
  if ((ball.posX + ball.xSpeed) > 100 && (ball.posX + ball.xSpeed) < 120 && (ball.posY + ball.ySpeed) > (mouseY - 50) && (ball.posY + ball.ySpeed) < (mouseY + 50) || (ball.posX + ball.xSpeed) > width - 120) {
    
    // Der Ball trifft die Spielerplattform
    if ((ball.posX + ball.xSpeed) > 100 && (ball.posX + ball.xSpeed) < 120 && (ball.posY + ball.ySpeed) > (mouseY - 50) && (ball.posY + ball.ySpeed) < (mouseY + 50)) score++;
    
    // Der Ball dreht an der Plattform um
    ball.xSpeed = ball.xSpeed * -1;
    
    // Der Ball erhöht die Geschwindigkeit
    if (sqrt(pow(ball.xSpeed, 2)) < 20) { //der Ball wird schneller wenn er eine Platform trifft
      if (ball.xSpeed < 0) ball.xSpeed --;
      if (ball.xSpeed > 0) ball.xSpeed ++;
    };
    if (sqrt(pow(ball.ySpeed, 2)) < 20) {
      if (ball.ySpeed < 0) ball.ySpeed --;
      if (ball.ySpeed > 0) ball.ySpeed ++;
    };
    
    // Alle Objektfarben ändern sich
    fill (random(1, 255), random(1, 255), random(1, 255));
  };
  
  
  // Der Ball bewegt sich
  ball.posX = ball.posX + ball.xSpeed;
  ball.posY = ball.posY + ball.ySpeed;

  // Die Formen werden gerendert
  rect(100, mouseY - 50, 20, 100);
  rect(width - 100, ball.posY - 50, 20, 100);
  circle(ball.posX, ball.posY, ball.diameter);
};
