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

void setup() {
  Serial.begin(115200);     // opens serial port, sets baudrate to 115200 bps
  
}

void loop() {
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
      }
    }
  }


}
