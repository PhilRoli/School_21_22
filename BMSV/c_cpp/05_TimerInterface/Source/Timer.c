/*
 * Timer.c
 * 
 * Created: 24.11.2021 09:56:12
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *    Interface to the timers for the AtMega644 Microprocessor
*/

#include "Timer.h"
#include <stdlib.h>

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
TTimer
TimerCreate(TTimerNo aTimerNo, TTimerMode aTimerMode, unsigned long aTimerInterval, unsigned long aClkFrequency)
{
   TTimer timer;

   // Reserve the size of the TTimerStruct in the heap memory and clear the memory
   timer = calloc(sizeof(TTimerStruct), 1);

   if (timer == NULL)
   {
      return NULL;
   }

   return timer;
}

#if 0
TimerDestroy(TTimer aTimer);

TimerSetFunction(TTimer aTimer, TTimerFunction aFunction, void *aUserData);

TimerStart(TTimer aTimer);

TimerStop(TTimer aTimer);
#endif