#include <REGX52.H>

unsigned char NixieTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//ÿ�����ֶ�Ӧ�Ķ��루0-9��

void Nixie(unsigned char Location,Number)
{
	switch(Location)//����λ������1-8λ��
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//ʵ����LED8
		case 2:P2_4=1;P2_3=1;P2_2=0;break;//LED7
		case 3:P2_4=1;P2_3=0;P2_2=1;break;//101��Ӧʮ������5��Y5��LED6�ǵ���λ��
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;//138�������ϵ�P2���෴�ģ���CBA����
	}
	P0=NixieTable[Number];//Ҫ��ʾ������
}

void main()
{
	Nixie(5,4);//���ú���
	while(1)
	{
		
	}
}