
// Variable für den Hintergrund
int[] background = new int[]{70, 55, 50};

// Punktestand
float score = 0;

// Neuer Ball
Circle ball = new Circle(0, 0, -5, 2, 50);

// Spieler-2 Plattform
int playerTwoY;

void setup() {
  fullScreen();
  background(background[0], background[1], background[2]);

  ball.posX = width/2;
  ball.posY = height/2;

  playerTwoY = height/2;
};

void draw() {

  // Hintergrund
  background(background[0], background[1], background[2]);

  // Punktezahl
  textSize(50);
  text("Punktzahl: " + round(score), width/2 - 100, 50);

  // Spieler Plattformen
  if (keyPressed) {
    if (keyCode == DOWN || key == 's') {
      if (playerTwoY < height) {
        playerTwoY += 20;
      };
    };
    if (keyCode == UP || key == 'w') {
      if (playerTwoY > 0) {
        playerTwoY -= 20;
      };
    };
  };

  if (ball.tracer[0] == 0 && ball.tracer[1] == 0) {

    // Bewegt den Ball
    if (!ball.lockMove) {
      ball.posX += ball.xSpeed;
      ball.posY += ball.ySpeed;
    };

    // Schaut nach Kollisionen mit dem Ball, dreht den Ball um
    for (int i = 0; i < sqrt(pow(ball.xSpeed, 2)); i ++) {

      // Linke Wand
      if (ball.xSpeed < 0 ) {
        if ((ball.posX - i) <= 25) {
          ball.lockMove = true;
          ball.tracer[0] = i+1 * -1;
          ball.xSpeed = ball.xSpeed * -1;
          break;
        };
      };

      // Rechte Wand
      if (ball.xSpeed > 0 ) {
        if ((ball.posX + i) >= (width - 25)) {
          ball.lockMove = true;
          ball.tracer[0] = i-1;
          ball.xSpeed = ball.xSpeed * -1;
          break;
        };
      };
      // Spieler-1 Plattform
      if (ball.xSpeed < 0) {
        if ((ball.posX - i) >= 100 && (ball.posX - i) <= 120) {
          if (mouseY >= (ball.posY - 50) && mouseY <= (ball.posY + 50)) {
            score++;
            ball.lockMove = true;
            ball.tracer[0] = i+1 * -1;
            ball.xSpeed = ball.xSpeed * -1;
            if (sqrt(pow(ball.xSpeed, 2)) < 20) {
              ball.xSpeed++;
            };
            break;
          };
        };
      };
      if (ball.xSpeed > 0) {
        if ((ball.posX + i) <= 120 && (ball.posX + i) >= 100) {
          if (mouseY >= (ball.posY - 50) && mouseY <= (ball.posY + 50)) {
            score++;
            ball.lockMove = true;
            ball.tracer[0] = i-1;
            ball.xSpeed = ball.xSpeed * -1;
            if (sqrt(pow(ball.xSpeed, 2)) < 20) {
              ball.xSpeed--;
            };
            if (sqrt(pow(ball.ySpeed, 2)) < 20) {
              if (ball.ySpeed < 0) {
                ball.ySpeed --;
              };
              if (ball.ySpeed > 0) {
                ball.ySpeed++;
              };
            };
            break;
          };
        };
      };

      // Spieler-2 Plattform
      if (ball.xSpeed > 0) {
        if ((ball.posX + i) <= (width - 100) && (ball.posX + i) >= (width - 120)) {
          if (playerTwoY >= (ball.posY - 50) && playerTwoY <= (ball.posY + 50)) {
            ball.lockMove = true;
            ball.tracer[0] = i-1;
            ball.xSpeed = ball.xSpeed * -1;
            if (sqrt(pow(ball.xSpeed, 2)) < 20) {
              ball.xSpeed--;
            };
            if (sqrt(pow(ball.ySpeed, 2)) < 20) {
              if (ball.ySpeed < 0) {
                ball.ySpeed --;
              };
              if (ball.ySpeed > 0) {
                ball.ySpeed++;
              };
            };
            break;
          };
        };
      };
    };

    for (int i = 0; i < sqrt(pow(ball.ySpeed, 2)); i ++) {

      // Obere Wand
      if (ball.ySpeed < 0 ) {
        if ((ball.posY - i) <= 25) {
          ball.lockMove = true;
          ball.tracer[1] = i * -1;
          ball.ySpeed = ball.ySpeed * -1;
          break;
        };
      };

      // Untere Wand
      if (ball.ySpeed > 0 ) {
        if ((ball.posY + i) >= (height - 25)) {
          ball.lockMove = true;
          ball.tracer[1] = i;
          ball.ySpeed = ball.ySpeed * -1;
          break;
        };
      };
    };
  };

  // Bewegt den Ball mit Tracer
  if (ball.lockMove) {
    ball.posX += ball.tracer[0];
    ball.posY += ball.tracer[1];
    ball.lockMove = false;

    // Tracer zurücksetzen
    ball.tracer[0] = 0;
    ball.tracer[1] = 0;

    // Random Farbe nach Aufprall
    fill(random(0, 255), random(0, 255), random(0, 255));
  };

  // Die Formen werden gerendert
  rect(100, mouseY - 50, 20, 100);
  rect(width - 100, playerTwoY - 50, 20, 100);
  circle(ball.posX, ball.posY, ball.diameter);
};
