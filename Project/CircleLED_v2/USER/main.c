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
    
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LEDInit();		  		
	KEYInit();         	//��ʼ���밴�����ӵ�Ӳ���ӿ�
	ExtiInit();		 	//�ⲿ�жϳ�ʼ��
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
