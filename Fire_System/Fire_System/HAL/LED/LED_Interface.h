/*
 * LED_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#define PORT_A      0
#define PORT_B      1
#define PORT_C      2
#define PORT_D      3

void ON_LED(u8 PORT ,u8 PIN);
void OFF_LED(u8 PORT ,u8 PIN);

#endif /* HAL_LED_LED_INTERFACE_H_ */
