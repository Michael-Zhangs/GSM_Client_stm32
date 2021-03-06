#include "main.h"

int main()
{
	int i=0;
	uart_init(9600);
	for(;i<10;i++)
	{
		uart_tx_bytes(2,"nihao\n",7);
	}
}
