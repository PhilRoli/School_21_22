/*
 * 02_Zaehler.c
 *
 * Created: 28.09.2021 08:42:23
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define INPUT_MASK 0x01;

int main(void)
{
	unsigned char inputWert;
			 char outputWert = 0;
			 
	DDRB = 0x00;
	DDRA = 0xFF;
	
	PORTA = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
	inputWert = PINB & INPUT_MASK;
		
	if (inputWert == 0) {
			outputWert--;
    } else {
		outputWert++;
	}
	
	PORTA = outputWert;
	
	_delay_ms(300);
	
	}
}

