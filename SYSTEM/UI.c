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
				}
			}
		}
	}
}

void UI_PrintMenu()
{
	LCD_Clear();
	LCD_Display_Words(0,0,"�ն���");
	LCD_Display_Words(1,0,"������");
	LCD_Display_Words(2,0,"����");
	LCD_Display_Words(3,0,"�Լ�");
}

void UI_SendMsg_hander()
{

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
