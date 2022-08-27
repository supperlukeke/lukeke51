#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int xms)
{
		while(xms--)
		{
				unsigned char i,j;
					_nop_();
				i = 2;
				j = 199;
				do
				{
					while (--j);
				} while (--i);
		}
}

void main()
{
		unsigned char LEDNum=0;
		while(1)
		{
				if(P3_1==0)
				{
						Delay(20);
						while(P3_1==0);
						Delay(20);
						LEDNum++;//0000 0001  µÚ¶þ´Î0000 0010
						P2=~LEDNum;//1111 1110			1111 1101
				}
		}
}