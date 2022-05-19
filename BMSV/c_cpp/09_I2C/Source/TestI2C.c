/*******************************************************************************
 * TestI2C.c
 *
 * Created: 21.03.2022 13:43:37
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		I2C Bus Controller Program
 *      Data sheet:
 *          271 - Status Codes Master Transmitter Mode
 *******************************************************************************/

#include <avr/io.h>
#include "I2C.h"
#define F_CPU 16000000UL

int main(void)
{
    unsigned char buffer[3];

    I2cInit(F_CPU, 100000UL);

    I2cRead(0x20, buffer, 3);
    while (1)
    {
    }
}