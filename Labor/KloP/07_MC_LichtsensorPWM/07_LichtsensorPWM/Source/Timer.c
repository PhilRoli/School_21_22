/*
 * Timer.c
 *
 * Created: 24.11.2021 09:56:12
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *     Interface to the timers for the AtMega644 Microprocessor
 */

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "Timer.h"
#include "HTLStddef.h"

// Number of Timer Modes available
#define MAX_TIMER_NO 2

// Pre-scaler Modes available for ATmega644P
unsigned int TimerPrescaler[] = {1, 1, 8, 64, 256, 1024};

// initialize array of Timers, which will hold our Timers
TTimer TIMER[MAX_TIMER_NO + 1];

// Declaration of private functions
PRIVATE TBool TimerInitNo0(TTimer aTimer);

/*
 * Function: TimerCreate
 * Description:
 *     Allocates memory for the requested timer and returns the timer object
 * Parameters:
 *     aTimerNo        - One of the available timer Numbers. See also TTimerNo
 *     aTimerMode      - The wanted timer Mode. See also TTimerMode
 *     aTimerIntervall - The wanted timer interrupt interval in us
 *     aClkFrequency   - The CPU clock frequency
 * Return value:
 *     The timer object if successful, otherwise NULL
 */

/*
 *  Create a Timer with TimerCreate()
 *  @aTimerNo > Position of Timer in TIMER[]
 *  @aTimerMode > Mode of the Timer (CTC or Normal)
 *  @aTimerInterval > Interval between Timer Interrupts
 *  @aClkFrequency > CLock Frequency of the Microchip in use
 */
TTimer TimerCreate(TTimerNo aTimerNo, TTimerMode aTimerMode, unsigned long aTimerInterval, unsigned long aClkFrequency)
{
    TTimer timer;

    // If the given position in the Array is higher then the max number, cancel the Timer creation
    if (aTimerNo > MAX_TIMER_NO)
    {
        return NULL;
    }

    // Reserve the size of the TTimerStruct in the heap memory and clear the memory
    timer = calloc(sizeof(TTimerStruct), 1);

    // If no memory could be allocated, cancel the Timer creation
    if (timer == NULL)
    {
        return NULL;
    }

    // Set the Timer variables (defined in Timer.h) with the variables in the Function call
    timer->TimerNo = aTimerNo;
    timer->TimerMode = aTimerMode;
    timer->TimerInterval = aTimerInterval;
    timer->ClockFrequency = aClkFrequency;

    // Switch between the available Timer Numbers
    switch (aTimerNo)
    {
    case TIMER_NO_0:
        TimerInitNo0(timer);
        break;

    default:
        return NULL;
    }

    // Store the finished Timer in the TIMER[] array
    TIMER[aTimerNo] = timer;

    // Return the timer
    return timer;
}

/*
 *  Set the function to be triggered on Timer interrupt
 *  @aTimer > The timer which uses this function
 *  @aFunction > The Function to be called
 *  @*aUserData > A pointer to the variable which the Function uses
 */
void TimerSetFunction(TTimer aTimer, TTimerFunction aFunction, void *aUserData)
{
    // Set the Timer variables (defined in Timer.h) with the variables in the Function call
    aTimer->InterruptFunction = aFunction;
    aTimer->UserData = aUserData;
}

/*
 *
 */
TBool TimerSetPwmDutyCycle(TTimer aTimer, unsigned char aValue)
{
    // Change can result in an unwanted behavior
    switch (aTimer->TimerMode)
    {
    case TIMER_MODE_PWM_NON_INV:
        OCR0A = aValue;
        return ETRUE;
        break;

    case TIMER_MODE_PWM_2:
        OCR0B = aValue;
        return ETRUE;
        break;

    default:
        return EFALSE;
        break;
    }
}

// Functions not finished / used
#if 0
TimerDestroy(TTimer aTimer);

TimerStart(TTimer aTimer);

TimerStop(TTimer aTimer);
#endif

// Definition of private functions
PRIVATE TBool TimerInitNo0(TTimer aTimer)
{
    TBool success;

    double interval;
    // Clock select bits
    unsigned char cs0;
    unsigned long ocra;
    unsigned char cs0Max;

    cs0Max = sizeof(TimerPrescaler) / sizeof(int);

    switch (aTimer->TimerMode)
    {
        // Normal Timer Mode
    case TIMER_MODE_NORMAL:

        // Start with highest prescaler value (array max +1)
        cs0 = cs0Max;
        do
        {
            // Step down the prescaler (array position -1)
            cs0--;
            // Calculate the new interval
            interval = ((double)TimerPrescaler[cs0] / aTimer->ClockFrequency) * 256;
            // Check if interval is bigger then the wanted interval, if yes, lower prescaler
            // or stop if the prescaler is at 1
        } while (interval * 1000000 > aTimer->TimerInterval && cs0 > 0);

        // Setting the correct Flags for the Normal Timer Mode
        TCCR0B |= (cs0 << CS00);
        TIMSK0 |= (1 << TOIE0);

        break;

    // CTC Timer Mode
    case TIMER_MODE_CTC:
        for (cs0 = 1; cs0 < cs0Max; cs0++)
        {
            // Calculate Steps with given Presclaer
            ocra = (unsigned long)((aTimer->TimerInterval / 1000000.0) * (aTimer->ClockFrequency / TimerPrescaler[cs0] - 1));

            // If totalsteps in range 1 - 256, prescaler value found
            if (ocra < 256)
            {
                break;
            }

            // if no prescaler is high enough, go with highest possible delay
            if (cs0 >= cs0Max)
            {
                cs0 = cs0Max - 1;
                ocra = 255;
            }
        }

        // Set register to compare to
        OCR0A = ocra;
        // Set Prescaler
        TCCR0B |= (cs0 << CS00);
        // Enable CTC Mode
        TIMSK0 |= (1 << OCIE0A);
        // Enable CLear on Compare
        TCCR0A |= (1 << WGM01);

        break;

        // PWM Timer Mode
    case TIMER_MODE_PWM_NON_INV:
        // Fast PWM Mode

        // Start with highest prescaler value (array max +1)
        cs0 = cs0Max;
        do
        {
            // Step down the prescaler (array position -1)
            cs0--;
            // Calculate the new interval
            interval = ((double)TimerPrescaler[cs0] / aTimer->ClockFrequency) * 256;
            // Check if interval is bigger then the wanted interval, if yes, lower prescaler
            // or stop if the prescaler is at 1
        } while (interval * 1000000 > aTimer->TimerInterval && cs0 > 0);

        // Setting the correct Flags for the Normal Timer Mode
        TCCR0B |= (cs0 << CS00);
        // Enable PWM Mode 11 << 0
        TCCR0A |= (3 << WGM00);
        // Enable Non Inverted Mode 10 << 6
        TCCR0A |= (2 << COM0A0);
        // Precaution
        OCR0A = 0;

        break;

    case TIMER_MODE_PWM_2:
        // Prescaler 8
        cs0 = 2;
        // TODO: Calculate
        OCR0A = 100;

        TCCR0B |= (cs0 << CS00);
        TCCR0A |= (3 << WGM00);
        TCCR0B |= (1 << WGM02);
        TCCR0A |= (2 << COM0B0);

        OCR0B = 10;
        DDRB |= 1 << 4;

        TIMSK0 |= (1 << OCIE0A);
        TIMSK0 |= (1 << OCIE0B);

        break;

    default:
        // If no available Mode is selected, set success to False
        success = EFALSE;
    }

    // Activate all interrupts
    sei();

    // Return the success of the Function
    return success;
}

/************************ Interrupt Service Routines ************************/
ISR(TIMER0_OVF_vect)
{
    // If a interrupt function is defined, call it
    if (TIMER[TIMER_NO_0]->InterruptFunction != NULL)
    {
        TIMER[TIMER_NO_0]->InterruptFunction(TIMER[TIMER_NO_0]->UserData);
    }
}

ISR(TIMER0_COMPA_vect)
{
    // If a interrupt function is defined, call it
    if (TIMER[TIMER_NO_0]->InterruptFunction != NULL)
    {
        TIMER[TIMER_NO_0]->InterruptFunction(TIMER[TIMER_NO_0]->UserData);
    }
}

ISR(TIMER0_COMPB_vect)
{
  // If a interrupt function is defined, call it
  if (TIMER[TIMER_NO_0]->InterruptFunction != NULL)
  {
    TIMER[TIMER_NO_0]->InterruptFunction(TIMER[TIMER_NO_0]->UserData);
  }
}