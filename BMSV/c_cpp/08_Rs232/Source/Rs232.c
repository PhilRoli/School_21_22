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

#include <stdlib.h>
#include <avr/io.h>
#include "HTLStddef.h"
#include "RingBuffer.h"
#include "Rs232.h"

/*******************************************************************************
 * Structure of a Rs232 Connection
 * @param Rs232Nu: Number of the Rs232 Connection
 * @param SendRingBuffer: RingBuffer for sending bytes
 * @param ReciveRingbuffer: RingBuffer for receiving bytes
 *******************************************************************************/
struct TRs232Struct
{
   ERS232_NU Rs232Nu;
   TRingBuffer SendRingbuffer;
   TRingBuffer ReciveRingbuffer;
};

/*******************************************************************************
 * Global Variable for the Rs232 connections for the Interrupt
 *******************************************************************************/
TRs232 Rs232_0;

/*******************************************************************************
 * Function for initializing a Rs232 connection
 * @param aReciveBufferSize: Buffer Size for the receiving Buffer
 * @param aSendBufferSize: Buffer Size for the sending Buffer
 * @return ETRUE with no errors, EFALSE if the RingbufferCreate functions fail
 *******************************************************************************/
TRs232 Rs232Init(unsigned char aReciveBufferSize, unsigned char aSendBufferSize)
{
   TRs232 rs232;
   rs232 = calloc(sizeof(struct TRs232Struct), 1);
   if (!rs232)
   {
      return NULL;
   }

   UCSR0A = 0;
   UCSR0B = 0;
   UCSR0C = 0;

   UCSR0B = (1 << RXEN0) | (1 << TXEN0);
   UCSR0C = (3 << UCSZ00);
   // 9600 Baud
   UBRR0 = 103;

   rs232->ReciveRingbuffer = RingbufferCreate(aReciveBufferSize + 1);
   rs232->SendRingbuffer = RingbufferCreate(aSendBufferSize + 1);

   if (!rs232->ReciveRingbuffer || !rs232->SendRingbuffer)
   {
      Rs232Destory(rs232);
      return NULL;
   }

   Rs232_0 = rs232;
   return rs232;
}

/*******************************************************************************
 * Function for writing a byte to the Rs232 Connection
 * @param aByte: The Byte to write out on the Rs232 Connection
 * @return (no return) ETRUE
 *******************************************************************************/
TBool Rs232WriteByte(TRs232 aRs232, unsigned char aByte)
{
   if (!RingbufferWrite(aRs232->SendRingbuffer, aByte))
   {
      return EFALSE;
   }

   UCSR0B |= (1 << UDRIE0);
   return ETRUE;
}

/*******************************************************************************
 * Function for receiving a byte from the Rs232 Connection
 * @param *aByte: Pointer to the variable which the recived byte is written to
 * @return ETRUE on successful read, EFALSE if no byte could be read
 *******************************************************************************/
TBool Rs232Read(unsigned char *aByte)
{
   if (UCSR0A & (1 << RXC0))
   {
      *aByte = UDR0;
      return ETRUE;
   }

   return EFALSE;
}

/*******************************************************************************
 * Destory a Rs232 Connection
 * @param aRs232: The Rs232 Connection to destroy
 *******************************************************************************/
void Rs232Destory(TRs232 aRs232)
{
   if (aRs232->ReciveRingbuffer)
   {
      RingbufferDestroy(aRs232->ReciveRingbuffer);
   }
   if (aRs232->SendRingbuffer)
   {
      RingbufferDestroy(aRs232->SendRingbuffer);
   }

   free(aRs232);
}

/*******************************************************************************
 * Interrupt for data transmission. This interrupt is active when the transmit
 * resistor is empty and the next data byte can be send.
 * @param USART0_UDRE_vec: Interrupt Vector
 *******************************************************************************/
ISR(USART0_UDRE_vect)
{
   unsigned char data;
   if (RingbufferRead(Rs232_0->SendRingbuffer, &data))
   {
      UDR0 = data;
   }
   else
   {
      UCSR0B &= ~(1 << UDRIE0);
   }
}