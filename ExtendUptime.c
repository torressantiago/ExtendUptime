#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

// NOTE output pin => 13
// NOTE interrupt input pin => 2

void Timer1_config();
void externalInterrupt_config();

int main(void){
    externalInterrupt_config();

    // Configure pin 13 as output
    DDRB |= (1 << DDB5);

    while(1);

    return 0;
}

/*------- Configuration Functions -------*/
void Timer1_config(){
  	cli(); // stop interrupts
    // 2 Hz (16000000/((31249+1)*256))
    OCR1A = 31249;
    // CTC
    TCCR1A |= (1 << WGM12);
    // Prescaler 256
    TCCR1B |= (1 << CS12);
    // Output Compare Match A Interrupt Enable
    TIMSK1 |= (1 << OCIE1A);
    sei(); // allow interrupts
}

void externalInterrupt_config(){
    cli(); // stop interrupts
    // Set the rising edge of INT0 (pin 2) to generate an interrupt request
    EICRA |= (1 << ISC01) | (1 << ISC00);

    // Enable the interrupt
    EIMSK |= (1 << INT0);

    sei(); // allow interrupts
}

/*------- Interrupts -------*/
ISR(TIMER1_COMPA_vect){
    // Change value of output pin to 0
    PORTB &= (0 << PORTB5);

    // Clear Output Compare Match A Interrupt
    TIMSK1 &= (0 << OCIE1A);
}

ISR(INT0_vect){
    // Change value of output pin to 1
    PORTB |= (1 << PORTB5);

    // Set the timer
    Timer1_config();
}
