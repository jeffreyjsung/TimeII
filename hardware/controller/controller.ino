/*
// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define FINISHED 5
*/
#define END_CHAR ']'
#define POWER_READ 0x33
#define POWER_WRITE 0x53

#include <stdint.h>
#include "motor_setup.h"


/**Defaults the current status to prelaunch **/
int currentStatus = PRELAUNCH;
/**Defaults the flighttime to 0**/
double flightTime = 0;
/**Defaults the status to @ **/
char statuschar = (char) '@';
//--------------------------------------------------------------------------------------
//State Variables.
//--------------------------------------------------------------------------------------
enum STATE {
SLEEP, MISSION, REGULATION
};
enum MISSION_STATES {
  PRELAUNCH, LIFTOFF, MGRAV_BEGIN, MGRAV_END, LANDING, FINISHED
};
STATE volatile controller_state;
MISSION_STATES volatile mission_status;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
// Functions for the serial interface.
//---------------------------------------------------------------------------------------
/*INPUTS: void
	OUTPUTS: bool
	FUNC: Returns True, if serial data is ready to be read, otherwise returns false.
*/
bool is_input() {
  return (Serial.available());
}
//----------------------------------------------------------------------------------------
/**	INPUTS: char
	OUTPUTS: bool
	FUNC: Returns true if the given char is the end character, otherwise returns false. 
**/
bool is_ended(char end_char){
  return (end_char == ']');
}
//-----------------------------------------------------------------------------------------
/**	INPUT: char
	OUTPUT: void
	FUNC: Reads from the serial port until until the parameter begin_char is reached. 
**/
void wait_until_char(char begin_char) {
  while (Serial.read() != begin_char); 
}
//------------------------------------------------------------------------------------------
/**	INPUT: int
	OUTPUT: char
	FUNC: Waits until the serial sends a [, then stores serial input to a 100 byte buffer
	until a ] is reached, effectively creating a string then ends the loop. 
**/
char get_packet(int pos_input) {
  char contents[100];
  //wait until beginning char
  wait_until_char('[');
  for(int i = 0; i < 99; i++){
    contents[i] = char(Serial.read());
    if(is_ended(contents[i])){
      contents[i] = '\0';
      break;
    }
  }
  Serial.println("Serial read complete!");
  //check until past comma tracker and get until next comma flag
  int status_index = 0;
  char contents_buffer[100];
  char statusChar[1];
  char timeChar[10];
  while (contents[index] != ',') {
    while (contents[index] != ',') {
      statusChar[index] = contents[index];
      index += 1;
    }
    timeChar[index] = contents[index];
    index += 1;
  }
  //current contents_buffer contains char for currentStatus
  for(int comma_tracker = 0; comma_tracker <= pos_input; )
}
//-----------------------------------------------------------------------------
int pollStatus() {
  
}
//-----------------------------------------------------------------------------
double experimentTime() {
  
}
//-----------------------------------------------------------------------------
//Sleep Functions
//-----------------------------------------------------------------------------
/*Sets the sleep mode to idle and enables sleep. 
*****TURNS ON SLEEP WHEN WRITTEN!!*****/
void setSleepMode() {
  uint8_t* reg = POWER_WRITE;
  *reg  = 0;
  *reg |= 1;
}
//-----------------------------------------------------------------------------
//Timer Functions
//-----------------------------------------------------------------------------


void timerInterruptHandler() {
    controller_state = REGULATION;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/*Sets the baud rate for the serial port, sets the initial FSM to SLEEP 
and mission state to PRELAUNCH, and also setups the motor.*/
void setup() {
  Serial.begin(115200);
  STATE controller_state = SLEEP;
  MISSION_STATES mission_status = PRELAUNCH;
  float sleep_time_ms = 5000;
  setupMotor(); 
}
//-----------------------------------------------------------------------------




/**Main loop of the arduino**/
void loop() {
  if (!is_input()){
    return;
  }
  Serial.println(get_packet());
  //Serial.println("YOLO"); // printed yolo without input, perhaps because of Serial.begin???

  switch(controller_state) {
    case SLEEP:
      
    break;

    case MISSION:
    break;

    case REGULATION:
    break;

  }



}
