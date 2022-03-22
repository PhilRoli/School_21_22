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

void ADCInit(void)
{
    // AVCC with external capacitor
    ADMUX |= (1 << REFS0);
    // Single Input ADC0
    ADMUX &= ~(31 << MUX0);
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
    value = value * 0.0782014;
    return value;
}

int main(void)
{
    // Set port A as input
    DDRA = 0x00;

    TTimer timer;
    int myCounter = 0;
    volatile int tmp = 0;
    int value = 0;

    // MyPut is called by printf
    fdevopen(MyPut, NULL);

    MyRs232 = Rs232Init(20, 200);

    ADCInit();

    // Create the Timer
    // Timer Number, Timer Mode, Interval in us, CPU Frequency
    timer = TimerCreate(TIMER_NO_0, TIMER_MODE_PWM_2, 1000, F_CPU);

    // Set the interrupt Function to be called
    TimerSetPwmDutyCycle(timer, 0);

    /* Replace with your application code */
    while (1)
    {
        value = getvalue();
        TimerSetPwmDutyCycle(timer, value);
        printf("%d ", value);
        _delay_ms(500);
    }
}