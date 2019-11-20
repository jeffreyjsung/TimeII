#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PRELAUNCH 0
#define LIFTOFF 1
#define MGRAV_BEGIN 2
#define MGRAV_END 3
#define LANDING 4
#define FINISHED 5

/*
Test:
[A,11.16,8502.000000,0.000000,102.471875,0.000000,0.0]
[F,24.43,23838.000000,0.000000,433.167572,0.000000,0.0]
 */

/*
char readchar()
{
  //simulated character input + random [ and ]
  char randomletter = "ABCDEFG123.456][,,"[random() % 18];
}
*/

int flightStatus = PRELAUNCH;
int length = 100;

/*
void wait_for_open_bracket()
{
  //while(readchar() != '[');
  while (Serial.read() != '[');
}
*/

char *get_packet(int length)
{
  //allocates to the packet_str address, retrying if errors
  //wait_for_open_bracket();
  char *packet_str = malloc(length);
  char current_char = '[';
  for(int i = 0; current_char != ']' && i < length; i++)
  {
    //current_char = readchar();
    current_char = Serial.read();
    //error; retry
//    if (current_char == '[' || i == length)
//    {
//      get_packet(length);
//      return;
//    }
//    if (current_char == ']' && i > 0)
//    {
//      packet_str[i] = '\0';
//      return packet_str;
//    }
    packet_str[i] = current_char;
    if (i >= length - 1){
      packet_str[length-1] = '\0';
    }
  }
  return packet_str;
}

int pollStatus(char statusChar, int flightStatus) {
  if (statusChar == 'A') {
    return LIFTOFF;
  }
  else if (statusChar == 'D') {
    return MGRAV_BEGIN;
  }
  else if (statusChar == 'F') {
    return MGRAV_END;
  }
  else if (statusChar == 'H') {
    return LANDING;
  }
  else {
    return flightStatus;
  }
}

bool is_valid_packet(char *packet_str)
{
  char current_char = packet_str[0];
  while (current_char != '\0')
  {
    //verify that the packet is OK, currently do nothing
    return false;
  }
}

char *get_sub_packet(char *packet_str, int packet_no, int length)
{
  char *sub_packet_str = malloc(length);
  char current_char = packet_str[0];
  int packet_index = 0;
  int sub_packet_index = 0;
  int i = 0;
  while (current_char != '\0')
  {
    //return empty string if not found before end
    current_char = packet_str[i++];
    if (current_char == ',')
    {
      if (packet_index > packet_no)
      {
        sub_packet_str[sub_packet_index] = '\0';
        return;
      }
      packet_index++;
    }
    if (packet_index == packet_no)
    {
      sub_packet_str[sub_packet_index++] = current_char;
    }
  }
  sub_packet_str[sub_packet_index] = '\0';
  return sub_packet_str;
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (Serial.read() == '[') {
    char *packet_str = get_packet(length);
    //printf("PAK: %s\n", packet_str);

    free(packet_str);
    //char *sub_packet_str = get_sub_packet(packet_str, 1, length);
    //printf("SUB: %s\n", sub_packet_str);
    //Serial.println(sub_packet_str);
  }
}

