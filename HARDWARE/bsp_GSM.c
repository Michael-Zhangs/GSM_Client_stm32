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
	cmd[i+9]='\"';
	cmd[i+10]='\r';
	cmd[i+11]='\n';
	cmd[i+12]='\0';
	uart_SendStr(1,"AT\r\n");
	Delayms(1000);
	if(!uart_rx_bytes(1,RBuffer))
		PRINTER_Print("No\n\n");
	uart_SendStr(1,"AT+CSCS=\"GSM\"\r\n");
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(1000);
	uart_SendStr(1,"AT+CMGF=1\r\n");
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(1000);
	uart_SendStr(1,cmd);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(10000);
	uart_SendStr(1,data);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(1000);
	uart_tx_bytes(1,&a,1);
	uart_rx_bytes(1,RBuffer);
	PRINTER_Print(RBuffer);
	Delayms(1000);
}
