/*
 * 05_TimerInterface.c
 *
 * Created: 24.11.2021 09:17:48
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "HTLStddef.h"
#include "Timer.h"

#define F_CPU 16000000UL

// initialize deltatime
volatile int schrittemax = 256;
volatile int timeinc = 0;

void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int main(void)
{
    TTimer timer;
    int mycounter = 0;
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_NORMAL, 100, F_CPU);
    TimerSetFunction(timer, TimerFunction, &mycounter);

    // Registerys for Timer

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
    // int deltatime = periodendauer / schrittemax;

    // Output Counter Value
    DDRB = 0xFF;

    // delta counter
    int deltacounter;
    int oldcounter = 0;

    /* Replace with your application code */
    while (1)
    {
        deltacounter = mycounter - oldcounter;
        PORTB = timeinc;
        if (deltacounter < timeinc)
        {
            PORTA |= (1 << 0);
        }
        else
        {
            PORTA &= ~(1 << 0);
        }

        if (deltacounter > periodendauer)
        {
            oldcounter = mycounter;
        }
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
