#include "sd.h"

/*Reads file and sends it over serial.*/
void setupRead() {
  Serial.begin(115200);
  
  while (!Serial); // wait for serial port to connect. Needed for native USB port only
  while (!SD.begin());
    
  log_file = SD.open("datalog.txt");
  
  if (log_file) {
    Serial.println("datalog.txt");
     while (log_file.available()) {
      Serial.write(log_file.read());
    }
    log_file.close();
  } else {
    Serial.println("error opening");
  }
  
  Serial.println();
  Serial.println("Delete? Y/N");
}

/*Deletes current file if input is 'Y' or 'N'.*/
void deleteFile() {
  if (Serial.available()) {
    int delete_file = Serial.read();
    if (delete_file == 'Y') {
      if (SD.remove("datalog.txt")) {
        Serial.println("Successfully deleted");
      }
    }
  }
}

/*Setup function sets the baud rate, and waits for the serial port to connect.
 When connected, initializes the SD card to write. Creates a file, then writes.*/
void setupWrite() {
  Serial.begin(115200);

  while (!Serial) ;// wait for serial port to connect. Needed for native USB port only
  while (!SD.begin());

  log_file = SD.open("datalog.txt", FILE_WRITE);
  if (log_file) {
    log_file.println("Writing...");
    log_file.close();
  }
}

/*Gets a valid packet, then checks the status of the string buffer.
 Then writes the current status to the file.*/
void writeToFile() {
  if (Serial.available()) {
    getValidPacket();
    if (isValidPacket()) {
      getStatus();
      log_file = SD.open("datalog.txt", FILE_WRITE);
      if (log_file) {
        log_file.println(current_status);
        log_file.close();
      }
    }
  }
}