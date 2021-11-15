/*
 * 02_PinChangeInterrupt.c
 *
 * Created: 10.11.2021 09:11:10
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 */

#include <avr/io.h>
#include <avr/interrupt.h>

// initialize interrupt counter
volatile unsigned int intCounter = 0;

int main(void)
{
    // Enable Trigger Group 4 -> pin 24 in group 4
    PCICR |= (1 << PCIE3);

    // Enable PCINT on pin 24 in Mask Group 4
    PCMSK3 |= (1 << PCINT24);

    // Enable all interrupts
    sei();

    // Enable Output on PortA
    DDRA = 0xFF;

    /* Replace with your application code */
    while (1)
    {
        // Output counter to Port A
        PORTA = intCounter;
    }
}

// Interrupt Service Routine with Group 4 Vector
ISR(PCINT3_vect)
{
    // Increment Counter
    intCounter++;
}
