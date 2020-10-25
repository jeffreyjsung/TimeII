#include "thermal.h"

/*Setups the thermals with the right pins.*/
void setupThermal() {
  Serial.begin(115200);
  pinMode(TEMP_SENSOR_1, INPUT);
  pinMode(HEATER, OUTPUT);
}

/*Sensor that checks the temperature and converts the voltage
to a temperature. Returns if at the correct temperature.*/
bool atTemp(int pin) {
  // Should change to <= because of schematic
  return (analogRead(pin) >= FIVE_VOLTS / 2.0);
}

/*Regulates the temperature.*/
void controlThermals() {
  Serial.println(atTemp(TEMP_SENSOR_1));
  if (!atTemp(TEMP_SENSOR_1)) {
    digitalWrite(HEATER, HIGH);
  } else {
    digitalWrite(HEATER, LOW);
  }
}

/*Reads the temperature and returns a float.*/
float readTemp(int pin) {
  return (1.0 / (1.0/298.15 + 1.0/3950.0 * log(1023.0/float(analogRead(pin)) - 1.0)) - 273.15);
}