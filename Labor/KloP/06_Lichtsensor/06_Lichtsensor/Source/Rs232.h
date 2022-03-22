/**********************************************

   File: Rs232.c
   Description:
      Simple polling interface for the Rs232 module of the AtMega644
      microcontroller
***************************************************/

#ifndef RS232_H
#define RS232_H // wichtig beide

#include "HtlStddef.h"

void Rs232Init(void);

TBool Rs232WriteByte(
    unsigned char aByte);

TBool Rs232Read(
    unsigned char *aByte);

#endif