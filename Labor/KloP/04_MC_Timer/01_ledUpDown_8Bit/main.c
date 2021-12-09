/*
 * main.c
 *
 * Created: 07.12.2021 09:54:38
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		LED up down with output of timeinc variable
*/

// To run the program in the simulator, uncomment
// #define SIM
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// initialize deltatime
volatile int schrittemax = 256;
volatile int timeinc = 0;

int main(void)
{
    // Output of Signal on PortA
    DDRA |= (1 << 0);

    // Set Interrupt to trigger on negative flank
    EICRA |= 0x0A;
    // Enable int0 and int1 interrupts
    // Int 0 -> UP | Int 1 -> Down
    EIMSK |= (1 << INT0);
    EIMSK |= (1 << INT1);

    // enable all interrupts
    sei();

    // enable pull ups on interrupt pins
    PORTD |= (1 << 2);
    PORTD |= (1 << 3);

    // Variables
    //* period time in us, change last value in ms
    int periodendauer = 1000 * 10;
    // Higher delta time -> brighter LED
    int deltatime = periodendauer / schrittemax;

    // Output Counter Value
    DDRB = 0xFF;

    /* Replace with your application code */
    while (1)
    {
        PORTA |= (1 << 0);
#ifndef SIM
        _delay_us(deltatime * timeinc);
#endif
        PORTA &= ~(1 << 0);
#ifndef SIM
        _delay_us(periodendauer - (deltatime * timeinc));
#endif
        PORTB = timeinc;
    }
}

ISR(INT0_vect)
{
    // UP
    if (timeinc < schrittemax)
    {
        timeinc++;
    }
}

ISR(INT1_vect)
{
    // Down
    if (timeinc > 0)
    {
        timeinc--;
    }
}
