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
 * Variable that will hold the 200 byte packets
 */
char current_packet[200];
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
/**
 */
void read_packet() {
    if (Serial.available()) {
        Serial.readStringUntil('\0').toCharArray(current_packet, 200);
    } 
}
void setup() {
    Serial.begin(115200);
    STATES flight_status = PREFLIGHT;
    //Thermal Setup
    pinMode(TEMP_SENSOR_1, INPUT);
    pinMode(HEATER, OUTPUT);


}

void loop() {
    switch(flight_status) {
        case PREFLIGHT:
            read_packet()
            temp_reg();
        break;

        case MICROG:
            read_packet()
            temp_reg();
        break;

        case POSTFLIGHT:
            read_packet()
            temp_reg();
        break;
    }
}