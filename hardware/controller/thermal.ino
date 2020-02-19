#define FIVE_VOLTS 972.0

//Temp Sensor Pins
const int tempSensorOne = A0; 

float tempOne;


void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A5, OUTPUT);
  
}

bool atTemp(int pin) {
  return (analogRead(A0) >= FIVE_VOLTS / 2.0);
}

void loop() {
  Serial.println(atTemp(A0));
  if (!atTemp(A0)) {
    digitalWrite(A5, HIGH);
  } else {
    digitalWrite(A5, LOW);
  }
}

float readTemp(int pin) {
  return (1.0 / (1.0/298.15 + 1.0/3950.0 * log(1023.0/float(analogRead(pin)) - 1.0)) - 273.15);
}
