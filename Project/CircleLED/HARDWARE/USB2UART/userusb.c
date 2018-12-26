
#include "userusb.h"





void UserUSB_Init(void)
{
	USB_Port_Set(0); 	//USB先断开
	delay_ms(700);
	USB_Port_Set(1);	//USB再次连接
 	Set_USBClock();   
 	USB_Interrupts_Config();    
 	USB_Init();
    delay_ms(800);
}

u8 UserUSB_LinkStateCheck(void)
{
	u8 usbstatus=0;
//    if(usbstatus != bDeviceState)
    usbstatus=bDeviceState;		//记录新的状态
	if(usbstatus==CONFIGURED) 
		return 0;				//提示USB连接成功
	else
		return 1;				//提示USB断开
}

u8 UserUSB_RecDate(void)
{
	u16 RxLen;
	
	if(USB_USART_RX_STA&0x8000)
	{
		RxLen=USB_USART_RX_STA&0x3FFF;	//得到此次接收到的数据长度
		USB_USART_RX_STA=0;
		
	}
	return RxLen;					//返回接收长度					
}

void UserUSB_SendByte(u8 TxDat)
{
	USB_USART_SendData(TxDat);			//以字节方式,发送给USB
}