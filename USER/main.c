#include "main.h"

int main()
{
	Delayms(1000);
	uart_init(9600);
	KEY_Init();
	LCD_GPIO_Init();
	Lcd_Init();
	LCD_Display_Words(0,0,"Hello");
	LCD_Display_Words(1,0,"Hello");
	LCD_Display_Words(2,0,"Hello");
	PRINTER_Init();
	PRINTER_SetSize(PRINTER_SIZE_1);
	PRINTER_SetPos(PRINTER_POS_MID);
	while(1)
	{
		uint8_t a=KEY_GetKey();
		if(a!=KEY_OFF)
		{
			PRINTER_Print("ÄãºÃ\n");
			LCD_Display_Words(3,0,"ÄãºÃ");
		}
	}
}
