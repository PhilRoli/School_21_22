/*
 * 05_TimerInterface.c
 *
 * Created: 24.11.2021 09:17:48
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 *      Timer counts up permanently
 *      Set Period Time = Diffrence of one period
 *      Button Inc = Interrupts LED is on
 *      
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include "HTLStddef.h"
#include "Timer.h"

#define F_CPU 16000000UL

//* initialize variables
//! All times in us
// time between each timer interrupt
volatile int timerPeriod = 100;
// complete LED period time
volatile int ledPeriod = 100;
// Max Num of timer interrupts befor LED off + max num of buttoninc
// calc: ledPeriod / timerPeriod
volatile int periodMax = 100;
// Variable changed by up / down buttons
volatile int buttoninc = 0;

void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int main(void)
{
    TTimer timer;
    unsigned int mycounter = 0;
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_NORMAL, timerPeriod, F_CPU);
    TimerSetFunction(timer, TimerFunction, &mycounter);

    //* Registerys for Interrupts

    // Output of LED Signal on PortA pin 0
    DDRA |= (1 << 0);

    // Output Counter Value
    DDRB = 0xFF;

    // Set button Interrupt to trigger on negative flank
    EICRA |= 0x0A;

    // Enable int0 and int1 button interrupts
    // Int 0 -> UP | Int 1 -> Down
    EIMSK |= (1 << INT0);
    EIMSK |= (1 << INT1);

    // enable all interrupts
    sei();

    // enable pull ups on button interrupt pins
    PORTD |= (1 << 2);
    PORTD |= (1 << 3);

    // initialize old counter
    unsigned int oldcounter = 0;
    // initialize diff counter
    unsigned int diffcounter;

    /* Replace with your application code */
    while (1)
    {
        diffcounter = mycounter - oldcounter;

        if (diffcounter == 100)
        {
            PORTA |= (1 << 0);
            oldcounter = mycounter;
        }

        if (diffcounter == 20)
        {
            PORTA &= ~(1 << 0);
        }

        // if (oldcounter > mycounter)
        // {
        //     diffcounter = mycounter + (65.535 - oldcounter);
        // }
        // else
        // {
        //     diffcounter = mycounter - oldcounter;
        // }

        // // Start of Period - LED on
        // if (diffcounter == ledPeriod)
        // {
        //     oldcounter = mycounter;
        //     PORTA |= (1 << 0);
        // }

        // // End of LED on time - LED off
        // if (diffcounter == buttoninc)
        // {
        //     PORTA &= ~(1 << 0);
        // }

        // output current buttonInc value (7 LED's)
        PORTB = buttoninc;
        // PORTB = 0x33; //00110011;
    }
}

ISR(INT0_vect)
{
    // UP if buttonInc in range of 0 - 100
    if (buttoninc < periodMax)
    {
        buttoninc++;
    }
}

ISR(INT1_vect)
{
    // Down if buttonInc in range of 0 - 100
    if (buttoninc > 0)
    {
        buttoninc--;
    }
}
