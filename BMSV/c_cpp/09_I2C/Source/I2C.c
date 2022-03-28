/*******************************************************************************
 * I2C.c
 *
 * Created: 21.03.2022 13:43:04
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		I2C Bus Programm
 *******************************************************************************/

I2cCreate(
    TI2cNumber aTI2cNumber,
    unsigned long aCpuClock,
    unsigned long aBitrate);

I2cWrite(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aBufferSize);

I2cRead(
    TI2c aI2c,
    unsigned char aSlaveAddress,
    unsigned char *aBuffer,
    unsigned char aNoOfBytes);

I2cGetState(I2c aI2c);
