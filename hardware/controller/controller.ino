// Flight status
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define FINISHED 5

#define END_CHAR ']'
/**Defaults the current status to prelaunch **/
int currentStatus = PRELAUNCH;
/**Defaults the flighttime to 0**/
double flightTime = 0;
/**Defaults the status to @ **/
char statuschar = "@";
//---------------------------------------------------------------------------------------
/**	INPUTS: void
	OUTPUTS: bool
	FUNC: Returns True, if serial data is ready to be read, otherwise returns false.
**/
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
  
  
  for(comma_tracker = 0; comma_tracker <= pos_input; )
}
//-----------------------------------------------------------------------------
int pollStatus() {
  
}
//-----------------------------------------------------------------------------
double experimentTime() {
  
}
//-----------------------------------------------------------------------------
/**	INPUT: void
	OUTPUT: void
	FUNC: Sets the baud rate in the serial port to 115200.
**/
void setup() {
  Serial.begin(115200);
}
//-----------------------------------------------------------------------------
/**Main loop of the arduino**/
void loop() {
  if (!is_input()){
    return;
  }
  Serial.println(get_packet());
  //Serial.println("YOLO"); // printed yolo without input, perhaps because of Serial.begin???
}
