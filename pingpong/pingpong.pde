float restX;
float restY;

float backgroundGrey = 100;

float xSpeed = -5;
float ySpeed = 2;

float score = 0;

void setup() {
  fullScreen();
  background(backgroundGrey);
  restX = width/2;
  restY = height/2;
};

void draw() {
  background(backgroundGrey);
  
  text("Score: " + score, width/2, 50);
  
  if ((restX + xSpeed) < 0) {
    xSpeed = xSpeed * -1;
  };
  if ((restY + ySpeed) < 0 || (restY + ySpeed) > height) {
    ySpeed = ySpeed * -1;
  };
  
  if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50) || (restX + xSpeed) > width - 120) {
      if ((restX + xSpeed) > 100 && (restX + xSpeed) < 120 && (restY + ySpeed) > (mouseY - 50) && (restY + ySpeed) < (mouseY + 50)) score++;
      xSpeed = xSpeed * -1;
      if (sqrt(pow(xSpeed, 2)) < 20) {
        if (xSpeed < 0) xSpeed --;
        if (xSpeed > 0) xSpeed ++;
      };
      if (sqrt(pow(ySpeed, 2)) < 20) {
        if (ySpeed < 0) ySpeed --;
        if (ySpeed > 0) ySpeed ++;
      };
      fill (random(1, 255), random(1, 255), random(1, 255));
  };
  
  restX = restX + xSpeed;
  restY = restY + ySpeed;
  
  
  rect(100, mouseY - 50, 20, 100);
  rect(displayWidth - 100, restY - 50, 20, 100);
  circle(restX, restY, 50);
};
