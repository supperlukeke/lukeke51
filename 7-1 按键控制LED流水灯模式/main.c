#include <REGX52.H>
#include "Timer0.h"
#include "key.h"
#include <INTRINS.H>
unsigned char KeyNum,LEDMode;
void main()
{
	P2=0xFE;
	Timer0Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LEDMode=1;
			}
			if(KeyNum==2)
			{
				LEDMode=0;
			}
		}
	}
}

void Timer0_Routine()		interrupt 1
{
	static unsigned int T0Count;	//出函数之后T0Count=0的数据需要保留,一次中断出去后count也得保留当前值
	TL0=0x66;
	TH0=0xFC;
	T0Count++;
	if(T0Count>=500)//执行500次中断，T0Count加到500后才可进入以下语句
	{
		T0Count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}