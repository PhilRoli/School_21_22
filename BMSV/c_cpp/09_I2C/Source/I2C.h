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
#define MAX_BUFFER_SIZE 10

typedef enum
{
    I2C_STATE_IDLE,
    I2C_STATE_START_W,
    I2C_STATE_STOP,
    I2C_STATE_FINISHED,
    I2C_STATE_ADDR_W,
    I2C_STATE_BYTE_W,
    I2C_STATE_ERROR
} TI2cState;

typedef struct TI2cStruct *TI2c;

/*******************************************************************************
 * Function to create a I2C Bus Connection
 * @param aCpuClock: CPU Clock Speed
 * @param aBitrate: Bitrate of the I2C Bus connection
 * @return TBool if action is successful
 *******************************************************************************/
TBool I2cInit(
    unsigned long aCpuClock,
    unsigned long aBitrate);

/*******************************************************************************
 * Function to write Data out on the I2C Bus
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aBufferSize: Size of the Data Buffer
 * @return TBool if action was successful
 *******************************************************************************/
TBool I2cWrite(
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aBufferSize);

/*******************************************************************************
 * Description
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aNoOfBytes: Number of bytes to read
 * @return TBool if action was successful
 *******************************************************************************/
TBool I2cRead(
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aNoOfBytes);

/*******************************************************************************
 * Description
 * @param aI2c: I2C Bus Object
 * @return TI2cState: State of the I2C Bus
 *******************************************************************************/
TI2cState I2cGetState(TI2c aI2c);

/*******************************************************************************
 * Description
 * @param void
 * @return Void
 *******************************************************************************/
void I2cDone(void);

/*******************************************************************************
 * Description
 * @param void
 * @return void
 *******************************************************************************/
void I2cStop(void);

#endif