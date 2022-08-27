#include <REGX52.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;

void main()
{
	LCD_Init();//初始化
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)	//如果s1~s10按下，输入密码
			{
				if(Count<4)		//如果输入次数小于4	
				{
					Password*=10;						//密码左移一位
					Password+=KeyNum%10;		//获取一位密码
					Count++;								//计次
				}
				LCD_ShowNum(2,1,Password,4);		//更新显示
			}
			if(KeyNum==11)	//如果s11按键按下
			{
				if(Password==5438)	//如果密码等于正确密码
				{
					LCD_ShowString(1,14,"OK ");			//显示OK
					Password=0;										//密码清零
					Count=0;												//计次清零
					LCD_ShowNum(2,1,Password,4);		//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"ERR");			//显示ERR
					Password=0;										//密码清零
					Count=0;												//计次清零
					LCD_ShowNum(2,1,Password,4);		//更新显示
				}
			}
			if(KeyNum==12)	//如果s12按键按下
			{
				Password=0;										//密码清零
				Count=0;												//计次清零
				LCD_ShowNum(2,1,Password,4);		//更新显示
			}
		}
	}
}