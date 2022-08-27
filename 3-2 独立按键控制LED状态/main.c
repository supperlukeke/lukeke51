#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
			_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	while(1)
	{
			if(P3_1==0)//按下D1按键的时候
			{
				Delay(20);//按下按钮时机械开关按键抖动
				while(P3_1==0);//检测按键的按下情况，松开按键跳出循环。
				Delay(20);//按键抖动时间利用延时忽略
				P2_0=~P2_0;//按位取反，初始高电频1，按完按钮后取反为0，就亮了
			}
	}
}