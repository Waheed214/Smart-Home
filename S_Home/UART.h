/*
 * UART.h
 *
 *  Created on: 4 Dec 2020
 *      Author: wahee
 */

#ifndef UART_H_
#define UART_H_
#include "Dio_Int.h"
#include "util/delay.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#define UDR   *((volatile u8*)0x2C)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x20)
#define UCSRA *((volatile u8*)0x2B)
void UART_Init(void);
void UART_SendByte(u8 Byte);
u8 UART_RecieveByte(void);

#endif /* UART_H_ */
