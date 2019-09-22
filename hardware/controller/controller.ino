// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define OTHER 5
#define FINISHED 6



int flightStatus = PRELAUNCH;

char value = " ";

void setup() {
  Serial.begin(115200);     // opens serial port, sets baudrate to 115200 bps
  
}

void loop() {



   
}
