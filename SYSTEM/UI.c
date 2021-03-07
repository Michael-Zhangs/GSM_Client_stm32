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
	LCD_Display_Words(0,0,"·¢¶ÌÐÅ");
	LCD_Display_Words(1,0,"ÊÕ¶ÌÐÅ");
	LCD_Display_Words(2,0,"ÍøÂç");
	LCD_Display_Words(3,0,"×Ô¼ì");
}

void UI_SendMsg_hander()
{
	uint8_t num[20]={0},pos=0,datBuf[300]={0},bit_flag=0,bit_tmp=0;
	PRINTER_SetSize(PRINTER_SIZE_0);
	PRINTER_SetPos(PRINTER_POS_MID);
	PRINTER_Print("abcdefghijklmnopqrstuvwxyz\n");
	PRINTER_Print("01234567890123456789012345\n");
	PRINTER_Print("0         1         2     \n\n\n\n");
	LCD_Clear();
	LCD_Display_Words(0,0,"ÇëÊäÈëºÅÂë:");
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
				{
					num[pos]='\0';
					pos--;
					LCD_Clear();
					LCD_Display_Words(0,0,"ÇëÊäÈëºÅÂë:");
					LCD_Display_Words(1,0,num);
				}
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
				pos++;
				LCD_Clear();
				LCD_Display_Words(0,0,"ÇëÊäÈëºÅÂë:");
				LCD_Display_Words(1,0,num);
		}
		if(flag==0)
			break;
	}
	pos=0;
	LCD_Clear();
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
				{
					LCD_Clear();
					datBuf[pos]='\0';
					LCD_Display_Words(0,0,datBuf);
					pos--;
				}
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				flag=0;
				break;
			default:
				if(bit_flag==0)//If have not written a litter
				{
					uint8_t wdtmp[2];
					wdtmp[0]=a;
					wdtmp[1]='\0';
					LCD_Display_Words(3,0,wdtmp);
					bit_tmp+=(a-'0')*10;
					bit_flag=1;//Mark the status
				}
				else//If have
				{
					bit_tmp+=(a-'0');
					datBuf[pos]=bit_tmp+'a';
					datBuf[pos+1]='\0';
					pos++;
					bit_flag=0;//turn into 0
					bit_tmp=0;
					LCD_Clear();
					LCD_Display_Words(0,0,datBuf);
				}
		}
		if(flag==0)
			break;
	}
	GSM_SendMsg(num,datBuf);
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
