/*
 * 01_zaehlerAusgang.c
 *
 * Created: 12.10.2021 08:19:13
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define INPUT_MASK 0x01;


int main(void)
{
    // Output to portB
    DDRB = 0xFF;

    // Input PinA with pin = inputPin
    DDRA |= (1 << 6);

    // Pull-Up einschalten
    PORTA |= (1 << 6);

    char outputwert = 0;
    char input = 0;

    /* Replace with your application code */
    while (1) 
    {
        input = (PINA >> 6) & INPUT_MASK;

        while (input == 1) {
			PORTB = outputwert;
            outputwert++;
            if (outputwert == 29)
            {
                outputwert = 0;
            }
			_delay_ms(150);
			input = (PINA >> 6) & INPUT_MASK;
        }
        while (input == 0) {
			PORTB = outputwert;
            outputwert--;
            if (outputwert > 28)
            {
                outputwert = 28;
            }
			_delay_ms(150);
			input = (PINA >> 6) & INPUT_MASK;
        }
        
    }
}

