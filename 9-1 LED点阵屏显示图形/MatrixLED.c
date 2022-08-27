#include <REGX52.H>
#include "Delay.h"
#define MATRIX_LED_PORT P0

sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;

/**
  *  @brief     74HC595写入一个字节
  *  @param			Byte要写入的字节
  *  @retval		无
  */

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

/**
  *  @brief     点阵屏初始化
  *  @param			无
  *  @retval		无
  */

void MatrixLED_Init()
{
	SCK=0;
	RCK=0;
}

/**
  *  @brief     LED点阵屏显示一列数据
  *  @param			Column 要选择的列，范围：0~7，0在最左边
*	 @param			  Date 选择列要显示的数据，用16进制，高位在上，1为亮，0为灭
  *  @retval	  无
  */

void MatrixLED_ShowColumn(unsigned char Column,Date)
{
	_74HC595_WriteByte(Date);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}