//set the led pins
int led1 = 22;
int led2 = 24;
int led3 = 28;
int led4 = 32;
int led5 = 36;
int led6 = 40;
int led7 = 44;
int led8 = 48;
int led9 = 52;
int led_correct = 12;
int led_incorrect = 13;

//set buttons
int button1 = 21;
int button2 = 20;
int button3 = 18;
int button4 = 16;
int button5 = 14;
int button6 = 7;
int button7 = 5;
int button8 = 3;
int button9 = 2;

//set the useful variables
bool pressed = false;
bool not_pressed = true;

//make function for lighting with buttons

void light_button(int button, int led) {
  while (digitalRead(button) == false) {
    digitalWrite(led, HIGH);
  }
  while (digitalRead(button) == true) {
    digitalWrite(led, LOW);
  }
}

void tick() {
  int tick_count = 0;
  for (int i = 1; i == 2; i++) {
    switch (i) {
      case 1:
        light_button(button1, led1);
        light_button(button2, led2);
        light_button(button3, led3);
        light_button(button4, led4);
        light_button(button5, led5);
        light_button(button6, led6);
        light_button(button7, led7);
        light_button(button8, led8);
        light_button(button9, led9);
      case 2:
        light_button(button1, led1);
        light_button(button2, led2);
        light_button(button3, led3);
        light_button(button4, led4);
        light_button(button5, led5);
        light_button(button6, led6);
        light_button(button7, led7);
        light_button(button8, led8);
        light_button(button9, led9);
    }
  }
}


void setup() {
  //set button pins input
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  //set led pins output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led_correct, OUTPUT);
  pinMode(led_incorrect, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*
  while (digitalRead(button9) == pressed) {
    digitalWrite(led9, HIGH);
  }
  while (digitalRead(button9) == not_pressed) {
    digitalWrite(led9, LOW);
  }
  
  light_button(button1, led1);
  light_button(button2, led2);
  light_button(button3, led3);
  light_button(button4, led4);
  light_button(button5, led5);
  light_button(button6, led6);
  light_button(button7, led7);
  light_button(button8, led8);
  light_button(button9, led9);
  */
  tick();
}
