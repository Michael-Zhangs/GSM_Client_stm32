#include "bsp_printer.h"

void PRINTER_Print(uint8_t* data)
{
	int i=0;
	while(*(data+i)!='\0')i++;
	i++;
	uart_tx_bytes(2,data,i);
}

void PRINTER_Init()
{
	uint8_t dat[]={0x1b,0x40};
	uart_tx_bytes(2, dat, 2);
}

void PRINTER_SetSize(uint8_t n)
{
	uint8_t dat[4]={0x1d,0x21};
	dat[2]=n;
	dat[3]=n;
	uart_tx_bytes(2,dat,4);
}

void PRINTER_SetPos(uint8_t n)
{
	uint8_t dat[3]={0x1b,0x61};
	dat[2]=n;
	uart_tx_bytes(2,dat,3);
}
