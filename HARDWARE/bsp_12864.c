#include "bsp_12864.h"

void LCD_GPIO_Init()
{
	GPIO_InitTypeDef GPIO_InitTypeDefStructure;
	RCC_APB2PeriphClockCmd(LCD_GPIO_SID_CLK | LCD_GPIO_CLK_CLK,ENABLE);
	
	GPIO_InitTypeDefStructure.GPIO_Mode=GPIO_Mode_Out_PP;//init the sid
	GPIO_InitTypeDefStructure.GPIO_Pin=LCD_GPIO_SID_PIN;
	GPIO_InitTypeDefStructure.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(LCD_GPIO_SID_PORT, &GPIO_InitTypeDefStructure);
	
	GPIO_InitTypeDefStructure.GPIO_Mode=GPIO_Mode_Out_PP;//init the clk
	GPIO_InitTypeDefStructure.GPIO_Pin=LCD_GPIO_CLK_PIN;
	GPIO_InitTypeDefStructure.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(LCD_GPIO_CLK_PORT, &GPIO_InitTypeDefStructure);
}

/*void LCD_SendByte(char data)
{
	int i;
	LCD_SID_0;
	LCD_CLK_0;
	for(i=0;i<8;i++)
	{
		if(data&80)
			LCD_SID_1;
		else
			LCD_SID_0;
		LCD_CLK_1;
		Delayms(5);
		LCD_CLK_0;
		Delayms(5);
		LCD_SID_0;
		data<<=1;
	}
}*/

void LCD_SendByte(u8 data)
{
     u8 i; 
	  for(i = 0;i < 8;i++)
    {
        if((data << i) & 0x80)  //0x80(1000 0000)  ???????
		{
		  LCD_SID_1;  
			//SID = 1;           // ???????,????1
		}
		else
		{
			LCD_SID_0;
			//SID = 0;         // ???????,????0
		}
		/*?		
		SID =	(Dbyte << i) & 0x80;
				
		??????????
		*/
		//SCLK = 0;   //?????  ??SID??
		LCD_CLK_0;
		Delayms(1); //???????
		//SCLK = 1;    //????,????SID
		LCD_CLK_1;
	}   
}

void Lcd_WriteCmd(u8 Cmd )
{
     Delayms(1);    //???????LCD?????,??????1ms,??????????????1ms ??????????
     LCD_SendByte(WRITE_CMD);            //11111,RW(0),RS(0),0   
     LCD_SendByte(0xf0&Cmd);      //???
     LCD_SendByte(Cmd<<4);   //???(???<<)
}
 
/*! 
 *  @brief      LCD???
 *  @since      v1.0
 *  @param  Dat   ??????
 *  @author     Z??
 */
void Lcd_WriteData(u8 Dat )
{
     Delayms(1);     //???????LCD?????,??????1ms,??????????????1ms ??????????
     LCD_SendByte(WRITE_DAT);            //11111,RW(0),RS(1),0
     LCD_SendByte(0xf0&Dat);      //???
     LCD_SendByte(Dat<<4);   //???(???<<)

}


void Lcd_Init(void)
{ 
    Delayms(50);   	//??????(??>40ms)
	Lcd_WriteCmd(0x30);        //????:???????  ,??8bit???
    Delayms(1);//??>137us 
    Lcd_WriteCmd(0x0c);        //???
    Delayms(1);	//??>100us
    Lcd_WriteCmd(0x01);        //????,?????????00H
    Delayms(30);	//??>10ms
	Lcd_WriteCmd(0x06);        //??????+1,?????
}


/* ????RAM??    4?8? */
uint8_t LCD_addr[4][8]={
	{0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87},  		//???
	{0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97},		//???
	{0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F},		//???
	{0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F}		//???
	};
 
/*! 
 *  @brief      ???????
 *  @since      v1.0
 *  @param  x: row(0~3)
 *  @param  y: line(0~7) 
 *  @param 	str: ?????????
 *  @author     Z??
 */
void LCD_Display_Words(uint8_t x,uint8_t y,uint8_t*str)
{ 
	Lcd_WriteCmd(LCD_addr[x][y]); //???????
	while(*str>0)
    { 
      Lcd_WriteData(*str);    //???
      str++;     
    }
}

void LCD_Clear(void)
	{
		Lcd_WriteCmd(0x01);			//????
		Delayms(2);				//???????????1.6ms?
	}
