/*
 * TestRingBuffer.c
 *
 * Created: 24.01.2022 14:15:45
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Rs232 Transfer Program with Buffer function
 */

#include <avr/io.h>
#include <stdio.h>
#include "RingBuffer.h"
#include "HTLStddef.h"

TBool TestRingbuffer1(void);

int main(void)
{
    /* Replace with your application code */
    while (1)
    {
        TestRingbuffer1();
    }
}

TBool TestRingbuffer1(void)
{
#define BUFFER_SIZE1 5

    unsigned int counter;
    unsigned int error = 0;
    unsigned char dataByte;

    TRingBuffer ringbuffer;

    ringbuffer = RingbufferCreate(BUFFER_SIZE1);

    for (counter = 0; counter < 15; counter++)
    {
        if (!RingbufferWrite(ringbuffer, counter))
        {
            error++;
        }

        if (!RingbufferRead(ringbuffer, &dataByte))
        {
            error++;
        }

        if (counter != dataByte)
        {
            error++;
        }
    }
}
