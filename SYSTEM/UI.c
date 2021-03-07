#include "UI.h"

void UI_hander()
{
	uint8_t key;
	while(1)
	{
		uint8_t pos=0;
		UI_PrintMenu();
		LCD_Display_Words(pos,7,"*");
		while(1)
		{
			key=KEY_GetKey();
			if(key!=KEY_OFF)
			{
				if(key=='B')
				{
					if(pos<3)
					{
						LCD_Display_Words(pos,7," ");
						pos++;
						LCD_Display_Words(pos,7,"*");
					}
				}
				if(key=='A')
				{
					if(pos>0)
					{
						LCD_Display_Words(pos,7," ");
						pos--;
						LCD_Display_Words(pos,7,"*");
					}
				}
				if(key=='D')
				{
					switch(pos)
					{
						case 0:
							UI_SendMsg_hander();
							break;
						case 1:
							UI_ReceiveMsg_hander();
							break;
						case 2:
							UI_Net_hander();
							break;
						case 3:
							UI_SelfCheck_hander();
							break;
					}
					LCD_Clear();
					UI_PrintMenu();
					LCD_Display_Words(pos,7,"*");
				}
			}
		}
	}
}

void UI_PrintMenu()
{
	LCD_Clear();
	LCD_Display_Words(0,0,"收短信");
	LCD_Display_Words(1,0,"发短信");
	LCD_Display_Words(2,0,"网络");
	LCD_Display_Words(3,0,"自检");
}

void UI_SendMsg_hander()
{
	uint8_t num[20],pos=0,tmp[2];
	PRINTER_SetSize(PRINTER_SIZE_0);
	PRINTER_SetPos(PRINTER_POS_MID);
	PRINTER_Print("abcdefghijklmnopqrstuvwxyz\n");
	PRINTER_Print("01234567890123456789012345\n\n\n\n");
	LCD_Clear();
	LCD_Display_Words(0,0,"请输入号码:");
	while(1)
	{
		int flag=1;
		uint8_t a;
		do
		{
			a=KEY_GetKey();
		}while(a==KEY_OFF);
		switch(a)
		{
			case 'A':
				if(pos>0)
					LCD_Display_Words(1,pos," ");
					pos--;
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				flag=0;
				break;
			default:
				num[pos]=a;
				tmp[0]=a;
				tmp[1]='\0';
				pos++;
				LCD_Display_Words(1,pos,tmp);
		}
		if(flag==0)
			break;
	}
}

void UI_ReceiveMsg_hander()
{

}

void UI_Net_hander()
{

}

void UI_SelfCheck_hander()
{

}
