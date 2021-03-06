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

/*******************************************************************************
 * States of the I2C Connection
 * @param I2C_STATE_IDLE: Idle State
 * @param I2C_STATE_START_W: Start Write Process
 * @param I2C_STATE_ADDR_W: Write Slave Adress for Write Process
 * @param I2C_STATE_BYTE_W: Write Data to I2C Connection
 * @param I2C_STATE_START_R: Start Read Process
 * @param I2C_STATE_ADDR_R: Write Slave Adress for Read Process
 * @param I2C_STATE_BYTE_R: Read Bytes from I2C Connection
 * @param I2C_STATE_BYTE_LAST_R: Read Last Byte
 * @param I2C_STATE_ERROR: Error State
 * @param I2C_STATE_STOP: Stop I2C Connection
 * @param I2C_STATE_FINISHED: Transmission Finished
 *******************************************************************************/
typedef enum
{
    I2C_STATE_IDLE,
    I2C_STATE_START_W,
    I2C_STATE_ADDR_W,
    I2C_STATE_BYTE_W,
    I2C_STATE_START_R,
    I2C_STATE_ADDR_R,
    I2C_STATE_BYTE_R,
    I2C_STATE_BYTE_LAST_R,
    I2C_STATE_ERROR,
    I2C_STATE_STOP,
    I2C_STATE_FINISHED
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
 * @return ETRUE if successful, EFALSE on error
 *******************************************************************************/
TBool I2cWrite(
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aBufferSize);

/*******************************************************************************
 * Function to read Data from the I2C Bus
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aNoOfBytes: Number of bytes to read
 * @return ETRUE if successful, EFALSE on error
 *******************************************************************************/
TBool I2cRead(
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aNoOfBytes);

/*******************************************************************************
 * Returns I2C Connection State
 * @param void
 * @return TI2cState: State of the I2C Bus
 *******************************************************************************/
TI2cState I2cGetState(void);

/*******************************************************************************
 * Description
 * @param void
 * @return Void
 *******************************************************************************/
void I2cDone(void);

/*******************************************************************************
 * Function to Stop the I2C Connection
 * @param void
 * @return void
 *******************************************************************************/
void I2cStop(void);

#endif