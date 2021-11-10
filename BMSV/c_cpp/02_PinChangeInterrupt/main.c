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
    // Trigger on any flank
    PCICR |= (1 << PCIE3);

    // Enable PCINT on pin 24
    PCMSK3 |= (1 << PCINT24);

    // Enable all interrupts
    sei();

    // Output
    DDRA = 0xFF;

    /* Replace with your application code */
    while (1)
    {
        // Output
        PORTA = intCounter;
    }
}

ISR(PCINT3_vect)
{
    intCounter++;
}
