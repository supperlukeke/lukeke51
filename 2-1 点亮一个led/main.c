#include <REGX52.H>
#include <INTRINS.H>//调用_nop_时必要的头文件

void Delay500ms()		//@11.0592MHz 单片机晶振上边有标注
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
			P2=0x55;//0101 0101原二进制
			Delay500ms();	//如果不加这个，就会看起来常长亮，但实际上是闪烁的，
										//不过单片机是MHz，也就是每秒百万次。所以闪烁太快人无法察觉
			P2=0xAA;//1010 1010
			Delay500ms();
	}
}