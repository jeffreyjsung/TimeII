/** 
Writes data to the datalog.txt in the following format:
S (status)
TODO: add temperature and whether the servos turned on or not
*/

#include <SPI.h>
#include <SD.h>

File log_file;

char current_packet[200];
char current_status = '@';
/* 
 * Setup function sets the baud rate, and waits for the serial port to connect.
 * When connected, initializes the SD card to write. Creates a file, then writes.
 */
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  while (!SD.begin()) {
    ;
  }

  log_file = SD.open("datalog.txt", FILE_WRITE);
  if (log_file) {
    log_file.println("Writing...");
    log_file.close();
  }
}
/*
 * Gets a valid packet, then checks the status of the string buffer.
 * Then writes the current status to the file. 
 */
void loop() {
  if (Serial.available()) {
    get_valid_packet();
    if (is_valid_packet()) {
      get_status();
      log_file = SD.open("datalog.txt", FILE_WRITE);
      if (log_file) {
        log_file.println(current_status);
        log_file.close();
      }
    }
  }
}

/*
 * Reads a string from the serialport until a null terminator.
 * Stores the string into a buffer of size 200 characters.
 */
void get_valid_packet() {
  Serial.readStringUntil('\0').toCharArray(current_packet, 200);
}
/*
 * Checks to see if the initial character is less than @ and less than J. 
 * Not exactly sure why why those two specific characters!!!
 */

bool is_valid_packet() {
  bool is_not_empty = (strlen(current_packet) > 0);
  bool has_valid_first = ('@' <= current_packet[0] && current_packet[0] <= 'J');
  return (is_not_empty && has_valid_first);
}
/*
 * Returns the first character in the string buffer.
 */
 
void get_status() {
  current_status = current_packet[0];
}
