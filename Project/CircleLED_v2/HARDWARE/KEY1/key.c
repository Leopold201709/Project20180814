
#include "key.h"


void KEYInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9;	//DOWN : UP
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //设置成上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOE2,3,4
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;	    		 //LEFT : RIGHT
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}




//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
u8 KEYScan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up && ((KeyUp == 1) || (KeyDown == 1) || (KeyLeft == 1) || (KeyRight == 1)))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KeyUp == 1)return KeyUpRres;
		else if(KeyDown == 1)return KeyDownRres;
		else if(KeyLeft == 1)return KeyLeftRres;
		else if(KeyRight == 1)return KeyRightRres;
	}else if((KeyUp==0) && (KeyDown==0) && (KeyLeft==0) && (KeyRight==0)) key_up=1; 	    
 	return 0;// 无按键按下
}
