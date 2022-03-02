/*
 * Rs232TestSimple.c
 *
 * Created: 18.01.2022 08:47:31
 * Author: Philipp Rolinek
 * Class: 4AHBG
 */

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Rs232.h"
#include "HTLStddef.h"

TRs232 MyRs232;

int MyPut(char aCharacter, FILE *aFile)
{
    Rs232WriteByte(MyRs232, aCharacter);
    return 1;
}

int main(void)
{
    unsigned int counter = 0;
    unsigned char character;

    // MyPut is called by printf
    fdevopen(MyPut, NULL);

    MyRs232 = Rs232Init(20, 200);

#if 0
    /* Replace with your application code */
    while (1)
    {
        printf("My first RS232 transmission %u", counter++);
        _delay_ms(1000);
    }
#endif

    while (1)
    {
        if (Rs232Read(&character))
        {
            printf("%c", character);
        }
    }
}
