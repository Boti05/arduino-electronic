//set the pins and variables
int proba = 12;
int button_pin = 21;
bool pressed = false;
bool not_pressed = true;
int sum = 0;


void setup() {
    pinMode(proba, OUTPUT);
    pinMode(button_pin, INPUT_PULLUP); //button_pin will be INPUT_PULLUP
    Serial.begin(9600);
    
  }

void loop() {
    bool currentState = digitalRead(button_pin);
    //if button pressed it will say Hello
    if (digitalRead(button_pin) == pressed) {
      Serial.println("Hello");
      sum ++;
      Serial.println(sum);
      delay(150);
    }
    //while button pressed led will light up and stop saying Hello
    while (digitalRead(button_pin) == pressed) {
        digitalWrite(proba, HIGH);
      }
    //while not pressed it won't light up
    while (digitalRead(button_pin) == not_pressed) {
        digitalWrite(proba, LOW);
      }
}

