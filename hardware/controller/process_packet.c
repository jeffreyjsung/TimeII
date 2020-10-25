#include "process_packet.h"

/*Sets up the packet processer with baud rate and pins.*/
//FIXME
//What is pin 13?
void setupPacketProcessor() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

/*Checks if a packet is available. MUST be called in
the for loop of the arduino. Until all packets are received*/
//FIX ME 
//How to know when all packets are received?
void retrievePackets() {
  if (Serial.available()) {
    getValidPacket();
    if (isValidPacket()) {
      getStatus();
      if (current_packet[0] == 'C')
        digitalWrite(13, HIGH);
    }
  }
}

/*Retrieves a valid packet.*/
void getValidPacket() {
  Serial.readStringUntil('\0').toCharArray(current_packet, 200);
}

/*Checks if a packet received is valid. Returns a boolean.*/
//FIXME 
//Which packet is being checked?
bool isValidPacket() {
  bool is_not_empty = (strlen(current_packet) > 0);
  bool has_valid_first = ('@' <= current_packet[0] && current_packet[0] <= 'J');
  return (is_not_empty && has_valid_first);
}
/*Gets the current status of the packet by retrieving the first character
and storing it in current status.*/
void getStatus() {
  current_status = current_packet[0];
}