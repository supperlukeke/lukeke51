#include <REGX52.H>
#include "LCD1602.H"
#include "Delay.h"

int result = 0;
void main()
{
	LCD_Init();
	while(1)
	{
			result++;
			Delay(1000);
			LCD_ShowNum(1,1,result,3);
	}
}