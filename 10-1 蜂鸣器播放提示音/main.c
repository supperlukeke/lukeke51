#include <REGX52.H>
#include "key.h"
#include "Nixie.h"
#include "Buzzer.h"



unsigned char KeyNum;

void main()
{
	Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			Buzzer_Time(1000);
			Nixie(1,KeyNum);
		}
	}
}