#ifndef __BSP_KEYBOARD_H
#define __BSP_KEYBOARD_H

#include "stm32f10x.h"

#define KEY_GPIO_CLK	RCC_APB2Periph_GPIOB
#define KEY_GPIO_PORT	GPIOB

#define KEY_ON	1
#define KEY_OFF	0

void KEY_Init(void);
uint8_t KEY_GetKey(void);

#endif
