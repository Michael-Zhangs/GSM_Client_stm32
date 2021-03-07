#ifndef __BSP_PRINTER_H
#define __BSP_PRINTER_H

#include "delay.h"
#include "uart.h"

#define PRINTER_SIZE_0	0x00
#define PRINTER_SIZE_1	0x11
#define PRINTER_SIZE_2	0x02
#define PRINTER_SIZE_3	0x03
#define PRINTER_SIZE_4	0x04
#define PRINTER_SIZE_5	0x05
#define PRINTER_SIZE_6	0x06
#define PRINTER_SIZE_7	0x07

#define PRINTER_POS_LEFT	0x00
#define PRINTER_POS_MID		0x01
#define PRINTER_POS_RIGHT	0x02

void PRINTER_Print(uint8_t* data);
void PRINTER_Init(void);
void PRINTER_SetSize(uint8_t n);
void PRINTER_SetPos(uint8_t n);

#endif
