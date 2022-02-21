/*
 * RingBuffer.c
 *
 * Created: 24.01.2022 14:15:31
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Thread Safe ring buffer for exchanging data between different tasks
 *    Interface for Rs232 module on the AtMega644
 *    micro controller with Buffer Function
 */

#include <stdlib.h>
#include <avr/io.h>

#include "HTLStddef.h"
#include "RingBuffer.h"

/**********************
 * Type: TRingBufferStruct
 * Components:
 *    Read - Read index to the Buffer
 *    Write - Write index to the Buffer
 *    Buffer - Pointer to the allocated Buffer
 *    BufferSize - Size of the allocated Buffer
 ***********************/
struct TRingbufferStruct
{
   unsigned char Read;
   unsigned char Write;
   unsigned char *Buffer;
   unsigned char BufferSize;
};

/************************
 * Function: RingbufferCreate
 * Desc:
 *    Create a ring buffer for using in multi-threading environment
 *    The allocated ring buffer must be given free with RingbufferDestroy()
 *
 * Parameters:
 *    aBufferSize - The size of the data buffer
 *
 * Return Value:
 *    Pointer to the allocated ring buffer or NULL
 ***********************/
TRingBuffer RingbufferCreate(unsigned char aBufferSize)
{
   TRingBuffer ringbuffer; // pointer to the ringbuffer
   ringbuffer = calloc(sizeof(struct TRingbufferStruct), 1);
   if (ringbuffer == NULL)
   {
      return NULL;
   }
   ringbuffer->Buffer = malloc(aBufferSize);
   if (!ringbuffer->Buffer)
   {
      RingbufferDestroy(ringbuffer);
      return NULL;
   }
   ringbuffer->BufferSize = aBufferSize;

   return ringbuffer;
};

/************************
 * Function: RingbufferDestroy
 * Desc:
 *
 * Parameters:
 *
 * Return Value:
 ***********************/
void RingbufferDestroy(TRingBuffer aRingBuffer)
{
   if (!aRingBuffer)
   {
      return;
   }

   if (aRingBuffer->Buffer)
   {
      free(aRingBuffer->Buffer);
   }

   free(aRingBuffer);
};

/************************
 * Function: RingbufferWrite
 * Desc:
 *
 * Parameters:
 *
 * Return Value:
 ***********************/
TBool RingbufferWrite(TRingBuffer aRingBuffer, unsigned char aByte)
{
   unsigned char writeIndex;
   // aRingBuffer->Write must not be set to invalid value!
   writeIndex = aRingBuffer->Write;

   aRingBuffer->Buffer[writeIndex] = aByte;
   writeIndex++;

   if (writeIndex >= aRingBuffer->BufferSize)
   {
      writeIndex = 0;
   }

   if (writeIndex == aRingBuffer->Read)
   {
      return EFALSE;
   }

   aRingBuffer->Write = writeIndex;

   return ETRUE;
};

/************************
 * Function: RingbufferRead
 * Desc:
 *
 * Parameters:
 *
 * Return Value:
 ***********************/
TBool RingbufferRead(TRingBuffer aRingBuffer, unsigned char *aByte)
{
   unsigned char readIndex;
   readIndex = aRingBuffer->Read;

   if (readIndex == aRingBuffer->Write)
   {
      return EFALSE;
   }

   *aByte = aRingBuffer->Buffer[readIndex];
   readIndex++;

   if (readIndex >= aRingBuffer->BufferSize)
   {
      readIndex = 0;
   }

   aRingBuffer->Read = readIndex;

   return ETRUE;
}