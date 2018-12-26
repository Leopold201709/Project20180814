#ifndef __LED_H
#define __LED_H	 

#include "sys.h"


#define LED0		PBout(7)		//LED0 -> D8
#define LED1		PBout(6)		//LED1 -> D9
#define LED2		PBout(5)		//LED2 -> D10
#define LED3		PDout(2)		//LED3 -> D11
#define LED4		PCout(12)		//LED4 -> D6
#define LED5		PCout(11)		//LED5 -> D7
#define LED6		PAout(5)		//LED6 -> D0
#define LED7		PAout(4)		//LED7 -> D1
#define LED8		PAout(3)		//LED8 -> D2
#define LED9		PAout(2)		//LED9 -> D3
#define LED10		PAout(1)		//LED10 -> D4
#define LED11		PAout(0)		//LED11 -> D5



void LEDInit(void);
void LEDCtrl(u16 CtrlData);

#endif
