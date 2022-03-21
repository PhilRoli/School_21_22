/*
 * main.c
 *
 * Created: 21.03.2022 20:19:50
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *
 */

#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "HTLStddef.h"
#include "Rs232.h"
#include "Timer.h"

TRs232 MyRs232;

int MyPut(char aCharacter, FILE *aFile)
{
    Rs232WriteByte(MyRs232, aCharacter);
    return 1;
}

// Timer Function to be called on interrupt
void TimerFunction(void *aUserData)
{
    int *counter = (int *)aUserData;
    *counter += 1;
}

int main(void)
{
    TTimer timer;
    int myCounter = 0;
    volatile int tmp = 0;

    // MyPut is called by printf
    fdevopen(MyPut, NULL);

    MyRs232 = Rs232Init(20, 200);

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_CTC, 1000, F_CPU);

    // Set the interrupt Function to be called
    TimerSetFunction(timer, TimerFunction, &myCounter);

    /* Replace with your application code */
    while (1)
    {
        if (myCounter == 1000)
        {
            printf("07_LichtsensorPWM RolP");
            myCounter = 0;
        }
    }
}