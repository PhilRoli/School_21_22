/*******************************************************************************
 * I2C.c
 *
 * Created: 21.03.2022 13:43:04
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		I2C Bus Program
 *******************************************************************************/

#include <stdlib.h>
#include <avr/io.h>
#include "I2C.h"
#include "HTLStddef.h"

/*******************************************************************************
 * Structure of the I2C Bus Object
 * @param I2cNumber: Number of which I2C Bus to choose
 * @param I2cState: Current state of the I2C Bus
 *******************************************************************************/
struct TI2cStruct
{
    TI2cNumber I2cNumber;
    TI2cState I2cState;
};

TI2c I2c = NULL;

#define NO_OF_PRESCALER_VALUES 4
unsigned int I2cPrescaler[4] = {1, 4, 16, 64};

/*******************************************************************************
 * Function to create a I2C Bus Connection
 * @param aI2cNumber: Numerator of which I2C Bus it should create
 * @param aCpuClock: CPU Clock Speed
 * @param aBitrate: bit rate of the I2C Bus connection
 * @return I2C Bus Object
 *******************************************************************************/
TI2c I2cCreate(
    TI2cNumber aI2cNumber,
    unsigned long aCpuClock,
    unsigned long aBitrate)
{
    TI2c i2c;
    unsigned int i;
    unsigned long twbr;
    // Sim. clears entire storage
    i2c = calloc(sizeof(struct TI2cStruct), 1);
    if (i2c == 0)
    {
        return 0;
    }

    I2c = i2c;
    i2c->I2cNumber = aI2cNumber;
    i2c->I2cState = I2C_STATE_IDLE;

    switch (aI2cNumber)
    {
    case E_I2C_NO_0:
        // Set bitrate -> TWBT register
        // Set Prescaler -> TWSR register

        // Array - highest -> lowest
        for (i = 0; i < NO_OF_PRESCALER_VALUES; i++)
        {
            twbr = (aCpuClock / aBitrate - 16) / 2 / I2cPrescaler[i];
            if (twbr < 256)
            {
                break;
            }
        }

        TWSR = (i << TWPS0);
        TWBR = twbr;

        break;

    default:
        return NULL;
        break;
    }
}

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
    unsigned char aBufferSize)
{
#if 1
    I2cStartWrite(aI2c);

    // Create ring buffer and store data bytes
    // Store Data bytes in a ring buffer
    // Write Data bytes

#endif
}

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
