/*
 * main.c
 *
 *  Created on: Aug 31, 2023
 *      Author: eman adel
 */


#include "SERVICES/BIT_MATH.h"
#include "SERVICES/STD_TYPES.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000
#include "util/delay.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/KEYPAD_Interface.h"
#include "HAL/SENSOR/SENSOR_Inerface.h"
#include "MCAL/UART/UART.h"


int main(){
	DIO_Init();
	LCD_Init();
	FIRE_INIT();
	UART_Init();
	ADC_Init(VREF_VCC,ADC_SCALER_64);
	ADC_StartConversion(CH_0);
	DIO_WritePin(RELAY,LOW);
	while(1){

		FIRE_Runnable();
	}
	return 0;
}
