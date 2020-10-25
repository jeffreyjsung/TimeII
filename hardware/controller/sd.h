/** 
Writes data to the datalog.txt in the following format:
S (status)
TODO: add temperature and whether the servos turned on or not
*/
#ifndef SD
#define SD

#include <SPI.h>
#include <SD.h>
#include "process_packet.h"

File log_file;

char current_packet[200];
char current_status = '@';

/*Setup function sets the baud rate, and waits for the serial port to connect.
 When connected, initializes the SD card to write. Creates a file, then writes. */
void setupWrite();

/*Gets a valid packet, then checks the status of the string buffer.
Then writes the current status to the file.*/
void writeToFile();

/*Reads file and sends it over serial.*/
void setupRead();

/*Deletes the current file.*/
void deleteFile();

#endif