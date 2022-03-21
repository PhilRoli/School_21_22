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

/*******************************************************************************
 * Structure of a RingBuffer
 * @param Read: Read index to the Buffer
 * @param Write: Write index to the Buffer
 * @param *Buffer: Pointer to the allocated Buffer
 * @param BufferSize: Size of the allocated Buffer
 *******************************************************************************/
struct TRingbufferStruct
{
   unsigned char Read;
   unsigned char Write;
   unsigned char *Buffer;
   unsigned char BufferSize;
};

/*******************************************************************************
 * Create a ring buffer for using in multi-threading environment.
 * The allocated ring buffer must be given free with RingbufferDestroy()
 * @param aBufferSize: The size of the data buffer
 * @return Pointer to the allocated ring buffer or NULL
 *******************************************************************************/
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

/********************************************************************************
 * Destroys the given RingBuffer, if existing,
 * by freeing the allocated memory
 * @param aRingBuffer: The ringbuffer you want to destroy
 *******************************************************************************/
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

/********************************************************************************
 * Write a byte into the ringbuffer on position of aRingBuffer->Write.
 * @param aRingBuffer ringbuffer you want to write to
 * @param aByte The byte you want to write into the ringbuffer
 * @return ETRUE if successful, EFALSE if wrtieIndex = readIndex
 *******************************************************************************/
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

/********************************************************************************
 * Read a Byte from the buffer of position aRingBuffer->Read and write it into
 * the pointer to aByte.
 * @param aRingBuffer ringbuffer you want to read from
 * @param *aByte pointer to the char varaible you want to save the byte in
 * @return ETRUE if successful, EFALSE if readIndex = writeIndex
 *******************************************************************************/
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