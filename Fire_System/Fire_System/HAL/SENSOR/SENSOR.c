/*
 * LM35.c
 *
 *  Created on: Sep 7, 2023
 *      Author: eman adel
 */
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include <avr/io.h>
#include "SENSOR_CFG.h"
#include "SENSOR_Inerface.h"


/******************* TEMP ***********************/

u16 Temp_Read(void)
{
	u16 volt = ADC_ReadVolt(LM35_CH); //0 -> 5000 mv

	u16 temp = volt;

	return temp;
}





