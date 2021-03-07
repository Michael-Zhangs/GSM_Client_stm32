/**
  ******************************************************************************
  * @author  ???? ASHINING
  * @version V3.0
  * @date    2016-10-08
  * @brief   UART??H??
  ******************************************************************************
  * @attention
  *
  * ??	:	http://www.ashining.com
  * ??	:	https://shop105912646.taobao.com
  * ????:	https://cdzeyao.1688.com
  ******************************************************************************
  */
	
#ifndef __UART_H
#define __UART_H

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"


//??????
#define UART1_PORT				USART1
#define UART1_PORT_CLK				RCC_APB2Periph_USART1
#define UART1_PORT_AF				GPIO_Remap_USART1

//??????
#define UART1_TX_GPIO_PORT			GPIOA
#define UART1_TX_GPIO_CLK			RCC_APB2Periph_GPIOA
#define UART1_TX_GPIO_PIN			GPIO_Pin_9

#define UART1_RX_GPIO_PORT			GPIOA
#define UART1_RX_GPIO_CLK			RCC_APB2Periph_GPIOA
#define UART1_RX_GPIO_PIN			GPIO_Pin_10

//??????
#define UART2_PORT					USART2
#define UART2_PORT_CLK			RCC_APB1Periph_USART2
#define UART2_PORT_AF				GPIO_Remap_USART2

//??????
#define UART2_TX_GPIO_PORT			GPIOA
#define UART2_TX_GPIO_CLK			RCC_APB2Periph_GPIOA
#define UART2_TX_GPIO_PIN			GPIO_Pin_2

#define UART2_RX_GPIO_PORT			GPIOA
#define UART2_RX_GPIO_CLK			RCC_APB2Periph_GPIOA
#define UART2_RX_GPIO_PIN			GPIO_Pin_3


void uart_init( uint32_t UartBaudRate );
void uart_tx_bytes(uint8_t port, uint8_t* TxBuffer, uint8_t Length );
uint8_t uart_rx_bytes(uint8_t port, uint8_t* RxBuffer );
void uart_SendStr(uint8_t port, uint8_t* dat);

#endif
