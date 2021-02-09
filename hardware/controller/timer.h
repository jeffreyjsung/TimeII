/*Contains functions used by the TIMEII timer.*/

#include <avr/io.h> 
#include <avr/interrupt.h>

/*The time*/
unsigned long time;

/*Setups the pins and other properties for the timer.*/
void setupTimer();

/*Timer0 overflow interrupt.*/
ISR (TIMER0_COMPA_vect);  