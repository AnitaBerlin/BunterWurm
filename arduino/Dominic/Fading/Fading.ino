#define PIN1 9

int nowValue = 0;
bool increase = 1;

void setup() {
  pinMode(PIN1, OUTPUT);
  digitalWrite(PIN1, 0);
}

void loop() {
  if(Serial.available() > 1){
    nowValue = Serial.parseInt();
    Serial.println(nowValue);
    analogWrite(PIN1, nowValue);
  }
}

void fade()
{
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
