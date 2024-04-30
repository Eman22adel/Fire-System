/*
 * TIMER.h
 *
 *  Created on: Sep 8, 2023
 *      Author: eman adel
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_


void TIMER0_voidTimer0OVFInit(void);
void TIMER0_voidTimer0CTCInit(void);


void TIMER0_voidTimer0OVFSetCallBack (void (*Copy_PFvoidTimer0OVF) (void));
void TIMER0_voidTimer0CTCSetCallBack (void (*Copy_PFvoidTimer0CTC) (void));

#endif /* MCAL_TIMER_TIMER_H_ */
