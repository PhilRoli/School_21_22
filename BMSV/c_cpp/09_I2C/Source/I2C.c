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
#include <avr/interrupt.h>
#include "I2C.h"
#include "HTLStddef.h"
#include "RingBuffer.h"
#include "twi.h"

/*******************************************************************************
 * Structure of the I2C Bus Object
 * @param I2cState: Current state of the I2C Bus
 *******************************************************************************/
struct TI2cStruct
{
    TI2cState I2cState;
    TRingBuffer WBuffer;
};

// Private Variables
static TI2c I2c = NULL;

#define NO_OF_PRESCALER_VALUES 4
unsigned int I2cPrescaler[4] = {1, 4, 16, 64};

/*******************************************************************************
 * Function to create a I2C Bus Connection
 * @param aCpuClock: CPU Clock Speed
 * @param aBitrate: bit rate of the I2C Bus connection
 * @return I2C Bus Object
 *******************************************************************************/
TBool I2cInit(
    unsigned long aCpuClock,
    unsigned long aBitrate)
{
    unsigned int i;
    unsigned long twbr;
    // Sim. clears entire storage
    I2c = calloc(sizeof(struct TI2cStruct), 1);
    if (I2c == 0)
    {
        return EFALSE;
    }

    I2c->WBuffer = RingbufferCreate(MAX_BUFFER_SIZE + 1);
    if ( I2c->WBuffer)

    I2c->I2cState = I2C_STATE_IDLE;

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

    return ETRUE;
}

/*******************************************************************************
 * Function to write Data out on the I2C Bus
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aBufferSize: Size of the Data Buffer
 * @return xxx
 *******************************************************************************/
TBool I2cWrite(
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
 * @param aSlaveAddress: Address of the I2C Bus Slave
 * @param *aBuffer: Data Buffer
 * @param aNoOfBytes: Number of bytes to read
 * @return xxx
 *******************************************************************************/
TBool I2cRead(
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
TI2cState I2cGetState(TI2c aI2c)
{
}

/*******************************************************************************
 * Description
 * @param void
 * @return Void
 *******************************************************************************/
void I2cDone(void)
{
}
