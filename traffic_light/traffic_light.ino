int led_green = 12;
int led_yellow = 11;
int led_red = 5;
int led_gr = 4;
int led_rd = 3;
int port_check = A0;
int port_led = 7;
int high = 1;
int low = 0;


struct Bl_rules {
  int pin;
  int volt;
};

struct Group_tick {
  int tick;
  Bl_rules rules[4];
};

Group_tick groups[13] = {
  {0, { {led_red, high}, {led_gr, high} }},
  {5, {{led_gr, low}}},
  {6, {{led_gr, high}}},
  {7, {{led_gr, low}}},
  {8, {{led_gr, high}}},
  {9, { {led_gr, low}}},
  {10, {{led_gr, high}}},
  {11, {{led_gr, low}}},
  {12, {{led_gr, high}}},
  {13, {{led_gr, low}, {led_rd, high}, {led_yellow, high}}},
  {17, {{led_red, low}, {led_green, high}, {led_yellow, low}}},
  {31, {{led_yellow, high}, {led_green, low}}},
  {35, {{led_gr, high}, {led_rd, low}, {led_red, high}, {led_yellow, low}}}
};

void traffic_l_handle(int tick) {
  for(Group_tick group : groups) {
    if(group.tick == tick) {
      for(Bl_rules rule : group.rules) {
        digitalWrite(rule.pin, rule.volt);
      }
    }
  }
}

void tick() {
  int tick_count = 0;
  for(int _ = 1; _ <= 36; _ ++) {
    int out = analogRead(port_check);
    int led_val = map(out, 0, 1023, 0, 255);
    Serial.println(led_val);
    Serial.println(out);
    Serial.println();
    analogWrite(port_led, led_val);
    traffic_l_handle(tick_count);
    tick_count ++;
    delay(500);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_gr, OUTPUT);
  pinMode(led_rd, OUTPUT);
  pinMode(port_check, INPUT);
  pinMode(port_led, OUTPUT);
}

void loop() {
  tick();
}
