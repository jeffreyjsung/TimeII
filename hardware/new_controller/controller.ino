#define FIVE_VOLTS 972.0
#define HEATER A5;
#define TEMP_SENSOR_1 A0;
#include <SPI.h>
#include <SD.h>

/**
 * Data structure that describes the states of the machine.
 * PREFLIGHT: subroutines include temp. check and data writes to SD
 * MICROG: Run the experiment, while also maintaing temperature and data writes to SD
 * POSTFLIGHT: TBD
*/
typedef enum {
    PREFLIGHT,
    MICROG,
    POSTFLIGHT
} STATES;

/**
 * temp_reg takes in no arguments and determines if
 * the temperature needs to be raised.
 */
bool temp_reg() {
    // Should change to <= because of schematic
    bool state_ok = (analogRead(TEMP_SENSOR_1) >= FIVE_VOLTS / 2.0);
    if (!state_ok) 
    digitalWrite(HEATER, HIGH);
    else 
    digitalWrite(HEATER, LOW);
}
/** read_temp takes a pin and returns the translation from voltage 
 * to Farhenheit degrees
 */
float read_temp() {
  return (1.0 / (1.0/298.15 + 1.0/3950.0 * log(1023.0/float(analogRead(TEMP_SENSOR_1)) - 1.0)) - 273.15);
}

void setup() {
    STATES flight_status = PREFLIGHT;
    //Thermal Setup
    pinMode(TEMP_SENSOR_1, INPUT);
    pinMode(HEATER, OUTPUT);


}

void loop() {
    switch(flight_status) {
        case PREFLIGHT:
            temp_reg();
        break;

        case MICROG:
            temp_reg();
        break;

        case POSTFLIGHT:
            temp_reg();
        break;
    }
}