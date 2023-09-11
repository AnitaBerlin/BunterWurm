
// Variable für den Hintergrund
int[] background = new int[]{30, 20, 50};

// Neuer Ball
Circle ball = new Circle(0, 0, -5, 2, 50);

// Neue Spieler
Player playerOne = new Player("player", 0, 0, 0);
Player playerTwo = new Player("player", 0, 0, 0);

// Spieler-2 Plattform
int playerTwoY;

// Farben
float color1;
float color2;
float color3;
float newColor1;
float newColor2;
float newColor3;

void setup() {
  fullScreen();
  background(background[0], background[1], background[2]);

  color1 = round(random(0, 255));
  color2 = round(random(0, 255));
  color3 = round(random(0, 255));

  newColor1 = round(random(0, 255));
  newColor2 = round(random(0, 255));
  newColor3 = round(random(0, 255));

  ball.posX = width/2;
  ball.posY = height/2;

  playerTwoY = height/2;
};

void draw() {

  // Farben einstellen
  background(background[0], background[1], background[2]);
    fill(color1, color2, color3, 255);
    strokeWeight(4);
    stroke(255);

  // Punktezahl
  textSize(50);
  text("Punktestand: " + playerOne.score + " - " + playerTwo.score, width/2 - 200, 50);

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
          playerTwo.score ++;
          break;
        };
      };

      // Rechte Wand
      if (ball.xSpeed > 0 ) {
        if ((ball.posX + i) >= (width - 25)) {
          ball.lockMove = true;
          ball.tracer[0] = i-1;
          ball.xSpeed = ball.xSpeed * -1;
          playerOne.score ++;
          break;
        };
      };
      // Spieler-1 Plattform
      if (ball.xSpeed < 0) {
        if ((ball.posX - i) >= 100 && (ball.posX - i) <= 120) {
          if (mouseY >= (ball.posY - 50) && mouseY <= (ball.posY + 50)) {
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
  };

  // Random Farben
  changeColor();
  fill(color1, color2, color3);
  
  // Spieler 1
  rect(100, mouseY - 50, 20, 100);

  // Spieler 2
  rect(width - 100, playerTwoY - 50, 20, 100);

  // Ball
  circle(ball.posX, ball.posY, ball.diameter);
  
  // Keine Umrandung
  noStroke();
  
  // Todeszonen
  fill (150, 20, 20);
  rect(0, 0, 20, height);
  rect(width - 20, 0, 20, height);

  // Glow Effekt
  for (int i = 0; i < 40; i ++) {
    fill(color1, color2, color3, 10 - round(i/2));
    
    // Spieler 1
    rect(100 - i, mouseY - 50 - i, 20 + 2*i, 100 + 2*i);
    
    // Spieler 2
    rect(width - 100 - i, playerTwoY - 50 - i, 20 + 2*i, 100 + 2*i);
    
    // Ball
    circle(ball.posX, ball.posY, ball.diameter + 2*i);
  };
};

void changeColor() {

  if (newColor1 - color1 < 0) color1 --;
  if (newColor1 - color1 > 0) color1 ++;

  if (newColor2 - color2 < 0) color2 --;
  if (newColor2 - color2 > 0) color2 ++;

  if (newColor3 - color3 < 0) color3 --;
  if (newColor3 - color3 > 0) color3 ++;

  if (newColor1 == color1 && newColor2 == color2 && newColor3 == color3) {
    newColor1 = round(random(0, 255));
    newColor2 = round(random(0, 255));
    newColor3 = round(random(0, 255));
  };
};
