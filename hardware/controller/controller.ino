// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define FINISHED 5

int currentStatus = PRELAUNCH;
double flightTime = 0;
char leftBound;

int pollStatus() {
  int flightStatus = currentStatus;
  char statusChar = Serial.read();
  char rightBound = Serial.read();
  if (rightBound == ',') {
    if (statusChar == 'A') {
      flightStatus = LIFTOFF;
    }
    else if (statusChar == 'D') {
      flightStatus = MGRAV_BEGIN;
    }
    else if (statusChar == 'F') {
      flightStatus = MGRAV_END;
    }
    else if (statusChar == 'H') {
      flightStatus = LANDING;
    }
    else if (statusChar == 'J') {
      flightStatus = FINISHED;
    }
  }
  return flightStatus;
}

double experimentTime() {
  char mark = Serial.read();
  String time = "";
  while (mark != ',') {
    time += mark;
    mark = Serial.read();
  }
  return time.toDouble();
}

void setup() {
  Serial.begin(115200);     // opens serial port, sets baudrate to 115200 bps

}

void loop() {
  while (Serial.available()) {
    if (Serial.available() > 0) {
      char currentChar = Serial.read();
      if (currentChar == '[') {
        currentStatus = pollStatus();
        flightTime = experimentTime();
      }
    }
  }
}



