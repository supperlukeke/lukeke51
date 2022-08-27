#include <REGX52.H>
#include "DELAY.H"

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;//给P1_1-7赋1
	P1_3=0;//扫描列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=1;}//扫描行
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=5;}//扫描行
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=9;}//扫描行
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=13;}//扫描行
	
	P1=0xFF;
	P1_2=0;//扫描列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=14;}
	
	P1=0xFF;
	P1_1=0;//扫描列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=15;}
	
	P1=0xFF;
	P1_0=0;//扫描列
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=16;}
	return KeyNumber;
}