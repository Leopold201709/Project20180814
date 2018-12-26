
#include "extiserv.h"
#include "userusb.h"

u8 MoveDir = LEFT;
u8 DelayN = 1;

void ExtiInit(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	KEYInit();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟
	
	//GPIOC.2 (KeyLeft)中断线以及中断初始化配置   下降沿触发
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//KEY2
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
	
	//GPIOC.3 (KeyRight) 中断线以及中断初始化配置 下降沿触发 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource3);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;
  	EXTI_Init(&EXTI_InitStructure);	  	
	
	//GPIOB.8 (KeyDown) 中断线以及中断初始化配置 下降沿触发 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource8);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
  	EXTI_Init(&EXTI_InitStructure);	  	
	
	//GPIOB.9 (KeyUp) 中断线以及中断初始化配置 下降沿触发 
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource9);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  	EXTI_Init(&EXTI_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			//使能按键KEY2所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键KEY1所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键KEY0所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}

//外部中断2服务程序  Left
void EXTI2_IRQHandler(void)
{
	delay_ms(20);//消抖
	if(KeyLeft == 1)	 	 //WK_UP按键
	{				 
		MoveDir = LEFT;	
        UserUSB_SendByte(MoveDir);
	}
	EXTI_ClearITPendingBit(EXTI_Line2); //清除LINE0上的中断标志位  
}

//Right
void EXTI3_IRQHandler(void)
{
	delay_ms(20);
	if(KeyRight == 1)	  //按键KEY2
	{
		MoveDir = RIGHT;
        UserUSB_SendByte(MoveDir);
	}
	EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE2上的中断标志位  
}


//void EXTI8_IRQHandler(void)
//{
//	delay_ms(10);//消抖
//	if(KeyDown == 1)	 //按键KEY1
//	{				 
//		if(DelayN > 1) DelayN = DelayN - 1;
//		else DelayN = 1;
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line8);  //清除LINE3上的中断标志位  
//}

//KeyUp : Delay Increment
//KeyDown : Delay Decrement
void EXTI9_5_IRQHandler(void)
{
	
    if(EXTI_GetITStatus(EXTI_Line9) != RESET)
    {
        delay_ms(20);//消抖
        if(KeyUp == 1)	 
        {				 
            DelayN = DelayN + 1;
            UserUSB_SendByte(DelayN);
        }
        EXTI_ClearITPendingBit(EXTI_Line9);  //清除LINE3上的中断标志位  
    }
    else if(EXTI_GetITStatus(EXTI_Line8) != RESET)
    {
        delay_ms(20);//消抖
        if(KeyDown == 1)	 
        {				 
            if(DelayN > 1) DelayN = DelayN - 1;
            else DelayN = 1;
            UserUSB_SendByte(DelayN);
        }
        EXTI_ClearITPendingBit(EXTI_Line8);  //清除LINE3上的中断标志位  
    }
}

