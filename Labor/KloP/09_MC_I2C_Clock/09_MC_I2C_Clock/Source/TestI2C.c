/*******************************************************************************
 * TestI2C.c
 *
 * Created: 24.05.2022 08:11:35
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *		Read time from PCF8583P Clock MC
 *******************************************************************************/

#include <avr/io.h>
#include <stdio.h>
#include "I2C.h"
#include "Rs232.h"
#define F_CPU 16000000UL

// 1010 000x (p. 16)
#define SLAVE_ADDRESS 0xA0

// TRs232 MyRs232;

// int MyPut(char aCharacter, FILE *aFile)
// {
//     Rs232WriteByte(MyRs232, aCharacter);
//     return 1;
// }

int main(void)
{
    unsigned char wBuffer[4];
    unsigned char rBuffer[4];
    unsigned char tmp = 0;

    I2cInit(F_CPU, 100000UL);

    // MyPut is called by printf
    // fdevopen(MyPut, NULL);

    // MyRs232 = Rs232Init(20, 10);

    while (1)
    {
        // printf("Test");
        wBuffer[0] = 1;
        I2cWrite(SLAVE_ADDRESS, wBuffer, 1);
        while (I2cGetState() != I2C_STATE_FINISHED)
        {
            tmp++;
        }

        I2cRead(SLAVE_ADDRESS, rBuffer, 4);
        while (I2cGetState() != I2C_STATE_FINISHED)
        {
            tmp++;
        }
       tmp++;
    }
}