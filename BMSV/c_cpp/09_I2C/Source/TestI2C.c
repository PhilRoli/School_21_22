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
    TI2c i2c;
    i2c = I2cCreate(E_I2C_NO_0, F_CPU, 100000UL);
    while (1)
    {
    }
}