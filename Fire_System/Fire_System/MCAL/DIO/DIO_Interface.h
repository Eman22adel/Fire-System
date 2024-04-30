/*
 * DIO_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#ifndef MCAL_DIO_DIO_INTERFACE_C_
#define MCAL_DIO_DIO_INTERFACE_C_

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	LOW=0,
	HIGH,
}DIO_PinVoltage_type;

typedef enum{
	PINA_0 =0,
	PINA_1 =1,
	PINA_2,
	PINA_3,
	PINA_4,
	PINA_5,
	PINA_6,
	PINA_7,
	PINB_0,
	PINB_1,
	PINB_2,
	PINB_3,
	PINB_4,
	PINB_5,
	PINB_6,
	PINB_7,
	PINC_0,
	PINC_1,
	PINC_2,
	PINC_3,
	PINC_4,
	PINC_5,
	PINC_6,
	PINC_7,
	PIND_0,
	PIND_1,
	PIND_2,
	PIND_3,
	PIND_4,
	PIND_5,
	PIND_6,
	PIND_7,
	TOTAL_PINS
}DIO_Pin_type;




/* INIT CALL BEFORE WHILE */
void DIO_Init(void);

/*FUNCTION EFFECT ON ONE PIN */
void DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt); /*write on one pin*/
DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_type pin); /*read on one pin*/
void DIO_TogglePin(DIO_Pin_type pin);  /*togle on one pin*/


/*FUNCTION EFFECT ON ONE PIN */
void DIO_WritePort(DIO_Port_type port,u8 value);
u8 DIO_ReadPort(DIO_Port_type port);


/*FUNCTION USEING TO READ PIN IS INFREE OR INPULL*/
DIO_PinStatus_type DIO_ReadStatus_CfgPin(DIO_Pin_type pin);
#endif /* MCAL_DIO_DIO_INTERFACE_C_ */
