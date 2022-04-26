/*******************************************************************************
 * main.c
 *
 * Created: 26.04.2022 08:25:52
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *
 *******************************************************************************/
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "twi.h"
#include "HTLStddef.h"

// Slave = 0100 A2 A1 A0 0
#define SLA_W 0x40

int main(void)
{
    // Pull Ups
    PORTC |= (1 << 0);
    PORTC |= (1 << 1);

    // Prescaler 1
    TWSR = (1 << TWPS0);
    // calculated in other lesson
    TWBR = 72;

    // data var
    unsigned char dataVar = 1;
    unsigned char updown = 0;

    /* Replace with your application code */
    while (1)
    {
        // Send START condition
        TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

        // Wait for TWINT Flag set. This indicates that the START condition has been transmitted.
        while (!(TWCR & (1 << TWINT)))
            ;

        // Check value of TWI Status Register. Mask Prescaler bits. If status different from START go to ERROR
        if ((TWSR & 0xF8) != TW_START)
        {
            return EFALSE;
        }

        // Load SLA_W into TWDR Register. Clear TWINT bit in TWCR to start transmission of address
        TWDR = SLA_W;
        TWCR = (1 << TWINT) | (1 << TWEN);

        // Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK ha  been received.
        while (!(TWCR & (1 << TWINT)))
            ;

        // Check value of TWI Status Register. Mask Prescaler bits. If status different from MT_SLA_ACK go to ERROR
        if ((TWSR & 0xF8) != TW_MT_SLA_ACK)
        {
            return EFALSE;
        }

        // Load DATA into TWDR Register. Clear TWINT bit in TWCR to start transmission of data
        TWDR = ~dataVar;
        TWCR = (1 << TWINT) | (1 << TWEN);

        // Wait for TWINT Flag set. This indicates that the DATA has been transmitted, and ACK/NACK has been received
        while (!(TWCR & (1 << TWINT)))
            ;

        // Check value of TWI Status Register. Mask Prescaler bits. If status different from MT_DATA_ACK go to ERROR
        if ((TWSR & 0xF8) != TW_MT_DATA_ACK)
        {
            return EFALSE;
        }

        // Transmit STOP condition.
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

        // Also overflow possible

        if (updown == 0)
        {
            if (dataVar == 255)
            {
                updown = 1;
                dataVar = 254;
            }
            else
            {
                dataVar++;
            }
        }
        else
        {
            if (dataVar == 0)
            {
                updown = 0;
                dataVar = 1;
            }
            else
            {
                dataVar--;
            }
        }

        _delay_ms(50);
    }
}
