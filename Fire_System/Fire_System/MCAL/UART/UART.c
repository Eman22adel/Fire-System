/*
 * UART.c
 *
 *  Created on: Sep 8, 2023
 *      Author: eman adel
 */
/*
 * DIO.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "avr/io.h"
#include "UART.h"


void UART_Init(void)
{
	/* set baud rate 9600*/
	UBRRL=51;
	/* NORMAL SPEED*/
	CLR_BIT(UCSRA,U2X);
	/*frame  no parity 1 stop bit  8 data*/

	/* enable*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}


void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;

}

u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

u8 UART_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	return 0;
}

