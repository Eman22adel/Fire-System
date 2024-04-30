/*
 * KEYPAD_Interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: eman adel
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_



#define  NO_KEY   'T'

void KEYPAD_Init(void);

u8 KEYPAD_GetKey(void);


#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
