#define ENA PB9
#define IN1 PB8
#define IN2 PB7

int val = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void increasePWM(int change) {
  if(val + change > 255) val = 255;
  else if(val + change < 0) val = 0;
  else val += change;
  analogWrite(ENA, val);
}

void motorMovement(char input) {
  if(input == 'F') {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("IN1=HIGH\tIN2=LOW");
  } else if(input == 'B') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Serial.println("IN1=LOW \tIN2=HIGH");
  } else if(input == 'S') {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    Serial.println("IN1=LOW \tIN2=LOW");
  } else if(input == '+') {
    increasePWM(10);
    Serial.printf("PWM=%i\n",val);
  } else if(input == '-') {
    increasePWM(-10);
    Serial.printf("PWM=%i\n",val);
  }
}

void loop() {
  motorMovement(Serial.read());
}
