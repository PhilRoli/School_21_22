/*
 * 02_zaehlerExtInt0.c
 *
 * Created: 12.10.2021 10:00:36
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
// Include path for vscode
// #include "C:/Program Files (x86)/Atmel/Studio/7.0/packs/atmel/ATmega_DFP/1.6.364/include/avr/iom644p.h"

// define input mask -> xxxx xxx1
#define INPUT_MASK 0x01;
// initialize interrupt counter
volatile int intCounter = 0;

int main(void)
{
	// Output to portB
    DDRB = 0xFF;
	// Input aktivieren
	PORTD |= ( 1 << 2 );

    // Set interrupt to trigger on negative flank
    EICRA |= 0x02;
    // Enable int0 interrupt
    EIMSK |= (1 << INT0);
    // Enable all interrupts
    sei();
    /* Replace with your application code */
    while (1) 
    {
        // Dauerhaftes ausgeben des Zähler Werts am PORTB
        // Erhöhen nur durch Interrupts
        PORTB = intCounter;
    }
}

ISR (INT0_vect) 
{
    _delay_ms(100);
    intCounter++;
	// Löschen aller interupts die im zeitraum des delays aufgekommen sind
	EIFR &= ~(1<< INTF0);
}

