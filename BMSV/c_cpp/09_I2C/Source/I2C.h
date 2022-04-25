/*******************************************************************************
 * I2C.h
 *
 * Created: 21.03.2022 13:43:25
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		I2C Bus Programm
 *******************************************************************************/

#ifndef I2C_H
#define I2C_H

#include "HTLStddef.h"

typedef enum
{
    E_I2C_NO_0
} TI2cNumber;

typedef enum
{
    I2C_STATE_IDLE,
    I2C_STATE_START,
    I2C_STATE_STOP,
    I2C_STATE_FINISHED,
    I2C_STATE_ADDR_W,
    I2C_STATE_BYTE_W
} TI2cState;

typedef struct TI2cStruct *TI2c;

/*******************************************************************************
 * Function to create a I2C Bus Connection
 * @param aI2cNumber: Numberator of which I2C Bus it should create
 * @param aCpuClock: CPU Clock Speed
 * @param aBitrate: Bitrate of the I2C Bus connection
 * @return I2C Bus Object
 *******************************************************************************/
TI2c I2cCreate(
    TI2cNumber aI2cNumber,
    unsigned long aCpuClock,
    unsigned long aBitrate);

/*******************************************************************************
 * Function to write Data out on the I2C Bus
 * @param aI2c: I2C Bus Object
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aBufferSize: Size of the Data Buffer
 * @return xxx
 *******************************************************************************/
I2cWrite(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aBufferSize);

/*******************************************************************************
 * Description
 * @param aI2c: I2C Bus Object
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aNoOfBytes: Number of bytes to read
 * @return xxx
 *******************************************************************************/
I2cRead(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aNoOfBytes);

/*******************************************************************************
 * Description
 * @param aI2c: I2C Bus Object
 * @return xxx
 *******************************************************************************/
I2cGetState(TI2c aI2c);

#endif