#include <REGX52.H>
#include <INTRINS.H>//����_nop_ʱ��Ҫ��ͷ�ļ�

void Delay500ms()		//@11.0592MHz ��Ƭ�������ϱ��б�ע
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
			P2=0x55;//0101 0101ԭ������
			Delay500ms();	//�������������ͻῴ��������������ʵ��������˸�ģ�
										//������Ƭ����MHz��Ҳ����ÿ�����Ρ�������˸̫�����޷����
			P2=0xAA;//1010 1010
			Delay500ms();
	}
}