
/*Setups the pins and other properties for the timer.*/
void setupTimer() {
    // Set the Timer Mode to CTC
    TCCR0A |= (1 << WGM01);

    // Sets the value to count to 4ms
    OCR0A = 0xF9;

    //Set the ISR COMPA vect
    TIMSK0 |= (1 << OCIE0A);    

    //enable interrupts
    sei();         

    // set prescaler to 256 and start the timer
    TCCR0B |= (1 << CS02);
    
    //Sets timer to 0
    time = 0;
}

/*Interrupt service routine that will increment the counter.*/
ISR (TIMER0_COMPA_vect)  
{
    time += 4;
}