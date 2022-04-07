/*******************************************************************************
 * I2C.c
 *
 * Created: 21.03.2022 13:43:04
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		I2C Bus Programm
 *******************************************************************************/

#include <stdlib.h>
#include "I2C.h"

/*******************************************************************************
 * Structure of the I2C Bus Object
 * @param I2cNumber: Number of which I2C Bus to choose
 *******************************************************************************/
struct TI2cStruct
{
    TI2cNumber I2cNumber;
};

/*******************************************************************************
 * Function to create a I2C Bus Connection
 * @param aTI2cNumber: Numberator of which I2C Bus it should create
 * @param aCpuClock: CPU Clock Speed
 * @param aBitrate: Bitrate of the I2C Bus connection
 * @return I2C Bus Object
 *******************************************************************************/
TI2c I2cCreate(
    TI2cNumber aTI2cNumber,
    unsigned long aCpuClock,
    unsigned long aBitrate)
{
    switch (aTI2cNumber)
    {
    case E_I2C_NO_0:
        // Set bitrate -> TWBT register
        // Set Prescaler -> TWSR register

        // Array - highest -> lowest

        break;

    default:
        return NULL;
        break;
    }
}

/*******************************************************************************
 * Function to write Data out on the I2C Bus
 * @param aI2c: I2C Bus Object
 * @param aSlaveAddress: Adress of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aBufferSize: Size of the Data Buffer
 * @return xxx
 *******************************************************************************/
I2cWrite(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aBufferSize)
{
}

/*******************************************************************************
 * Description
 * @param aI2c: I2C Bus Object
 * @param aSlaveAddress: Adress of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aNoOfBytes: Number of bytes to read
 * @return xxx
 *******************************************************************************/
I2cRead(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aNoOfBytes)
{
}

/*******************************************************************************
 * Description
 * @param aI2c: I2C Bus Object
 * @return xxx
 *******************************************************************************/
I2cGetState(TI2c aI2c)
{
}
