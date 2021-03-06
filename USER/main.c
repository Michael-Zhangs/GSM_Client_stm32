#include "main.h"

int main()
{
	uart_init(9600);
	KEY_Init();
	while(1)
	{
		uint8_t a=KEY_GetKey();
		if(a!=KEY_OFF)
		{
			uart_tx_bytes(2,&a,1);
			uart_tx_bytes(2,"\n",1);
		}
	}
}
