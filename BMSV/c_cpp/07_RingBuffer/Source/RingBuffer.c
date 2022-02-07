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
RingbufferDestroy(TRingBuffer aRingBuffer);

/************************
 * Function: RingbufferRead
 * Desc: 
 * 
 * Parameters: 
 * 
 * Return Value: 
 ***********************/
RingbufferRead();

/************************
 * Function: RingbufferWrite
 * Desc: 
 * 
 * Parameters: 
 * 
 * Return Value: 
 ***********************/
RingbufferWrite();