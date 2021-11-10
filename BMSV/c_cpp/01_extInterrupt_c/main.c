/*
 * 01_extInterrupt_c.c
 *
 * Created: 08.11.2021 12:50:37
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 * External Interrupt 0 with any edge enabled
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// define input mask -> xxxx xxxx
#define INPUT_MASK 0x00;
// initialize interrupt counter
volatile unsigned int intCounter = 0;

int main(void)
{
    // Set interrupt to trigger on any flank
    EICRA |= (1 << ISC00);

    // Enable int0 interrupt
    EIMSK |= (1 << INT0);

    // Enable PullUp resistor - INT0 = PortD Pin 2
    PORTD |= (1 << PD2);

    // Enable all interrupts
    sei();

    // set PortA to output
    DDRA = 0xFF;

    /* Replace with your application code */
    while (1)
    {
        // Output intCounter to PortA
        PORTA = intCounter;
    }
}

ISR(INT0_vect)
{
    intCounter++;
    _delay_ms(100);
    // Due to the switch bouncing we delete all new interrupts that appeared in the 100ms delay time
    EIFR &= ~(1 << INTF0);
}
