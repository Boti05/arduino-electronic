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
int button9 = 2;
int Button_Array[] = {button1, button2, button3, button4, button5, button6, button7, button8, button9};
//set the useful variables
bool pressed = false;
bool not_pressed = true;

//make function for lighting with buttons
void light_button(int button, int led) {
  while (digitalRead(button) == pressed) {
    digitalWrite(led, HIGH);
  }
  while (digitalRead(button) == not_pressed) {
    digitalWrite(led, LOW);
  }
}

//making a function for knowing which button was pressed and with it starting the game if it was't
int startin_process() {
  int start = 0;
  for (byte i = 0; i < 11; i++) {
    if (digitalRead(Button_Array[i]) == pressed) {
      return start = 1;
    }
  }
}

//making the "led game" before starting the actual game
void before_start(int start) {
  int led_num = 0;
  while (start == 0) {
    for (byte i = 0; i < 11; i++) {
      digitalWrite(Led_Array[i], HIGH);
      delay(50);
      digitalWrite(Led_Array[i+1], HIGH);
      digitalWrite(Led_Array[i], LOW);
      delay(50);
    }
    for (byte j = 11; j > 2 ; j--) {
      digitalWrite(Led_Array[j], LOW);
      digitalWrite(Led_Array[j-2], HIGH);
      delay(50);
      digitalWrite(Led_Array[j-2], LOW);
      digitalWrite(Led_Array[j-3], HIGH);
      delay(50);
    }
  }
  // do while ha az érték 1, a végén 2 lesz hogy csak egyszer fusson le és a másik ne fusson
    digitalWrite(Led_Array[-1], LOW);
    digitalWrite(Led_Array[-2], LOW);
    for (byte k = 0; k = 3; k++) {
      for (byte l = 0; l < 9; l++) {
        digitalWrite(Led_Array[l], LOW);
      }
      delay(100);
      for (byte b = 0; b < 9; b++) {
        digitalWrite(Led_Array[b], HIGH);
      }
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


  before_start(startin_process());

  for (byte i = 0; i < 11; i++) {
    Serial.println(Led_Array[i]);
    delay(1000);
  }
}
