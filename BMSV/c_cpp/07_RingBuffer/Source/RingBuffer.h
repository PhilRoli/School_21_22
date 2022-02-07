/*
 * RingBuffer.h
 *
 * Created: 24.01.2022 14:15:38
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Header File for the interface for Rs232 module on the AtMega644
 *    micro controller with Buffer Function
*/

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "HTLStddef.h"

/**********************
 * Type: TRingBufferStruct
 * Desc: TRingBuffer = Pointer to Structure
 * Components:
 *    Read - Read index to the Buffer
 *    Write - Write index to the Buffer
 *    Buffer - Pointer to the allocated Buffer
 *    BufferSize - Size of the allocated Buffer
***********************/
typedef struct TRingbufferStruct *TRingBuffer;

#endif