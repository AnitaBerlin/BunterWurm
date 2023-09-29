#define PIN1 9

int nowValue = 0;
bool increase = 1;

void setup() {
  pinMode(PIN1, OUTPUT);
  digitalWrite(PIN1, 0); //Die LED wird zu Beginn einmal ausgeschaltet
}

void loop() {
  if(Serial.available() > 0){
    nowValue = Serial.parseInt(); //List den eingegebenen Wert aus
    Serial.println(nowValue); //Hier wird dieser Wert einmal ausgegeben zum debuggen
    analogWrite(PIN1, nowValue); //Der Wert wird als output genutzt um die Heligkeit der LED zu verändern
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
