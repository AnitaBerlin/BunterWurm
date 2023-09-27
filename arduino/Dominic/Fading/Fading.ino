#define PIN1 9

int nowValue = 0;
bool increase = 1;

void setup() {
  pinMode(PIN1, OUTPUT);

}

void loop() {
  analogWrite(PIN1, nowValue);
  if(nowValue <= 0)
  {
    increase = 1;
  }
  else if (nowValue >=255) {
    increase = 0;
  }
  if (increase == 1) {
    nowValue++;
  }
  else {
    nowValue--;
  }
  delay(10);
  Serial.println(nowValue);

}
