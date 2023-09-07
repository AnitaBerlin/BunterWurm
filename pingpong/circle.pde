class Circle {

  int posX;
  int posY;
  int xSpeed;
  int ySpeed;
  int diameter;
  int[] tracer;
  boolean lockMove;

  public Circle(

    int posX,
    int posY,
    int xSpeed,
    int ySpeed,
    int diameter

    ) {
    this.posX = posX;
    this.posY = posY;
    this.xSpeed = xSpeed;
    this.ySpeed = ySpeed;
    this.diameter = diameter;
    this.tracer = new int[]{0, 0};
    this.lockMove = false;
  };
};
