int out = 12;

void blink_slow(int num) {
  Serial.println("mukodik");
  for(int i = 0; i < num; i++) {
    Serial.println(i);
    digitalWrite(out, HIGH);
    delay(1000);
    digitalWrite(out, LOW);
    delay(100);
  }
}


void setup() {
  pinMode(out, OUTPUT);
  Serial.begin(9600);
  blink_slow(10);
}

void loop() {

}
