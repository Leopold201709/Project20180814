
#ifndef __KEY_H
#define __KEY_H	 

#include "sys.h"
#include "delay.h"


#define KeyUp  				GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键UP
#define KeyDown  			GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//读取按键DOWN
#define KeyLeft  			GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)//读取按键LEFT
#define KeyRight   			GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)//读取按键RIGHT


#define KeyUpRres 			1	//KeyUp按下
#define KeyDownRres			2	//KeyDown按下
#define KeyLeftRres			3	//KeyLeft按下
#define KeyRightRres   		4	//KeyRight按下


void KEYInit(void);
u8 KEYScan(u8 mode);

#endif
