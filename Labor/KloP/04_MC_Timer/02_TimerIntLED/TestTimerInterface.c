/*
 * 05_TimerInterface.c
 *
 * Created: 24.11.2021 09:17:48
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 *      TimerVariable (mycounter) -> every 100us +1
 *      Period Time = 10 000us -> 100 Timer Interrupts
 *      Button Variable -> +1 = 100us longer on Time of LED
 *      TimerVar = 0 -> LED on
 *      TimerVar = ButtonVar -> LED out
 *      TimerVar = 100 -> TimerVar = 0 -> LED on
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
// complete LED period time (10ms)
volatile int ledPeriod = 10000;
// max num of buttoninc
// calc: ledPeriod / timerPeriod
volatile int periodMax = 100;
// Variable changed by up / down buttons
volatile int buttoninc = 0;
// Counter changed by Timer Interrupts
volatile int mycounter = 0;

void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int main(void)
{
    TTimer timer = TimerCreate(TIMER_NO_0, TIMER_MODE_NORMAL, timerPeriod, F_CPU);
    TimerSetFunction(timer, TimerFunction, &mycounter);

    //* Registerys for Interrupts

    // Output of LED Signal on PortB pin 2
    DDRB |= (1 << 2);

    // Output Counter Value to 8 other LEDs
    DDRA = 0xFF;

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

    // higher deltatime -> brigther led
    int deltatime = ledPeriod / periodMax;

    /* Replace with your application code */
    while (1)
    {
        // Turn on LED
        PORTB |= (1 << 2);
        // Delay for deltatime * buttoninc
        delayTimer(deltatime * buttoninc);
        // turn off LED
        PORTB &= ~(1 << 2);
        // Wait out rest of the period time
        delayTimer(ledPeriod - (deltatime * buttoninc));
        // output current buttonInc value
        PORTA = buttoninc;
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

// function for waiting a specified time
void delayTimer(int waitTimeUS)
{
    // reset mycounter to 0 for fresh counting
    // done at the beginning to include the calculation time
    mycounter = 0;
    // if waitTime == 0, return
    if (waitTimeUS == 0)
    {
        return;
    }
    // waitCounter = times the timer has to trigger for the specified time to pass
    int waitCounter = waitTimeUS / timerPeriod;
    int tmpVar = 0;
    while (mycounter < waitCounter)
    {
        tmpVar++;
    }
    return;
}
