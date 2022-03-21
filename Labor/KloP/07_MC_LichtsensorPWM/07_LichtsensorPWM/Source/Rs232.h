/*
 * Rs232.h
 *
 * Created: 18.01.2022 10:01:09
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *	  	Header File for the interface for the Rs232 module of the AtMega644
 *    micro controller
 */
#ifndef RS232_H
#define RS232_H

#include "HTLStddef.h"

typedef enum
{
    ERS232_0,
    ERS232_1
} ERS232_NU;

typedef struct TRs232Struct *TRs232;

/*******************************************************************************
 * Function for initializing a Rs232 connection
 * @param aReciveBufferSize: Buffer Size for the receiving Buffer
 * @param aSendBufferSize: Buffer Size for the sending Buffer
 * @return ETRUE with no errors, EFALSE if the RingbufferCreate functions fail
 *******************************************************************************/
TRs232 Rs232Init(unsigned char aReciveBufferSize, unsigned char aSendBufferSize);

/*******************************************************************************
 * Function for writing a byte to the Rs232 Connection
 * @param aByte: The Byte to write out on the Rs232 Connection
 * @return (no return) ETRUE
 *******************************************************************************/
TBool Rs232WriteByte(TRs232 aRs232, unsigned char aByte);

/*******************************************************************************
 * Function for receiving a byte from the Rs232 Connection
 * @param *aByte: Pointer to the variable which the recived byte is written to
 * @return ETRUE on successful read, EFALSE if no byte could be read
 *******************************************************************************/
TBool Rs232Read(unsigned char *aByte);

/*******************************************************************************
 * Destory a Rs232 Connection
 * @param aRs232: The Rs232 Connection to destroy
 *******************************************************************************/
void Rs232Destory(TRs232 aRs232);

#endif
