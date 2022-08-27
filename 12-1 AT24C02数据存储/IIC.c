#include <REGX52.H>

sbit IIC_SCL = P2^1;
sbit IIC_SDA = P2^0;

/**
  *  @brief    I2C开始
  *  @param		无
  *  @retval	无
  */

void IIC_Start(void)
{
	IIC_SDA = 1;
	IIC_SCL = 1;
	IIC_SDA = 0;
	IIC_SCL = 0;

}
/**
  *  @brief    I2C停止ֹ
  *  @param		无
  *  @retval	无
  */

void IIC_Stop(void)
{
	IIC_SDA = 0;
	IIC_SCL = 1;
	IIC_SDA = 1;
}

/**
  *  @brief    I2C发送一个字节
  *  @param		Byte 要发送的字节
  *  @retval	无
  */

void IIC_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		IIC_SDA = Byte&(0x80>>i);
		IIC_SCL = 1;
		IIC_SCL = 0;	
	}
}

/**
  *  @brief    I2C接收一个字节
  *  @param		无
  *  @retval	接收到的一个字节数据
  */

unsigned char IIC_ReceiveByte(void)
{
	unsigned char Byte = 0x00;
	IIC_SDA = 1;
	for(i=0;i<8;i++)
	{
		IIC_SCL = 1;
		if(IIC_SDA){Byte |= (0x80>>i)};		//��ֱ����Byte |= (0x80>>i)
		IIC_SCL = 0;
	}
	return Byte;
}

/**
  *  @brief    I2C发送应答
  *  @param	   AckBit 应答位，0为应答，1为非应答
  *  @retval   无
  */

void IIC_SendAck(bit AckBit)
{
	IIC_SDA = AckBit;
	IIC_SCL = 1;
	IIC_SCL = 0;
}

/**
  *  @brief    I2C接收应答
  *  @param	   无
  *  @retval   接收到的应答位
  */

unsigned char IIC_ReceiveAck()
{
	unsigned char AckBit;
	IIC_SDA = 1;
	IIC_SCL = 1;
	AckBit = IIC_SDA;
	IIC_SCL = 0;
	return AckBit;
}
