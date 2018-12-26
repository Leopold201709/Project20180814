
#ifndef USERUSB_H
#define USERUSB_H

#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "usb_lib.h"
#include "hw_config.h"
#include "usb_pwr.h"




void UserUSB_Init(void); 
u8 UserUSB_LinkStateCheck(void);
u8 UserUSB_RecDate(void);
void UserUSB_SendByte(u8 TxDat);




#endif
