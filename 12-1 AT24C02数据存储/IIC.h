#ifndef __IIC_H__
#define __IIC_H__

void IIC_Start(void);
void IIC_Stop(void);
void IIC_SendByte(unsigned char Byte);
unsigned char IIC_ReceiveByte(void);
void IIC_SendAck(bit AckBit);
unsigned char IIC_ReceiveAck(void);

#endif
