#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "extiserv.h"
#include "userusb.h"
// void CycleLED(void);


 int main(void)
 {		
    u8 i;
    u8 TmpDir, TmpDelayN;
    u16 LEDDisp = 0x01;
    TmpDir = MoveDir;
    TmpDelayN = DelayN;
    
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LEDInit();		  		
	KEYInit();         	//初始化与按键连接的硬件接口
	ExtiInit();		 	//外部中断初始化
    UserUSB_Init();

	while(1)
	{	    
		if(MoveDir == LEFT)
        {
            LEDDisp = (((LEDDisp & 0x0001) << 12) | LEDDisp) >> 1;
            LEDCtrl(LEDDisp);
        }
        else if(MoveDir == RIGHT)
        {
            LEDDisp = ((LEDDisp & 0x0800) >> 11) | (LEDDisp << 1);
            LEDCtrl(LEDDisp);
        }
        for( i = 0; i < DelayN; i++)
        {
            delay_ms(500); 
        }
//        UserUSB_SendByte(KEYScan(0));
	}
 }
