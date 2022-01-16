/*
 * 04_pinio.c
 *
 * Created: 28.09.2021 10:16:41
 * Author : Philipp Rolinek
 * Class  : 4AHBG
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRA = 0xFF;

  /* Replace with your application code */
  while (1)
  {
    PINA = 0xFF;
    _delay_ms(300);
  }
}
