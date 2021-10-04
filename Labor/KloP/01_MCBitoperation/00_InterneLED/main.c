/*
 * 01_MCBitoperation.c
 *
 * Created: 21.09.2021 08:15:16
 * Author : Philipp Rolinek
 * Class: 4AHBG
 */ 

// Setzten der Microchip Frequenz
#define F_CPU 16000000UL
#include <avr/io.h>
// Import der delay Libary für _delay_ms()
#include <util/delay.h>

int main (void) {
    // DatenRegister D > Ersten Bit auf 8. Stelle shiften um nur den letzten Bit zu aktivieren
    DDRD |= (1 << 7);

    while(1) {
        /*
		* 0x80 > 1000 0000
		* Eingebaute LED wird über den höchsten Bit angesprochen, 
        * daher nur den höchsten Bit auf 1 setzten
		* _delay_ms(1000) => 1 Sekunde warten
		* 0x00 > 0000 0000
		* Ausschalten
		*/

        PORTD = 0x80;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
    }

}
