/*
 * Timer.h
 *
 * Created: 29.11.2021 13:29:36
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Header File for the interface to the timers for the AtMega644 Microprocessor
*/

typedef enum
{
   TIMER_NO_0,
   TIMER_NO_1,
   TIMER_NO_2
} TTimerNo;

typedef enum
{
   TIMER_MODE_NORMAL,
   TIMER_MODE_CTC
} TTimerMode;

typedef struct
{
   TTimerNo TimerNo;
   TTimerMode TimerMode;
   unsigned long TimerInterval;
   unsigned long ClockFrequency;
} TTimerStruct;

typedef TTimerStruct *TTimer;

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
TimerCreate(TTimerNo aTimerNo, TTimerMode aTimerMode, unsigned long aTimerInterval, unsigned long aClkFrequency);