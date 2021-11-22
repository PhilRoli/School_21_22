/*
 * 04_Timer0CtcMode.c
 *
 * Created: 22.11.2021 13:57:03
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int Timer0CompareCounter = 0;
volatile unsigned int tmp = 0;

int main(void)
{

    // Prescaler set to 8
    TCCR0B |= (1 << CS01);

    // Enable Output Compare Interrupt Enable
    TIMSK0 |= (1 << OCIE0A);

    // ?
    TCCR0A |= (1 << WGM01);
	
	// Output Compare Register
	OCR0A = 20;

    // Enable all interrupts
    sei();

    /* Replace with your application code */
    while (1)
    {
        tmp++;
    }
}

ISR(TIMER0_COMPA_vect)
{
    Timer0CompareCounter++;
}
