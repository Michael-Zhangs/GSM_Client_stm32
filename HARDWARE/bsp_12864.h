#ifndef __BSP_12864_H
#define __BSP_12864_H

#include "stm32f10x.h"
#include "delay.h"

#define LCD_GPIO_SID_CLK	RCC_APB2Periph_GPIOB
#define LCD_GPIO_SID_PORT	GPIOB
#define LCD_GPIO_SID_PIN	GPIO_Pin_9

#define LCD_GPIO_CLK_CLK	RCC_APB2Periph_GPIOB
#define LCD_GPIO_CLK_PORT	GPIOB
#define LCD_GPIO_CLK_PIN	GPIO_Pin_8

#define LCD_SID_1 GPIO_SetBits(LCD_GPIO_SID_PORT, LCD_GPIO_SID_PIN)
#define LCD_SID_0 GPIO_ResetBits(LCD_GPIO_SID_PORT, LCD_GPIO_SID_PIN)
#define LCD_CLK_1 GPIO_SetBits(LCD_GPIO_CLK_PORT, LCD_GPIO_CLK_PIN)
#define LCD_CLK_0 GPIO_ResetBits(LCD_GPIO_CLK_PORT, LCD_GPIO_CLK_PIN)


#define WRITE_CMD	0xF8//???  
#define WRITE_DAT	0xFA//???

void LCD_GPIO_Init(void);
void LCD_SendByte(u8 data);

void Lcd_WriteData(u8 Dat );
void Lcd_WriteCmd(u8 Cmd );
void Lcd_Init(void);
void LCD_Display_Words(uint8_t x,uint8_t y,uint8_t*str);
void LCD_Clear(void);

#endif
