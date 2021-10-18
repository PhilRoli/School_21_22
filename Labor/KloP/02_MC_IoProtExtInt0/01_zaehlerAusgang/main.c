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
        // Input am PINA an den ersten Bit shiften
        //und dann maskieren
        input = (PINA >> 6) & INPUT_MASK;

        // Solange der draht nicht auf GND steckt, hochzählen
        while (input == 1) {
            // Ausgeben des wertes an die 8 LEDs
			PORTB = outputwert;
            // Erhöhen des Zähler Wertes
            outputwert++;
            // Overflow da maximum 28 angezeigt werden darf
            if (outputwert == 29)
            {
                outputwert = 0;
            }
            // Warten
			_delay_ms(150);
            // Neues einlesen des Inputs ob die Richtung
            // geändert werden muss
			input = (PINA >> 6) & INPUT_MASK;
        }
        // Wenn der Draht auf GND steckt, runterzählen
        while (input == 0) {
            // Ausgeben des wertes an die 8 LEDs
			PORTB = outputwert;
            // Verringern des Zähler Wertes
            outputwert--;
            // Underflow da maximal 0
            if (outputwert > 28)
            {
                outputwert = 28;
            }
            // Warten
			_delay_ms(150);
            // Neues einlesen des Inputs ob die Richtung
            // geändert werden muss 
			input = (PINA >> 6) & INPUT_MASK;
        }
        
    }
}

