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
    // AVCC with external capacitor
    ADMUX |= (3 << REFS0);
    // 1x gain between ADC0 and ADC1
    ADMUX |= (16 << MUX0);
    // Enables ADC
    ADCSRA |= (1 << ADEN);
    // Division factor of 16
    ADCSRA |= (1 << ADPS2);
    // Activates the ADC
    PRR &= ~(1 << PRADC);
    // Left Adjust Result
    ADMUX &= ~(1 << ADLAR);
}

unsigned int getvalue(void)
{
    unsigned int value;
    // Start ADC Conversion
    ADCSRA |= (1 << ADSC);
    // Wait until conversion is finished
    while (ADCSRA & (1 << ADSC))
        ;

    // Read lower part of ADC converted value
    value = ADCL;
    // Read hig part of value
    value |= ((unsigned int)ADCH << 8);
    return value;
}

int main(void)
{
    // Set port A as input
    DDRA = 0x00;

    // Initialize ADC converter and Rs232 connection
    ADCInit();
    Rs232Init();

    // fdevopen() gets called by "printf()"
    fdevopen(MyPut, NULL);

    while (1)
    {
        // Print value to Rs232 connection
        printf("%d ", getvalue());

        _delay_ms(500);
    }
}
