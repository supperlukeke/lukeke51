#include <REGX52.H>

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//每个数字对应的段码（0-9）

void Nixie(unsigned char Location,Number)
{
	switch(Location)//数字位数（第1-8位）
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//实际是LED8
		case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED7
		case 3:P2_4=1;P2_3=0;P2_2=1;break;//101对应十进制数5，Y5，LED6是第三位数
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;//138译码器上的P2是相反的，按CBA排数
	}
	P0=NixieTable[Number];//要显示的数字
}

void main()
{
	Nixie(5,4);//调用函数
	while(1)
	{
		
	}
}