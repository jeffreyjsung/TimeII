#ifndef PROCESS_PACKET
#define PROCESS_PACKET

//int current_temps[5];
//int sensor_port[5] = {15, 16, 17, 18, 19};
//TO DO: Wait until any writing is done to prevent bufferoverflow
char current_packet[200];
char current_status = '@';

/*Setups the interval variables for processing.*/
void setupPacketProcessor();

/*Waits until all packets are received.*/
void retrievePackets();

/*Retrieves a valid packet.*/
void getValidPacket();

/*Checks if the packet is valid, returns a boolean.*/
bool isValidPacket();

/*Gets the current status.*/
void getStatus();



#endif