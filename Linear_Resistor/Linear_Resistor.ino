#define LINEAR_RES PA7

int mm, val;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial);
  analogReadResolution(12);
  pinMode(PC13, OUTPUT);
  pinMode(LINEAR_RES, INPUT);
  pinMode(PB3, OUTPUT);
}

int valueRead() {
  int mean_value = 0;
  
  for(int i=0; i<5000; ++i) {
    mean_value += analogRead(LINEAR_RES);
    delayMicroseconds(100);
  }

  return mean_value / 5000;
}

double getPosition(int x) {
  return (x-3837)/2.7379;
}
 
void loop() {
  /*analogReadResolution(12);
  digitalWrite(PC13, HIGH);
  Serial.println(F("HIGH!"));
  Serial.printf("LINEAR_RES analog = %i\n", analogRead(LINEAR_RES));
  delay(1000);
  
  digitalWrite(PC13, LOW);
  Serial.println(F("LOW!"));

  for(int i=0; i<255; i+=10) {
    analogWrite(PB3, i);
    Serial.printf("LINEAR_RES analog = %i\n", analogRead(LINEAR_RES));
    delay(900);
  }
  analogWrite(PB3, 0);*/
  int input = Serial.read();
  if(input == 'A') {
    mm++;
    val = valueRead();
    Serial.printf("%i\t%i\n", mm, val);
  } else if(input == 'B') {
    mm--;
    val = valueRead();
    Serial.printf("%i\t%i\n", mm, val);
  } else if(input == 'C') {
    Serial.println();
  } else if(input == 'D') {
    Serial.println(valueRead());
  } else if(input == 'X') {
    Serial.println(getPosition(valueRead()));
  }
  input = 0;
} 
