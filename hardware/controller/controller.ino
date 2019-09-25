// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define FINISHED 5

int flightStatus = PRELAUNCH;
double flightTime = 0;
char leftBound;
bracketEnded = true;

int pollStatus(currentStatus); //reads the next two serial inputs and returns if valid format

void setup() {
  Serial.begin(115200);     // opens serial port, sets baudrate to 115200 bps

}

void loop() {
<<<<<<< HEAD
  while (Serial.available()) {
    if (Serial.available() > 0) {
      currentChar = Serial.read();
      if (currentChar == '[') {
        bracketEnded = false;
        flightStatus = pollStatus(flightStatus);
      } else if (currentChar == ']') {
        bracketEnded = true;
=======
  while (Serial.available()){
    if (Serial.available() > 0){
      leftBound = Serial.read();
      if (leftBound == '['){
        char status = Serial.read();
        char rightBound = Serial.read();
        if (rightBound == ','){
          if (status == 'A'){
            flightStatus = LIFTOFF;
          }
          else if (status == 'D'){
            flightStatus = MGRAV_BEGIN;
          }
          else if (status == 'F'){
            flightStatus = MGRAV_END;
          }
          else if (status == 'H'){
            flightStatus = LANDING;
          }
          else if (status == 'J'){
            flightStatus = FINISHED;
          }
          char mark = Serial.read();
          String time = "";
          while (mark != ',') {
            time += mark;
            mark = Serial.read();
          }
          flightTime = time.toDouble();
        }
>>>>>>> edff02d93aaa2de5c5394668bf8bf85b61a32dfe
      }
    }
  }
}

<<<<<<< HEAD
int pollStatus(currentStatus) {
  char statusChar = Serial.read();
  char rightBound = Serial.read();
  if (rightBound == ',') {
    if (statusChar == 'A') {
      currentStatus = LIFTOFF;
    }
    else if (statusChar == 'D') {
      currentStatus = MGRAV_BEGIN;
    }
    else if (statusChar == 'F') {
      currentStatus = MGRAV_END;
    }
    else if (statusChar == 'H') {
      currentStatus = LANDING;
    }
    else if (statusChar == 'J') {
      currentStatus = FINISHED;
    }
  }
  return currentStatus;
=======

>>>>>>> edff02d93aaa2de5c5394668bf8bf85b61a32dfe
}
