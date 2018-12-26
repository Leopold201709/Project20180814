
#include "led.h"


void LEDInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PE端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2
									| GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;				 //D0~D5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
//	GPIO_ResetBits(GPIOA,GPIO_Pin_5);						 //PB.5 输出高

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	    		 //D8~D10
	GPIO_Init(GPIOB, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;	    		 //D6~D7
	GPIO_Init(GPIOC, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //D11
	GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
}


void LEDCtrl(u16 CtrlData)
{
	LED0 = CtrlData & 0x0001;
	LED1 = (CtrlData >> 1) & 0x0001;
	LED2 = (CtrlData >> 2) & 0x0001;
	LED3 = (CtrlData >> 3) & 0x0001;
	LED4 = (CtrlData >> 4) & 0x0001;
	LED5 = (CtrlData >> 5) & 0x0001;
	LED6 = (CtrlData >> 6) & 0x0001;
	LED7 = (CtrlData >> 7) & 0x0001;
	LED8 = (CtrlData >> 8) & 0x0001;
	LED9 = (CtrlData >> 9) & 0x0001;
	LED10 = (CtrlData >> 10) & 0x0001;
	LED11 = (CtrlData >> 11) & 0x0001;
}