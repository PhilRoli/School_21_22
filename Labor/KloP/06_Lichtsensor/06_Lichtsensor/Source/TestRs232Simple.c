/*
 * main.c
 *
 * Created: 01.03.2022 10:29:04
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Lab exercise for detecting light value in lux and outputting to Rs232
 */

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "HTLStddef.h"
#include "Rs232.h"

int MyPut(char aCharacter, FILE *aFile)
{
    Rs232WriteByte(aCharacter);
    return 1;
}

void ADCInit(void)
{
    ADMUX |= (3 << REFS0);  // AVCC with external capacitor
    ADMUX |= (16 << MUX0);  // 1x gain
    ADCSRA |= (1 << ADEN);  // Enables ADC
    ADCSRA |= (1 << ADPS2); // Division factor of 16
    PRR &= ~(1 << PRADC);
    ADMUX &= ~(1 << ADLAR);
}

unsigned int getvalue(void)
{
    unsigned int value;

    ADCSRA |= (1 << ADSC);

    while (ADCSRA & (1 << ADSC))
        ;

    value = ADCL; // Low
    value |= ((unsigned int)ADCH << 8);
    return value;
}

int main(void)
{
    DDRA = 0x00;

    ADCInit();
    Rs232Init();

    fdevopen(MyPut, NULL);

    while (1)
    {
        printf("%d ", getvalue());

        _delay_ms(500);
    }
}
