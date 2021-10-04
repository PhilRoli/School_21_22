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
// Import der delay Libary f�r _delay_ms()
#include <util/delay.h>
/*
* Festlegen der INPUT_MASK
* Nur werte die bei der Input Mask eine 1 haben werden überommen, alle anderen werden 0 gesetzt
* 0x07 = 0000 0111
* Bsp. 
* Wert:   xxxx x011
* Mask:   0000 0111
* Result:		011
*/
#define INPUT_MASK 0x07;

int main(void)
{
	// Initialisieren der verwendeten Variablen
	unsigned char inputWert1;
	unsigned char inputWert2;
	char          outputWert;
	unsigned char operatorAuswahl;
	
	// Port B als Input festlgen
	DDRB = 0x00;
	
	// Port A als Output festlegen
	DDRA = 0xFF;	
	
    // Eigentlicher Code
    while (1) 
    {	
		// Auslesen der Werte an PinB und das darüberlegen der Input Mask
		inputWert1 = PINB & INPUT_MASK;
		// Auslesen der Werte an PinB, um 3 nach Rechts shiften um die 
		// gewünschten Bits an den niedrigsten Stellen zu haben
		// xx11 1xxx -> xxxx x111
		// Danach die Input Maske darüber legen
		inputWert2 = ( PINB >> 3 ) & INPUT_MASK;
		// Auslesen der Werte an PinB, um 6 nach Rechst shiften und Maskieren
		// 11xx xxxx -> xxxx xx11
		// 0x03 = 0000 0011 -> Da nur noch 2 pins von interesse sind
		operatorAuswahl = ( PINB >> 6 ) & 0x03;
		
		// Abhängig vom operatorAuswahl wird eine Operation ausgeführt
		switch ( operatorAuswahl )
		{
		case 0:
			// Keine Auswahl -> Addition
			outputWert = inputWert1 + inputWert2;
			break;
		case 1:
			// 01 Auswahl -> Subtaktion
			outputWert = inputWert1 - inputWert2;
			break;
		case 2:
			// 10 Auswahl -> AND
			outputWert = inputWert1 & inputWert2;
			break;
		case 3:
			// 11 Auswahl -> OR
			outputWert = inputWert1 | inputWert2;
			break;
		default:
			outputWert = 0;
			break;
		}
		
		// Ausgabe auf PortA
		PORTA = outputWert;
    }
}

