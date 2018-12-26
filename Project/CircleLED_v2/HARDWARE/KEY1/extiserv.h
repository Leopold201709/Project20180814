#ifndef __EXTISERV_H
#define __EXTISERV_H	

// Exti Interrupt Service

#include "sys.h"
#include "key.h"


#define LEFT	0x01
#define RIGHT	0x02

extern u8 MoveDir;
extern u8 DelayN;

void ExtiInit(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
//void EXTI8_IRQHandler(void);
void EXTI9_5_IRQHandler(void);


#endif
