/*
 * TestRingBuffer.c
 *
 * Created: 24.01.2022 14:15:45
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *      Rs232 Transfer Program with Buffer function
 */

// Write 4 bytes, check if 5th byte is not working, read 4 bytes, start again

#include <avr/io.h>
#include <stdio.h>
#include "RingBuffer.h"
#include "HTLStddef.h"

TBool TestRingbuffer1(void);
TBool TestRingbuffer2(void);

int main(void)
{
    while (1)
    {
        // TestRingbuffer1();
        TestRingbuffer2();
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

    if (error)
    {
        return EFALSE;
    }
    return ETRUE;
}

TBool TestRingbuffer2(void)
{
#define BUFFER_SIZE 5
    unsigned int counter;
    unsigned int smallCounter;
    unsigned int error = 0;
    unsigned char dataByte;

    TRingBuffer ringbuffer;

    ringbuffer = RingbufferCreate(BUFFER_SIZE);

    for (counter = 0; counter < 15; counter++)
    {
        for (smallCounter = 0; smallCounter < BUFFER_SIZE; smallCounter++)
        {
            if (!RingbufferWrite(ringbuffer, smallCounter))
            {
                error++;
            }
        }
        for (smallCounter = 0; smallCounter < BUFFER_SIZE - 1; smallCounter++)
        {
            if (!RingbufferRead(ringbuffer, &dataByte))
            {
                error++;
            }
        }
    }

    if (error)
    {
        return EFALSE;
    }
    return ETRUE;
}
