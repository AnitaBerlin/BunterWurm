class Kanonenkugel {
  float x;
  float y;
  float a;
  float b;
  float tl;
  float tr;
  float bl;
  float br;

  public Kanonenkugel(float xcor, float ycor, float aside, float bside, float tlc, float trc, float blc, float brc) {
    x = xcor;
    y = ycor;
    a = aside;
    b = bside;
    tl = tlc;
    tr=trc;
    bl=blc;
    br=brc;
    rect(xcor, ycor, aside, bside, tlc, trc, blc, brc);
  }

  public void velocity() {
    y--;
  }
}
