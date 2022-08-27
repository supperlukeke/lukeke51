#include <REGX52.h>
#include <INTRINS.h>

void Delay1ms(unsigned int xms)		//@11.0592MHz
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
				P2=0xFE;
				Delay1ms(1000);
				P2=0xFD;
				Delay1ms(1000);
				P2=0xFB;
				Delay1ms(1000);
				P2=0xF7;
				Delay1ms(1000);
				P2=0xEF;
				Delay1ms(1000);
				P2=0xDF;
				Delay1ms(1000);
				P2=0xBF;
				Delay1ms(1000);
				P2=0x7F;
				Delay1ms(1000);
		}
}