//Thermal Regulation
//Based on http://www.electronoobs.com/eng_arduino_tut24_code3.php
#include <SPI.h>

int driver_pin = 3;
//Later define pins for driver, etc.

float temp_obj = 37; //Celsius

float PID_error = 0;
float prev_error = 0;
float PID_value = 0;

//Control terms
float PID_p = 0;
float PID_i = 0;
float PID_d = 0;

//Coefficients for control function - adjust as necessary
int k_p = 90;
int k_i = 30;
int k_d = 80;

float current_time = 0;
float prev_time = 0;

float readTemp() {
  //Implement later
}

void setup() {
  pinMode(driver_pin, OUTPUT);
  current_time = millis();
  //Later include setup for driver, etc.
}

void loop() {
  float current_temp = readTemp();
  PID_error = temp_obj - current_temp;
  PID_p = k_p*PID_error;
  PID_i = PID_i + k_i*PID_error;

  prev_time = current_time;
  current_time = millis();
  float delta_time = (current_time - prev_time)/1000;
  PID_d = k_d*(PID_error - prev_error)/delta_time;

  PID_value = PID_p + PID_i + PID_d;
  
  //Later write signal to driver

  prev_error = PID_error;
}
