#include "main.h"

int main()
{
	Delayms(1000);
	uart_init(9600);
	KEY_Init();
	LCD_GPIO_Init();
	Lcd_Init();
	PRINTER_Init();
	while(1)
	{
		UI_hander();
	}
}
