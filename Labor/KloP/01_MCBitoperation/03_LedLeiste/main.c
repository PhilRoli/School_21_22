/*
 * 03_LedLeiste.c
 *
 * Created: 28.09.2021 09:09:20
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 */

 #define  F_CPU 16000000UL
 #include <avr/io.h>
 #include <util/delay.h>

 #define INPUT_MASK 0x01;

int main(void)
{
	DDRA = 0xFF;
	
	char outputwert = 1;
	
    /* Replace with your application code */
    while (1) 
    {
		// PORTA = outputwert;
		/*
		if (outputwert < 128) {
			outputwert = outputwert * 2;
		} else if (outputwert = 128) {
			
			*/
		while (outputwert < 128) {
			outputwert = outputwert * 2;
			_delay_ms(100);
			PORTA = outputwert;
		}
		
		while (outputwert > 1) {
				outputwert = outputwert / 2;
				_delay_ms(100);
				PORTA = outputwert;
			}
		//}
		
		//_delay_ms(100);
    } 
}

