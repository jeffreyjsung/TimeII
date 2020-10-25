/*  MP6500 Motor Driver
 *  Adjust to fit servo
*/
#ifndef MOTOR_SETUP 
#define MOTOR_SETUP 

//Motor driver pins - assign later
const int STEP; //step input
const int DIR; //direction input
const int nSLEEP; //sleep mode input

/*Sets the appropiate pins.*/
void setupMotor();

/*activates the motors.*/
void activateMotor();

#endif