/**********************************************

   File: Rs232.c
   Description:
      Simple polling interface for the Rs232 module of the AtMega644
      microcontroller
***************************************************/

#include <avr/io.h>

#include "HtlStddef.h"

void Rs232Init(void) // zum Inizialisieren baud konfigurieren und einstellen damit anwender nicht �ndern kann ersst n�chste version konfigurierbar machen
{

   UCSR0A = 0;
   UCSR0B = 0;
   UCSR0C = 0;

   UCSR0B = (1 << RXEN0) | (1 << TXEN0); // UCSR0B
   UCSR0C = (3 << UCSZ00);               // auf drei wegen 11 im datenblatt
   UBRR0 = 103;                          /* 9600 Baud*/
}

TBool Rs232WriteByte(unsigned char aByte)
{
   UDR0 = aByte;

   while (!(UCSR0A & (1 << TXC0)))
      ;

   UCSR0A |= (1 << TXC0); /* Reset the USART Transmit Complete Bit */
}

TBool Rs232Read(unsigned char *aByte) // * weil sonst landet es am stack
{
   if (UCSR0A & (1 << RXC0))
   {
      *aByte = UDR0;
      return EFALSE;
   }

   return EFALSE;
}
