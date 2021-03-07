#include "bsp_GSM.h"

void GSM_SendMsg(uint8_t* num, uint8_t* data)
{
	int i=0;
	uint8_t RBuffer[100];
	uint8_t cmd[50] = "AT+CMGS=\"";
	uint8_t a=0x1a;
	while(*(num+i)!=0)
	{
		cmd[i+9]=*(num+i);
		i++;
	}
	uart_SendStr(1,num);
	cmd[i+9]='\n';
	cmd[i+10]='\0';
	uart_SendStr(1,"AT\n");
	Delayms(100);
	if(!uart_rx_bytes(1,RBuffer))
		PRINTER_Print("No\n\n");
	uart_SendStr(1,"AT+CSCS=\"GSM\"\n");
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(100);
	uart_SendStr(1,"AT+CMGF=1\n");
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(100);
	uart_SendStr(1,cmd);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(100);
	uart_SendStr(1,data);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(100);
	uart_tx_bytes(1,&a,1);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(100);
}
