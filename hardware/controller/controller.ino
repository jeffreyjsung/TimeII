// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define OTHER 5
#define FINISHED 6

//Pins

#define LED_LIFTOFF 2
#define LED_MG_BEGIN 3
#define LED_MG_END 4

#define SRCLR 12
#define SRCLK 8
#define SER 11
#define RCLK 10

int flightStatus = PRELAUNCH;
int valves[] = {0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(115200);     // opens serial port, sets baudrate to 115200 bps
  pinMode(SRCLR, OUTPUT);
  pinMode(SRCLK, OUTPUT);
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  
}

void loop() {
   
   
  if (Serial.available() >= 1) {
      char inputChar = Serial.read();

        if (inputChar == '@') {
          flightStatus = PRELAUNCH;
           displayLED();
        }
        
        else if (inputChar == 'A') {
          flightStatus = LIFTOFF;
           displayLED();
        }
        
        else if (inputChar == 'D') {
          flightStatus = MGRAV_BEGIN;
           displayLED();
        }
        
        else if (inputChar == 'F') {
          flightStatus = MGRAV_END;
           displayLED();
        }
        
        else if (inputChar == 'H') {
          flightStatus = LANDING;
           displayLED();
        }    

        else if (inputChar == 'J') {
          flightStatus = FINISHED;
           displayLED();
        }    

        else if (isAlpha(inputChar)) {
          flightStatus = OTHER;
          displayLED();
        }
  }

    

}


void displayLED() {

  if (flightStatus == LIFTOFF) {
    valves[3] = 1;
    shift();
  }

  else if (flightStatus == MGRAV_BEGIN) {
    valves[3] = 0;
    valves[5] = 1;
    shift();
  }

  else if (flightStatus == MGRAV_END) {
   // valves = {0,0,0,0,0,0,1,0};
    shift();
  }

  else if (flightStatus == FINISHED) {
 //   valves = {0,0,0,1,0,1,1,0};
    shift();

    delay(500);  
    
   // valves = {0,0,0,0,0,0,0,0};
    shift();
    
    delay(500); 
    
 //   valves = {0,0,0,1,0,1,1,0};
    shift();

   delay(500); 
   
 //   valves = {0,0,0,0,0,0,0,0};
    shift();
  }

  else {
 //   valves = {0,0,0,0,0,0,0,0};
    shift();
  }
}


void shift(){
  digitalWrite(RCLK, LOW);
  for(int i=0; i < sizeof(valves)/2; i++){
    digitalWrite(SRCLR, HIGH);
    digitalWrite(SRCLK, LOW);
    
    if(valves[i] == 1){
      digitalWrite(SER,HIGH);
    }else{
      digitalWrite(SER,LOW);
    }
    
    Serial.println(i);
    digitalWrite(SRCLK, HIGH);
  }
  digitalWrite(RCLK, HIGH);
  return;
}
