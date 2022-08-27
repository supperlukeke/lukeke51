#include <REGX52.H>
#include "INTRINS.H"

//蜂鸣器端口：
sbit Buzzer=P2^5;
unsigned int i;

/**
  *  @brief    蜂鸣器专用延时函数，延时500ms
  *  @param		 无
  *  @retval	 无
  */

void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

/**
  *  @brief    蜂鸣器发声
  *  @param		 ms		发声时长
  *  @retval	 无
  */

void Buzzer_Time(unsigned int ms)
{
	for(i=0;i<ms*2;i++)				//延时只有500us，2次延时才是1秒
	{
		Buzzer=!Buzzer;
		Buzzer_Delay500us();
	}
}