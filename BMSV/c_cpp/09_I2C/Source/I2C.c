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

#define SDA_PIN 1
#define SCL_PIN 0
#define TWI_PIN_PORT PINC

/*******************************************************************************
 * Structure of the I2C Bus Object
 * @param I2cState: Current state of the I2C Bus
 *******************************************************************************/
struct TI2cStruct
{
    TI2cState I2cState;
    TRingBuffer WBuffer;
    unsigned char Address;
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
    if (I2c->WBuffer)
    {
        I2c->I2cState = I2C_STATE_IDLE;
    }
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

    sei();

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
    // Create ring buffer and store data bytes
    // Store Data bytes in a ring buffer
    // Write Data bytes
    unsigned int i;
    for (i = 0; i < aBufferSize; i++)
    {
        if (!RingbufferWrite(I2c->WBuffer, aBuffer[i]))
        {
            return EFALSE;
        }
    }
    I2c->Address = aSlaveAddress;
    I2c->I2cState = I2C_STATE_START_W;
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
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

/*******************************************************************************
 * Description
 * @param void
 * @return void
 *******************************************************************************/
void I2cStop(void)
{
    volatile unsigned int counter;
    unsigned char pins = (1 << SDA_PIN) | (1 << SCL_PIN);
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
    for (counter = 0; counter < 100; counter++)
    {
        if ((TWI_PIN_PORT & pins) == pins)
        {
            break;
        }
    }
}

/************************** INTERRUPT SERVICE ROUTINE **************************/
ISR(TWI_vect)
{
    unsigned char dataByte;
    unsigned char i2cStatus;
    i2cStatus = (TWSR & TW_STATUS_MASK);
    switch (I2c->I2cState)
    {
    case I2C_STATE_START_W:
        if (i2cStatus != TW_START)
        {
            I2c->I2cState = I2C_STATE_ERROR;
        }
        else
        {
            I2c->I2cState = I2C_STATE_ADDR_W;
            TWDR = I2c->Address & ~0x01;
            TWCR = (1 << TWINT) | (1 << TWEN);
        }
        break;

    case I2C_STATE_ADDR_W:
        if (i2cStatus != TW_MT_SLA_ACK)
        {
            I2c->I2cState = I2C_STATE_ERROR;
        }
        else
        {
            if (RingbufferRead(I2c->WBuffer, &dataByte))
            {
                I2c->I2cState = I2C_STATE_BYTE_W;
                TWDR = dataByte;
                TWCR = (1 << TWINT) | (1 << TWEN);
            }
            else
            {
                I2cStop();
                I2c->I2cState = I2C_STATE_FINISHED;
            }
        }
        break;

    case I2C_STATE_BYTE_W:
        if (i2cStatus != TW_MT_DATA_ACK)
        {
            I2c->I2cState = I2C_STATE_ERROR;
        }
        else
        {
            if (RingbufferRead(I2c->WBuffer, &dataByte))
            {
                I2c->I2cState = I2C_STATE_BYTE_W;
                TWDR = dataByte;
                TWCR = (1 << TWINT) | (1 << TWEN);
            }
            else
            {
                I2cStop();
                I2c->I2cState = I2C_STATE_FINISHED;
            }
        }
        break;

    default:
        break;
    }
}