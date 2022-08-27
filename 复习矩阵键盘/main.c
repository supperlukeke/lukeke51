#include <REGX52.H>
#include "LCD1602.H"
#include "MatrixKey.H"

unsigned char KeyNum;
unsigned int count=0,Password = 0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password");
		while(1)
		{
				KeyNum = MatrixKey();
				if(KeyNum)
				{
						if(KeyNum<=10)
						{
								if(count<4)
								{
										Password *= 10;
										Password += KeyNum;
										count++;
								}
								LCD_ShowNum(2,1,Password,4);
						}
						if(KeyNum==11)
						{
								if(Password==4567)
								{
										count=0;
										Password=0;
										LCD_ShowNum(2,1,Password,4);
										LCD_ShowString(2,14," OK");
								}
								else
								{
										count=0;
										Password=0;
										LCD_ShowNum(2,1,Password,4);
										LCD_ShowString(2,14,"ERR");
								}
						}
						if(KeyNum==12)
						{
										count=0;
										Password=0;
										LCD_ShowNum(2,1,Password,4);
						}
				}
		}
			
}