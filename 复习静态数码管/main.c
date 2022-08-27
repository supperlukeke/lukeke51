#include <reg52.h>
#include "delay.h"

unsigned int count;      //次数标识
unsigned int angle=5;         //角度标识
sbit pwm =P2^7 ;          //PWM信号输出

/*定时器初始化函数*/
void Timer0_Init(void)		//100微秒@11.0592MHz
{
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
}

/*串口初始化函数*/
void Uart_Init(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	ES = 1;
	EA = 1;
}

/*串口发送一字节函数*/
void Uart_SendData(unsigned char dat )
{
	SBUF = dat;
	while(TI == 0);
	TI = 0;
}

/*串口发送字符串函数*/
void Uart_SendString(char *s)
{
	while (*s)              
	{
		Uart_SendData(*s++);
	}
}

/*程序入口*/
void main(void)
{
	//angle与对应角度关系
	//4   5   6   ...... 19  20
	//0   11  22  ...... 166 177
	Uart_Init();
	Timer0_Init();
	Uart_SendString("舵机正在旋转。\r\n");
	for(angle=4;angle<21;angle++)//从0到177度，步进11度
	{
		Delay(2);
	}
	Delay(2000);
	for(angle=21;angle>4;angle--)//从177到0度，步进11度
	{
		Delay(2);
	}
	Uart_SendString("舵机正在往复旋转。\r\n");
	while(1)
	{ 
		            
	}
}

/*串口中断服务函数*/
void Uart_Isr() interrupt 4
{
    if (RI)
    {
        RI = 0;  
	}
}


/*定时器中断服务函数*/
void Timer0_Isr() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	if(count< angle)              //判断次数是否小于角度标识
      pwm=1;                  //确实小于，PWM输出高电平
    else
      pwm=0;                  //大于则输出低电平
    count=(count+1);          //0.1ms次数加1
    count=count%160;     //保持周期为20ms，普通51单片机定时100us有误差，经示波器测量约为50Hz
}

