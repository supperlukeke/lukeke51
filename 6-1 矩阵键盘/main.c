#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "MatrixKey.h"

unsigned char KeyNum;

void main()
{
	LCD_Init();//初始化
	LCD_ShowString(1,1,"InputNumber");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			LCD_ShowNum(2,1,KeyNum,2);
		}
	}
}