/*
 * RingBuffer.h
 *
 * Created: 24.01.2022 14:15:38
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *      Header File for the interface for Rs232 module on the AtMega644
 *      micro controller with Buffer Function
 */

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "HTLStddef.h"

/*******************************************************************************
 * TRingBuffer = Pointer to Structure of a RingBuffer
 * @param Read: Read index to the Buffer
 * @param Write: Write index to the Buffer
 * @param *Buffer: Pointer to the allocated Buffer
 * @param BufferSize: Size of the allocated Buffer
 *******************************************************************************/
typedef struct TRingbufferStruct *TRingBuffer;

/*******************************************************************************
 * Create a ring buffer for using in multi-threading environment.
 * The allocated ring buffer must be given free with RingbufferDestroy()
 * @param aBufferSize: The size of the data buffer
 * @return Pointer to the allocated ring buffer or NULL
 *******************************************************************************/
TRingBuffer RingbufferCreate(unsigned char aBufferSize);

/********************************************************************************
 * Destroys the given RingBuffer, if existing,
 * by freeing the allocated memory
 * @param aRingBuffer: The ringbuffer you want to destroy
 *******************************************************************************/
void RingbufferDestroy(TRingBuffer aRingBuffer);

/********************************************************************************
 * Write a byte into the ringbuffer on position of aRingBuffer->Write.
 * @param aRingBuffer ringbuffer you want to write to
 * @param aByte The byte you want to write into the ringbuffer
 * @return ETRUE if successful, EFALSE if wrtieIndex = readIndex
 *******************************************************************************/
TBool RingbufferWrite(TRingBuffer aRingBuffer, unsigned char aByte);

/********************************************************************************
 * Read a Byte from the buffer of position aRingBuffer->Read and write it into
 * the pointer to aByte.
 * @param aRingBuffer ringbuffer you want to read from
 * @param *aByte pointer to the char varaible you want to save the byte in
 * @return ETRUE if successful, EFALSE if readIndex = writeIndex
 *******************************************************************************/
TBool RingbufferRead(TRingBuffer aRingBuffer, unsigned char *aByte);

#endif