#include <Servo.h> 

int servoPin = 10; 
Servo Servo1; 

int findDist(float distance, float circumference) {
  return distance / circumference * 360.0;
}

void setup() {
   Servo1.attach(servoPin);
}

void loop(){
   // Make servo go to 0 degrees
   Servo1.write(0);
}
