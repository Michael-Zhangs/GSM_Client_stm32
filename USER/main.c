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
			unsigned int a=uni2gb(0x4f60);
			unsigned int b=uni2gb(0x597d);
			uint8_t dat[4];
			LCD_Display_Words(3,0,"ÄãºÃ");
			dat[0]=(b>>8)&0x00ff;
			dat[1]=(b)&0x00ff;
			dat[2]='\n';
			dat[3]='\0';
			PRINTER_Print(dat);
		}
	}
}
