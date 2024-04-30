/*
 * MOTOR.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "MOTOR_CFG.h"
#include "MOTOR_Interface.h"

void MOTOR_Init(void){

}

void MOTOR_Stop(u8 motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],LOW);
	DIO_WritePin(MotorPinsArray[motor][IN2],LOW);
}

void MOTOR_CW(u8 motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],LOW);
	DIO_WritePin(MotorPinsArray[motor][IN2],HIGH);
}

void MOTOR_CCW(u8 motor)
{
	DIO_WritePin(MotorPinsArray[motor][IN1],HIGH);
	DIO_WritePin(MotorPinsArray[motor][IN2],LOW);

}
