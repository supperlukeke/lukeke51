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
			if(P3_1==0)//����D1������ʱ��
			{
				Delay(20);//���°�ťʱ��е���ذ�������
				while(P3_1==0);//��ⰴ���İ���������ɿ���������ѭ����
				Delay(20);//��������ʱ��������ʱ����
				P2_0=~P2_0;//��λȡ������ʼ�ߵ�Ƶ1�����갴ť��ȡ��Ϊ0��������
			}
	}
}