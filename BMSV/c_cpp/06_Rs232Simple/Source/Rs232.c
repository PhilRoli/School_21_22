/*
 * Rs232.c
 *
 * Created: 18.01.2022 09:01:49
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Simple polling interface for the Rs232 module of the AtMega644
 *    micro controller
*/

#include <avr/io.h>
#include "HTLStddef.h"

void Rs232Init(void)
{
   UCSR0A = 0;
   UCSR0B = 0;
   UCSR0C = 0;

   UCSR0B = (1 << RXEN0) | (1 << TXEN0);
   UCSR0C = (3 << UCSZ00);
   // 9600 Baud
   UBRR0 = 103;
}

TBool Rs232WriteByte(unsigned char aByte)
{
   // write transfer byte to register
   UDR0 = aByte;

   // wait till transfer is finished
   while (!(UCSR0A & (1 << TXC0)))
      ;

   // reset the USART Transmit Complete Bit
   UCSR0A |= (1 << TXC0);
}

TBool Rs232Read(unsigned char *aByte)
{
   if (UCSR0A & (1 << RXC0))
   {
      *aByte = UDR0;
      return ETRUE;
   }

   return EFALSE;
}