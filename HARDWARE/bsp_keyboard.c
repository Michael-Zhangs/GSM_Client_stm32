#include "bsp_keyboard.h"

uint16_t KEY_Index[2][4]={
	{GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_10,GPIO_Pin_11},
	{GPIO_Pin_12,GPIO_Pin_13,GPIO_Pin_14,GPIO_Pin_15}
};

uint8_t KEY_Que[4][4]={
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

void KEY_Init()
{
	int i;
	GPIO_InitTypeDef GPIO_InitTypeDefStructure;
	RCC_APB2PeriphClockCmd(KEY_GPIO_CLK,ENABLE);
	for(i=0;i<4;i++)
	{
		GPIO_InitTypeDefStructure.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIO_InitTypeDefStructure.GPIO_Pin=KEY_Index[0][i];
		GPIO_InitTypeDefStructure.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(KEY_GPIO_PORT, &GPIO_InitTypeDefStructure);
		GPIO_ResetBits(KEY_GPIO_PORT, KEY_Index[0][i]);
	}
	for(i=0;i<4;i++)
	{
		GPIO_InitTypeDefStructure.GPIO_Mode=GPIO_Mode_IPD;//PULL DOWN
		GPIO_InitTypeDefStructure.GPIO_Pin=KEY_Index[1][i];
		GPIO_InitTypeDefStructure.GPIO_Speed=GPIO_Speed_2MHz;
		GPIO_Init(KEY_GPIO_PORT, &GPIO_InitTypeDefStructure);
		GPIO_ResetBits(KEY_GPIO_PORT,KEY_Index[1][i]);
	}
}

uint8_t KEY_GetKey()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		GPIO_SetBits(KEY_GPIO_PORT, KEY_Index[0][i]);
		for(j=0;j<4;j++)
		{
			if(GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_Index[1][j])==KEY_ON)
			{
				Delayms(5);
				while(GPIO_ReadInputDataBit(KEY_GPIO_PORT, KEY_Index[1][j])==KEY_ON);
				GPIO_ResetBits(KEY_GPIO_PORT, KEY_Index[0][i]);
				Delayms(10);
				return KEY_Que[3-i][3-j];
			}
		}
		GPIO_ResetBits(KEY_GPIO_PORT, KEY_Index[0][i]);
	}
	return KEY_OFF; 
}
