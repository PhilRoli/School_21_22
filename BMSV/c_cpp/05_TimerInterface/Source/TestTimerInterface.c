/*
 * 05_TimerInterface.c
 *
 * Created: 24.11.2021 09:17:48
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 * Description:
 */

#include <avr/iom644p.h>
#include <avr/io.h>
#include "HTLStddef.h"
#include "Timer.h"

#define F_CPU 16000000UL

void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int main(void)
{
    TTimer timer;
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_NORMAL, 1000, F_CPU);
    /* Replace with your application code */
    while (1)
    {
    }
}
