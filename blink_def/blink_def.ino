int num = 0;

void blink(int num) {
  int count = 1;
  for( ; ; ) {
    if(count == num) {
      Serial.println("END");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
    }
    else {
      Serial.println("ON GOING");
      digitalWrite(LED_BUILTIN, HIGH);
      delay(150);
      digitalWrite(LED_BUILTIN, LOW);
      count++;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  blink(5);
}
