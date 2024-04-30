/*
 * BUTTON_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#ifndef HAL_BUTTON_BUTTON_INTERFACE_H_
#define HAL_BUTTON_BUTTON_INTERFACE_H_

typedef enum{
	NOTPRESSED=0,
	PRESSED=1
}Button_Status;


Button_Status Button_IsPressed(DIO_Pin_type pin);

#endif /* HAL_BUTTON_BUTTON_INTERFACE_H_ */
