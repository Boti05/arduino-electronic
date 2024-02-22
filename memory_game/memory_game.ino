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
int Led_Array[] = {led1, led2, led3, led4, led5, led6, led7, led8, led9, led_correct, led_incorrect};
//set buttons
int button1 = 21;
int button2 = 20;
int button3 = 18;
int button4 = 16;
int button5 = 14;
int button6 = 7;
int button7 = 5;
int button8 = 3;
int button_Array[] = {button1, button2, button3, button4, button5, button6, button7, button8, button9};
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
    
  }
}

void setup() {
  //set button pins input pullup
  for (byte i = 0; i < 10; i++) {
    pinMode(Button_Array[i], INPUT_PULLUP);
  }

  //set led pins output
  for (byte i = 0; i < 12; i ++) {
    pinMode(Led_Array[i], OUTPUT);
  }

  //make the arduino be abel to print to the serial monitor
  Serial.begin(9600);
}

void loop() {
  tick();

  for (byte i = 0; i < 11; i++) {
    Serial.println(Led_Array[i]);
    delay(1000);
  }
}
