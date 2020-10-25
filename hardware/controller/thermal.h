#ifndef THERMAL
#define THERMAL

#define FIVE_VOLTS 972.0
#define HEATER A5;
#define TEMP_SENSOR_1 A0;

float tempOne;

/*Sets the pins for the thermal controller.*/
void setupThermal();

/*Sensor that checks the temperature and converts the voltage
to a temperature. Returns if at the correct temperature.*/
bool atTemp(int pin);

/*Regulates the temperature.*/
void controlThermals();

/*Reads the temperature and returns a float.*/
float readTemp(int pin);

#endif