/*
 * Interrupt_Interface.h
 *
 *  Created on: Sep 7, 2023
 *      Author: eman adel
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_

#define   NULLPTR  ((void*)0)

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;

void EXI_Init(void);

void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);

void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));

#endif /* MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_ */
