/*
 * UART.h
 *
 *  Created on: Sep 8, 2023
 *      Author: eman adel
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

void UART_Init(void);

void UART_Send(u8 data);
u8 UART_Receive(void);

#endif /* MCAL_UART_UART_H_ */
