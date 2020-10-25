#include "motor_setup.h"

/*Setups the servo motors with appropriate pins.*/
//FIX What is INPUT?
void setupMotor() {
  pinMode(STEP, INPUT);
  pinMode(DIR, INPUT);
  pinMode(nSLEEP, INPUT);
}

/*Activates the motors for some distance?.*/
//FIX
//What determines the distance?
void activateMotor(){
  digitalWrite(nSLEEP, HIGH);
  for (int i = 0; i < distance; i++) {
    digitalWrite(STEP, HIGH);
    delay(500);
    digitalWrite(STEP, LOW);
    delay(500);
  }
}


