/*
 * Timer.c
 * 
 * Created: 24.11.2021 09:56:12
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *    Interface to the timers for the AtMega644 Microprocessor
*/

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "Timer.h"
#include "HTLStddef.h"

#define MAX_TIMER_NO 2

unsigned int TimerPrescaler[] = {1, 1, 8, 64, 256, 1042};

TTimer TIMER[MAX_TIMER_NO + 1];

// Declaration of private functions
PRIVATE TBool TimerInitNo0(TTimer aTimer);

/*
 * Function: TimerCreate
 * Description:
 *    Allocates memory for the requested timer and returns the timer object
 * Parameters:
 *    aTimerNo        - One of the available timer Numbers. See also TTimerNo
 *    aTimerMode      - The wanted timer Mode. See also TTimerMode
 *    aTimerIntervall - The wanted timer interrupt interval in us
 *    aClkFrequency   - The CPU clock frequency
 * Returnvalue:
 *    The timer object if successful, otherwise NULL
*/
TTimer TimerCreate(TTimerNo aTimerNo, TTimerMode aTimerMode, unsigned long aTimerInterval, unsigned long aClkFrequency)
{
   TTimer timer;

   if (aTimerNo > MAX_TIMER_NO)
   {
      return NULL;
   }

   // Reserve the size of the TTimerStruct in the heap memory and clear the memory
   timer = calloc(sizeof(TTimerStruct), 1);

   if (timer == NULL)
   {
      return NULL;
   }

   timer->TimerNo = aTimerNo;
   timer->TimerMode = aTimerMode;
   timer->TimerInterval = aTimerInterval;
   timer->ClockFrequency = aClkFrequency;

   switch (aTimerNo)
   {
   case TIMER_NO_0:
      TimerInitNo0(timer);
      break;

   default:
      return NULL;
   }

   TIMER[aTimerNo] = timer;

   return timer;
}

void TimerSetFunction(TTimer aTimer, TTimerFunction aFunction, void *aUserData)
{
   aTimer->InterruptFunction = aFunction;
   aTimer->UserData = aUserData;
}

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

   switch (aTimer->TimerMode)
   {
   case TIMER_MODE_NORMAL:

      // Start with highest prescaler value
      cs0 = sizeof(TimerPrescaler) / sizeof(int);
      do
      {
         cs0--;
         interval = ((double)TimerPrescaler[cs0] / aTimer->ClockFrequency) * 256;

      } while (interval * 1000000 > aTimer->TimerInterval && cs0 > 0);

      TCCR0B |= (cs0 << CS00);
      TIMSK0 |= (1 << TOIE0);

      break;

   default:
      success = EFALSE;
   }

   sei();

   return success;
}

/************************ Interrupt Service Routines ************************/
ISR(TIMER0_OVF_vect)
{
   if (TIMER[TIMER_NO_0]->InterruptFunction != NULL)
   {
      TIMER[TIMER_NO_0]->InterruptFunction(TIMER[TIMER_NO_0]->UserData);
   }
}