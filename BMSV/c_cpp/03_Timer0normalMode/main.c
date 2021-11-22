/*
 * 03_Timer0normalMode.c
 *
 * Created: 17.11.2021 08:57:50
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 * Timer 0, mode normal
 * First Test
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int tmp = 0;
volatile int Timer0OverflowCounter = 0;

int main(void)
{
    // TCCR0A: default values used

    // Prescaler set to 1
    // TCCR0B |= (1 << CS00);

    // Prescaler set to 8
    TCCR0B |= (1 << CS01);

    // Prescaler set to 1024
    // TCCR0B |= (1 << CS02) | (1 << CS00);

    // enable timer overflow interrupt
    TIMSK0 |= (1 << TOIE0);

    // enable all interrupts
    sei();

    /* Replace with your application code */
    while (1)
    {
        tmp++;
		
		if ( Timer0OverflowCounter % 35 == 34)
		{
			// do something
			tmp++;
			Timer0OverflowCounter = 0;
		}
    }
}

ISR(TIMER0_OVF_vect)
{
    Timer0OverflowCounter++;
}
