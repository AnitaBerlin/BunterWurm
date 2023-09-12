class Raumschiff {
  float x1;
  float y1;
  float x2;
  float y2;
  float x3;
  float y3;
  float x4;
  float y4;


  public Raumschiff(float lu1, float lu2, float mu1, float mu2, float mo1, float mo2, float ru1, float ru2) {
    x1 = lu1;
    y1 = lu2;
    x2 = mu1;
    y2 = mu2;
    x3 = mo1;
    y3 = mo2;
    x4 = ru1;
    y4 = ru2;
    triangle(lu1, lu2, mu1, mu2, mo1, mo2);
    triangle(mu1, mu2, mo1, mo2, ru1, ru2);
  }

  public void move() {
    if (keyPressed) {
      if (key == 'w') {
        y1--;
        y2--;
        y3--;
        y4--;
      }
      if (key == 'a') {
        x1--;
        x2--;
        x3--;
        x4--;
      }
      if (key == 's') {
        y1++;
        y2++;
        y3++;
        y4++;
      }
      if (key == 'd') {
        x1++;
        x2++;
        x3++;
        x4++;
      }
    }
    triangle(x1, y1, x2, y2, x3, y3);
    triangle(x2, y2, x3, y3, x4, y4);
  }

  public void shoot() {
  }

  public void life() {
  }
}
