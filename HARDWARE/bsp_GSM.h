#ifndef __BSP_GSM_H
#define __BSP_GSM_H

#include "uart.h"
#include "stm32f10x.h"
#include "Delay.h"
#include "bsp_printer.h"

void GSM_SendMsg(uint8_t* num, uint8_t* data);

#endif
