/*
 * MOTOR_Interface.h
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#ifndef HAL_MOTOR_INTERFACE_H_
#define HAL_MOTOR_INTERFACE_H_

#define NUMBER_MOTORS 4
#define MOTOR_PIN_NUMBERS 3


#define IN1 0
#define IN2 1

DIO_Pin_type MotorPinsArray[NUMBER_MOTORS][MOTOR_PIN_NUMBERS]={
				/* IN1    IN2     EN  */
	/* motor 1*/{ M1_IN1,M1_IN2,M1_EN},
	/* motor 2*/{ M2_IN1,M2_IN2,M2_EN},
	/* motor 3*/{ M3_IN1,M3_IN2,M3_EN},
	/* motor 4*/{ M4_IN1,M4_IN2,M4_EN}
};

void MOTOR_Init(void);

void MOTOR_Stop(u8 motor);

void MOTOR_CW(u8 motor);

void MOTOR_CCW(u8 motor);

#endif /* HAL_MOTOR_INTERFACE_H_ */
