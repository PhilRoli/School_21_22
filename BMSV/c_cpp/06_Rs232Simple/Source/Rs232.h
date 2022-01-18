/*
 * Rs232.h
 *
 * Created: 18.01.2022 10:01:09
 * Author: Philipp Rolinek
 * Class: 4AHBG
 * Description:
 *	  	Header File for the interface for the Rs232 module of the AtMega644
 *    micro controller
*/
#ifndef RS232_H
#define RS232_H

#include "HTLStddef.h"

void Rs232Init(void);
TBool Rs232WriteByte(unsigned char aByte);
TBool Rs232Read(unsigned char *aByte);

#endif
