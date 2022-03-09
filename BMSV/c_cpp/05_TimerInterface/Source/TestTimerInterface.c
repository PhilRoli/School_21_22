/*
 * 05_TimerInterface.c
 *
 * Created: 24.11.2021 09:17:48
 * Author : Philipp Rolinek
 * Class    : 4AHBG
 * Description:
 */

#include <avr/io.h>
#include "HTLStddef.h"
#include "Timer.h"

// Define CPU CLock Frequency
#define F_CPU 16000000UL

// Timer Function to be called on interrupt
void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int TestTimerNormal(void)
{
    TTimer timer;
    int myCounter = 0;
    volatile int tmp = 0;

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_NORMAL, 100, F_CPU);

    // Set the interrupt Function to be called
    TimerSetFunction(timer, TimerFunction, &myCounter);
    /* Replace with your application code */
    while (1)
    {
        // tmp variable so main while loop has code
        tmp++;
    }
}

int TestTimerCTC(void)
{
    TTimer timer;
    int myCounter = 0;
    volatile int tmp = 0;

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_CTC, 100, F_CPU);

    // Set the interrupt Function to be called
    TimerSetFunction(timer, TimerFunction, &myCounter);
    /* Replace with your application code */
    while (1)
    {
        // tmp variable so main while loop has code
        tmp++;
    }
}

int TestTimerFastPWM(void)
{
    TTimer timer;
    volatile int tmp = 0;

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_PWM_NON_INV, 100, F_CPU);

    TimerSetPwmDutyCycle(timer, 0x40);

    // Set OC0A pin to output
    DDRB |= (1 << 3);

    /* Replace with your application code */
    while (1)
    {
        // tmp variable so main while loop has code
        tmp++;
    }
}

int TestTimerFastPWM_2(void)
{
    TTimer timer;
    volatile int tmp = 0;

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency

    // Tmax = 256 * Vorteiler * CPU Clock
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_PWM_2, 100, F_CPU);

    TimerSetPwmDutyCycle(timer, 50);

    // Set OC0A pin to output
    DDRB |= (1 << 4);

    /* Replace with your application code */
    while (1)
    {
        // tmp variable so main while loop has code
        tmp++;
    }
}

int main(void)
{
    // TestTimerNormal();
    // TestTimerCTC();
    // TestTimerFastPWM();
    TestTimerFastPWM_2();
}